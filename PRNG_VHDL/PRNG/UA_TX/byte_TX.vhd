library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

-- This translates an input byte and sends it to bit_TX.
entity byte_TX is -- ASCII
	port (-- inputs
			byte_in : in std_logic_vector (7 downto 0);
			byte_in_valid : in std_logic;
			is_ascii : in std_logic;
			bit_TX_ready : in std_logic;
			test_byte_TX: in std_logic; -- test byte_TX
			clk : in std_logic;
			reset : in std_logic;
			-- debug outputs
--			ns_byte_TX, ps_byte_TX : out byte_TX_state_type;
			-- outputs
			byte_out : out std_logic_vector (7 downto 0);
			byte_out_valid : out std_logic;
			byte_TX_ready : out std_logic
			);
end entity byte_TX;

architecture Behavioral of byte_TX is
	-- procedure to translate a hex to equivalent ASCII
	procedure hex_2_ascii (
		signal nibble: in std_logic_vector (3 downto 0);
		signal byte : out std_logic_vector (7 downto 0))  is
	begin
		case nibble is
			when X"0" =>  byte <= X"30";  
			when X"1" =>  byte <= X"31";
			when X"2" =>  byte <= X"32";
			when X"3" =>  byte <= X"33";
			when X"4" =>  byte <= X"34";
			when X"5" =>  byte <= X"35";
			when X"6" =>  byte <= X"36";
			when X"7" =>  byte <= X"37";
			when X"8" =>  byte <= X"38";
			when X"9" =>  byte <= X"39";
			when X"A" =>  byte <= X"41";
			when X"B" =>  byte <= X"42";
			when X"C" =>  byte <= X"43";
			when X"D" =>  byte <= X"44";
			when X"E" =>  byte <= X"45";
			when X"F" =>  byte <= X"46";
			when others =>byte <= X"3F"; -- ?
		end case;
	end procedure hex_2_ascii;
	
	signal p_state, n_state: byte_TX_state_type;
	signal byte : std_logic_vector(7 downto 0);

begin

	---------------------------------------------------------------------------------	
	ps_update: PROCESS (clk, reset)
	BEGIN
		IF reset = '1' THEN -- asynchronous reset
			p_state <= idle; 
		ELSIF rising_edge (clk) THEN
			p_state <= n_state; -- implied FF	
		END IF;
	END PROCESS ps_update;
	
------------------------------------------------------------------------------------
	capture: process (clk,byte_in_valid) is begin
		if ((rising_edge(clk)) and (byte_in_valid = '1')) then -- caputre valid input data
					byte <= byte_in; 
		end if;
	end process capture;
	
------------------------------------------------------------------------------------
	ns_update: PROCESS (test_byte_TX, byte_in_valid, byte_in, is_ascii, p_state, bit_TX_ready) is
	BEGIN
				CASE p_state IS 

				when idle => --ps_byte_TX<= idle;  
						byte_out<= X"00"; byte_out_valid <= '0'; 
						byte_TX_ready <= '1';
--						if bit_TX_ready = '1' then
--							byte_TX_ready <= '1';
--						else
--							byte_TX_ready <= '0';
--						end if;
						if test_byte_TX = '1' then
							n_state <= Tb0sw; --ns_byte_TX<= Tb0sw;
						elsif ((byte_in_valid = '1') and (is_ascii = '1')) then 
							n_state <= byte_asciiw; --ns_byte_TX<= byte_asciiw;
						elsif ((byte_in_valid = '1') and (is_ascii = '0')) then 
							n_state <= nibble0w; --ns_byte_TX<= nibble0w;
						else
							n_state <= idle; --ns_byte_TX<= idle;
						end if; 
-------------------------------------------------------------------------------------
-- ASCII states			
----------------------------------------------------------------------------------------						
				when byte_asciiw => --ps_byte_TX<= byte_asciiw;
						byte_out <= byte; -- copy input data to output
						byte_out_valid <= '1'; byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= byte_asciiw; --ns_byte_TX<= byte_asciiw;
						else
							n_state <= byte_ascii; --ns_byte_TX<= byte_ascii;	
						end if; 
						
				when byte_ascii => --ps_byte_TX<= byte_ascii;
						byte_out <= byte;  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= byte_ascii; --ns_byte_TX<= byte_ascii;
						else 
							n_state <= idle; --ns_byte_TX<= idle;	
						end if;
						
-------------------------------------------------------------------------------------
-- Non-ASCII states					
----------------------------------------------------------------------------------------						
				when nibble0w => --ps_byte_TX<= nibble0w;
						hex_2_ascii (byte (7 downto 4), byte_out); 
						byte_out_valid <= '1'; byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= nibble0w; --ns_byte_TX<= nibble0w;
						else
							n_state <= nibble0; --ns_byte_TX<= nibble0;	
						end if; 
						
				when nibble0 => --ps_byte_TX<= nibble0;
						hex_2_ascii (byte (7 downto 4), byte_out);  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= nibble0; --ns_byte_TX<= nibble0;
						else 
							n_state <= nibble1w; --ns_byte_TX<= nibble1w;	
						end if;
						
				when nibble1w => --ps_byte_TX<= nibble1w;
						hex_2_ascii (byte (3 downto 0), byte_out); 
						byte_out_valid <= '1'; byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= nibble1w; --ns_byte_TX<= nibble1w;
						else
							n_state <= nibble1; --ns_byte_TX<= nibble1;	
						end if;
						
				when nibble1 => --ps_byte_TX<= nibble1;
						hex_2_ascii (byte (3 downto 0), byte_out);  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= nibble1; --ns_byte_TX<= nibble1;
						else 
							n_state <= idle; --ns_byte_TX<= idle;	
						end if;	
						
-------------------------------------------------------------------------------------
-- Test states	display message: "byteTX OK"				
----------------------------------------------------------------------------------------						
				when Tb0sw => --ps_byte_TX<= Tb0sw;
						byte_out <= x"62"; -- b
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb0sw; --ns_byte_TX<= Tb0sw;
						else 
							n_state <= Tb0s; --ns_byte_TX<= Tb0s;	
						end if;
						
				when Tb0s => --ps_byte_TX<= Tb0s;
						byte_out <= x"62"; -- b  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb0s; --ns_byte_TX<= Tb0s;
						else 
							n_state <= Tb1sw; --ns_byte_TX<= Tb1sw;	
						end if;		
						
				when Tb1sw => --ps_byte_TX<= Tb1sw;
						byte_out <= x"79"; -- y
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb1sw; --ns_byte_TX<= Tb1sw;
						else 
							n_state <= Tb1s; --ns_byte_TX<= Tb1s;	
						end if;
						
				when Tb1s => --ps_byte_TX<= Tb1s;
						byte_out <= x"79"; -- y  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb1s; --ns_byte_TX<= Tb1s;
						else 
							n_state <= Tb2sw; --ns_byte_TX<= Tb2sw;	
						end if;		
						
				when Tb2sw => --ps_byte_TX<= Tb2sw;
						byte_out <= x"74"; -- t
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb2sw; --ns_byte_TX<= Tb2sw;
						else 
							n_state <= Tb2s; --ns_byte_TX<= Tb2s;	
						end if;
						
				when Tb2s => --ps_byte_TX<= Tb2s;
						byte_out <= x"74"; -- t  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb2s; --ns_byte_TX<= Tb2s;
						else 
							n_state <= Tb3sw; --ns_byte_TX<= Tb3sw;	
						end if;		
						
				when Tb3sw => --ps_byte_TX<= Tb3sw;
						byte_out <= x"65"; -- e
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb3sw; --ns_byte_TX<= Tb3sw;
						else 
							n_state <= Tb3s; --ns_byte_TX<= Tb3s;	
						end if;
						
				when Tb3s => --ps_byte_TX<= Tb3s;
						byte_out <= x"65"; -- e  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb3s; --ns_byte_TX<= Tb3s;
						else 
							n_state <= Tb4sw; --ns_byte_TX<= Tb4sw;	
						end if;		
						
				when Tb4sw => --ps_byte_TX<= Tb4sw;
						byte_out <= x"54"; -- T
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb4sw; --ns_byte_TX<= Tb4sw;
						else 
							n_state <= Tb4s; --ns_byte_TX<= Tb4s;	
						end if;
						
				when Tb4s => --ps_byte_TX<= Tb4s;
						byte_out <= x"54"; -- T  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb4s; --ns_byte_TX<= Tb4s;
						else 
							n_state <= Tb5sw; --ns_byte_TX<= Tb5sw;	
						end if;		
						
				when Tb5sw => --ps_byte_TX<= Tb5sw;
						byte_out <= x"58"; -- X 
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb5sw; --ns_byte_TX<= Tb5sw;
						else 
							n_state <= Tb5s; --ns_byte_TX<= Tb5s;	
						end if;
						
				when Tb5s => --ps_byte_TX<= Tb5s;
						byte_out <= x"58"; -- X  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb5s; --ns_byte_TX<= Tb5s;
						else 
							n_state <= Tb6sw; --ns_byte_TX<= Tb6sw;	
						end if;		
						
				when Tb6sw => --ps_byte_TX<= Tb6sw;
						byte_out <= x"20"; -- " ' space 
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb6sw; --ns_byte_TX<= Tb6sw;
						else 
							n_state <= Tb6s; --ns_byte_TX<= Tb6s;	
						end if;
						
				when Tb6s => --ps_byte_TX<= Tb6s;
						byte_out <= x"20"; -- " ' space  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb6s; --ns_byte_TX<= Tb6s;
						else 
							n_state <= Tb7sw; --ns_byte_TX<= Tb7sw;	
						end if;		
						
				when Tb7sw => --ps_byte_TX<= Tb7sw;
						byte_out <= x"4F"; -- O
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb7sw; --ns_byte_TX<= Tb7sw;
						else 
							n_state <= Tb7s; --ns_byte_TX<= Tb7s;	
						end if;
						
				when Tb7s => --ps_byte_TX<= Tb7s;
						byte_out <= x"4F"; -- O  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb7s; --ns_byte_TX<= Tb7s;
						else 
							n_state <= Tb8sw; --ns_byte_TX<= Tb8sw;	
						end if;		
						
				when Tb8sw => --ps_byte_TX<= Tb8sw;
						byte_out <= x"4B"; -- K 
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '1' then 
							n_state <= Tb8sw; --ns_byte_TX<= Tb8sw;
						else 
							n_state <= Tb8s; --ns_byte_TX<= Tb8s;	
						end if;
						
				when Tb8s => --ps_byte_TX<= Tb8s;
						byte_out <= x"4B"; -- K  
						byte_out_valid <= '1';	byte_TX_ready <= '0';
						if bit_TX_ready = '0' then 
							n_state <= Tb8s; --ns_byte_TX<= Tb8s;
						else 
							n_state <= Tb9sw; --ns_byte_TX<= Tb9sw;	
						end if;	
						
				when Tb9sw => --ps_byte_TX <= Tb9sw; -- wait till byte_TX accepts data and becomes not ready.
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '1';
                    if bit_TX_ready  = '1' then
                        n_state <= Tb9sw; --ns_byte_TX <= Tb9sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tb9s; --ns_byte_TX <= Tb9s;
						  end if;
						  
             when Tb9s => --ps_byte_TX <= Tb9s; -- byte_TX now tramsmitting the data
						  byte_TX_ready <= '0';
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '1'; 
                    if bit_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tb9s; --ns_byte_TX <= Tb9s;
                    else
                         n_state <= Tb10sw; --ns_byte_TX <= Tb10sw;
						  end if;
						  
				when Tb10sw => --ps_byte_TX <= Tb10sw; -- wait till byte_TX accepts data and becomes not ready.
						  byte_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF 
                    byte_out_valid <= '1';
                    if bit_TX_ready  = '1' then
                        n_state <= Tb10sw; --ns_byte_TX <= Tb10sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tb10s; --ns_byte_TX <= Tb10s;
						  end if;
						  
             when Tb10s => --ps_byte_TX <= Tb10s; -- byte_TX now tramsmitting the data
						  byte_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF
                    byte_out_valid <= '1';
                    if bit_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tb10s; --ns_byte_TX <= Tb10s;
                    else
								n_state <= idle; --ns_byte_TX <= idle;
						end if;
						
             when OTHERS => --ps_byte_TX <= Tb10s; -- byte_TX now tramsmitting the data
						if bit_TX_ready = '1' then
							byte_TX_ready <= '1';
						else
							byte_TX_ready <= '0';
						end if;
                    byte_out<= X"00"; 
                    byte_out_valid <= '0';
                    n_state <= idle; --ns_byte_TX <= idle;
										
				end case;
		end process ns_update;
end architecture Behavioral;
