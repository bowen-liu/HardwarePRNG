library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

entity word_TX is
    Port ( -- inputs
			  seed : in  STD_LOGIC_VECTOR (31 downto 0);
           s : in  STD_LOGIC_VECTOR (31 downto 0);
           prng_done : in  STD_LOGIC;
           byte_TX_ready : in  STD_LOGIC; -- byte_TX_ready  comes from serial interface. 
           clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           test_word_TX : in  STD_LOGIC; -- test word_TX
			  -- debug outputs
			  --ns_word_TX: out word_TX_state_type; ps_word_TX: out word_TX_state_type;			  
			  -- outputs 
			  word_TX_ready : out  STD_LOGIC; -- module is ready to accept new seed and s inputs
			  byte_out : out STD_LOGIC_VECTOR (7 downto 0);
			  byte_out_valid : out  STD_LOGIC; -- module has a byte send
			  is_ascii: out std_logic
           );
end word_TX;

architecture Behavioral of word_TX is
	
	-- declare signals to display internal states
	signal p_state, n_state: word_TX_state_type;
	-- declare signals for final prng results 
	signal seed_data, s_data : std_logic_vector (31 downto 0);

begin

---------------------------------------------------------------------------------	
	ps_word_TX_update: PROCESS (clk, reset)
	BEGIN
		IF reset = '1' THEN -- asynchronous reset
			p_state <= idle; 
		ELSIF rising_edge (clk) THEN
			p_state <= n_state; -- implied FF	
		END IF;
	END PROCESS ps_word_TX_update;
	
----------------------------------------------------------------------------------
	capture: process (clk, prng_done) is begin
		if ((rising_edge(clk)) and (prng_done = '1')) then -- caputre valid input data
					seed_data <= seed; s_data <= s; 
					--seed_data <= x"0A0B0C0D"; s_data <= x"01020304";
		end if;
	end process capture;
	
------------------------------------------------------------------------------------
	ns_word_TX_update: PROCESS (test_word_TX, prng_done, p_state, byte_TX_ready ) is
	BEGIN
				CASE p_state IS 

				when idle =>  --ps_word_TX <= idle; 
						if byte_TX_ready = '1' then
							word_TX_ready <= '1';
						else
							word_TX_ready <= '0';
						end if;
						byte_out<= X"00";
						is_ascii <= '1';
						if test_word_TX = '1' then -- test mode
							n_state <= Tw0sw; --ns_word_TX <= Tw0sw; -- Test Word_TX # State  Wait  (tw0sw) 
							byte_out_valid <= '1';
						elsif prng_done = '1' then -- data is available from PRNG
							n_state <= ch_s0w; --ns_word_TX <= ch_s0w; 
							byte_out_valid <= '1';
						else  -- not test and PRNG is not done 
							n_state <= idle; --ns_word_TX <= idle; 
							byte_out_valid <= '0';
						end if; -- if test
-------------------------------------------------------------------------------------
-- seed states (s0=s0)					
----------------------------------------------------------------------------------------						
				when ch_s0w => --ps_word_TX <= ch_s0w; -- wait till byte_TX accepts data (ready=0). Move to next state then.
						word_TX_ready <= '0';
						byte_out <= X"73"; -- ASCII for s
						byte_out_valid <= '1'; is_ascii <= '1';
						if byte_TX_ready  = '1' then -- byte_TX did not accept data, stay in same state.
							n_state <= ch_s0w; --ns_word_TX <= ch_s0w;
						else -- byte_TX just accepted data, go to next state.
							n_state <= ch_s0; --ns_word_TX <= ch_s0;	
						end if; 					
				when ch_s0 => --ps_word_TX <= ch_s0; -- byte_TX now tramsmitting the data. Move to next state when byte_TX ready.
						word_TX_ready <= '0';
						byte_out <= X"73"; -- ASCII for s 
						byte_out_valid <= '0';	is_ascii <= '1'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '0' then  -- byte_TX just accepted data, stay in same state.
							n_state <= ch_s0; --ns_word_TX <= ch_s0;
						else  -- byte_TX ready for next data, go to next state.
							n_state <= ch_0w; --ns_word_TX <= ch_0w;	
						end if;						
				when ch_0w => --ps_word_TX <= ch_0w;  -- wait till byte_TX accepts data and becomes not ready.
						word_TX_ready <= '0';
						byte_out <= X"30"; -- ASCII for 0
						byte_out_valid <= '1';	is_ascii <= '1'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '1' then -- byte_TX did not accept data, stay in same state.
							n_state <= ch_0w;--ns_word_TX <= ch_0w;
						else -- byte_TX just accepted data and is now busy transmitting
							n_state <= ch_0;--ns_word_TX <= ch_0;	
						end if;
				
				when ch_0 => --ps_word_TX <= ch_0;  -- wait till byte_TX accepts data and becomes not ready.
						word_TX_ready <= '0';
						byte_out <= X"30"; -- ASCII for 0
						byte_out_valid <= '0';	is_ascii <= '1'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '0' then 
							n_state <= ch_0;--ns_word_TX <= ch_0;
						else 
							n_state <= ch_s0eqw;--ns_word_TX <= ch_s0eqw;	
						end if;
				
				when ch_s0eqw => --ps_word_TX <= ch_s0eqw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
						byte_out <= X"3D"; -- ASCII for =
						byte_out_valid <= '1';	is_ascii <= '1';
						if byte_TX_ready  = '1' then 
							n_state <= ch_s0eqw;--ns_word_TX <= ch_s0eqw;
						else -- byte_TX just accepted data and is now busy transmitting
							n_state <= ch_s0eq;--ns_word_TX <= ch_s0eq;	
						end if; 
						
				when ch_s0eq => --ps_word_TX <= ch_s0eq;  -- wait till byte_TX accepts data and becomes not ready.
						word_TX_ready <= '0';
						byte_out <= X"3D"; -- ASCII for =
						byte_out_valid <= '0'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '0' then 
							n_state <= ch_s0eq;--ns_word_TX <= ch_s0eq;
							is_ascii <= '1';
						else 
							n_state <= sends03w;--ns_word_TX <= sends03w;
							is_ascii <= '0';
						end if;						
						
             when sends03w => --ps_word_TX <= sends03w;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= seed_data(31 downto 24); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then -- byte_TX did not accept data to start transmit yet.
                        n_state <= sends03w;--ns_word_TX <= sends03w;
                    else 
                         n_state <= sends03;--ns_word_TX <= sends03;
						  end if; 
             when sends03 => --ps_word_TX <= sends03; -- byte_TX now tramsmitting the data 
						  word_TX_ready <= '0';
                    byte_out<= seed_data(31 downto 24);
                    byte_out_valid <= '0'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends03;--ns_word_TX <= sends03;
                    else
                         n_state <= sends02w;--ns_word_TX <= sends02w;
						  end if;  
             when sends02w => --ps_word_TX <= sends02w;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= seed_data(23 downto 16); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends02w;--ns_word_TX <= sends02w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends02;--ns_word_TX <= sends02;
						  end if; 
             when sends02 => --ps_word_TX <= sends02; -- byte_TX now tramsmitting the data 
						  word_TX_ready <= '0';
                    byte_out<= seed_data(23 downto 16);
                    byte_out_valid <= '0'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then
                        n_state <= sends02;--ns_word_TX <= sends02;
                    else
                         n_state <= sends01w;--ns_word_TX <= sends01w;
						  end if;   
             when sends01w => --ps_word_TX <= sends01w;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= seed_data(15 downto 8); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends01w;--ns_word_TX <= sends01w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends01;--ns_word_TX <= sends01;
						  end if; 
             when sends01 => --ps_word_TX <= sends01; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= seed_data(15 downto 8);
                    byte_out_valid <= '0'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends01;--ns_word_TX <= sends01;
                    else
                         n_state <= sends00w;--ns_word_TX <= sends00w;
						  end if; 
						  
             when sends00w => --ps_word_TX <= sends00w; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= seed_data(7 downto 0); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends00w;--ns_word_TX <= sends00w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends00;--ns_word_TX <= sends00;
						  end if; 
             when sends00 => --ps_word_TX <= sends00; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= seed_data(7 downto 0);
                    byte_out_valid <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends00;--ns_word_TX <= sends00;
								 is_ascii <= '0';
                    else
                         n_state <= ch_s0crw;--ns_word_TX <= ch_s0crw;
								  is_ascii <= '1';
						  end if;  
						  
				when ch_s0crw => --ps_word_TX <= ch_s0crw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= ch_s0crw;--ns_word_TX <= ch_s0crw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= ch_s0cr;--ns_word_TX <= ch_s0cr;
						  end if; 
             when ch_s0cr => --ps_word_TX <= ch_s0cr; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '0'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= ch_s0cr;--ns_word_TX <= ch_s0cr;
                    else
                         n_state <= ch_s0lfw;--ns_word_TX <= ch_s0lfw;
						  end if;            
				when ch_s0lfw => --ps_word_TX <= ch_s0lfw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF 
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= ch_s0lfw;--ns_word_TX <= ch_s0lfw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= ch_s0lf;--ns_word_TX <= ch_s0lf;
						  end if; 
						  
             when ch_s0lf => --ps_word_TX <= ch_s0lf; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF
                    byte_out_valid <= '0'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= ch_s0lf;--ns_word_TX <= ch_s0lf;
                    else
                         n_state <= ch_s1w;--ns_word_TX <= ch_s1w;
						  end if;

-------------------------------------------------------------------------------------
-- s (random number) states						
----------------------------------------------------------------------------------------						
				when ch_s1w => --ps_word_TX <= ch_s1w; -- wait till byte_TX accepts data and becomes not ready.
						word_TX_ready <= '0';
						byte_out <= X"73"; -- ASCII for s
						byte_out_valid <= '1'; is_ascii <= '1';
						if byte_TX_ready  = '1' then 
							n_state <= ch_s1w; --ns_word_TX <= ch_s1w;
						else
							n_state <= ch_s1; --ns_word_TX <= ch_s1;	
						end if; 					
				when ch_s1 => --ps_word_TX <= ch_s1; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
						byte_out <= X"73"; -- ASCII for Y 
						byte_out_valid <= '1';	is_ascii <= '1';
						if byte_TX_ready  = '0' then  -- byte_TX just accepted data and is now busy transmitting
							n_state <= ch_s1; --ns_word_TX <= ch_s1;
						else -- ascii indicated it is sending the data
							n_state <= ch_s1eqw; --ns_word_TX <= ch_s1eqw;	
						end if;						
				when ch_s1eqw => --ps_word_TX <= ch_s1eqw; -- wait till byte_TX accepts data and becomes not ready.
						word_TX_ready <= '0';
						byte_out <= X"3D"; -- ASCII for =
						byte_out_valid <= '1';	is_ascii <= '1';
						if byte_TX_ready  = '1' then 
							n_state <= ch_s1eqw;--ns_word_TX <= ch_s1eqw;
						else -- byte_TX just accepted data and is now busy transmitting
							n_state <= ch_s1eq;--ns_word_TX <= ch_s1eq;	
						end if; 						
				when ch_s1eq => --ps_word_TX <= ch_s1eq; -- byte_TX now tramsmitting the data
						word_TX_ready <= '0';
						byte_out <= X"3D"; -- ASCII for = 
						byte_out_valid <= '1';
						if byte_TX_ready  = '0' then  -- byte_TX just accepted data and is now busy transmitting
							n_state <= ch_s1eq;--ns_word_TX <= ch_s1eq;
							is_ascii <= '1';
						else
							n_state <= sends13w;--ns_word_TX <= sends13w;	 -- wait till byte_TX accepts data and becomes not ready.
							is_ascii <= '0';
						end if; 
             when sends13w => --ps_word_TX <= sends13w; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= s_data(31 downto 24); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends13w;--ns_word_TX <= sends13w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends13;--ns_word_TX <= sends13;
						  end if; 
             when sends13 => --ps_word_TX <= sends13; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= s_data(31 downto 24);
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends13;--ns_word_TX <= sends13;
                    else
                         n_state <= sends12w;--ns_word_TX <= sends12w;
						  end if;  
             when sends12w => --ps_word_TX <= sends12w; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= s_data(23 downto 16); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends12w;--ns_word_TX <= sends12w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends12;--ns_word_TX <= sends12;
						  end if; 
             when sends12 => --ps_word_TX <= sends12; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= s_data(23 downto 16);
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends12;--ns_word_TX <= sends12;
                    else
                         n_state <= sends11w;--ns_word_TX <= sends11w;
						  end if;   
             when sends11w => --ps_word_TX <= sends11w; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= s_data(15 downto 8); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends11w;--ns_word_TX <= sends11w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends11;--ns_word_TX <= sends11;
						  end if; 
             when sends11 => --ps_word_TX <= sends11; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= s_data(15 downto 8);
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends11;--ns_word_TX <= sends11;
                    else
                         n_state <= sends10w;--ns_word_TX <= sends10w;
						  end if;   
             when sends10w => --ps_word_TX <= sends10w; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= s_data(7 downto 0); 
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= sends10w;--ns_word_TX <= sends10w;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= sends10;--ns_word_TX <= sends10;
						  end if; 
             when sends10 => --ps_word_TX <= sends10; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= s_data(7 downto 0);
                    byte_out_valid <= '1'; 
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= sends10;--ns_word_TX <= sends10;
								is_ascii <= '0';
                    else
                         n_state <= ch_s1crw;--ns_word_TX <= ch_s1crw;
								 is_ascii <= '1';
						  end if;            
				when ch_s1crw => --ps_word_TX <= ch_s1crw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= ch_s1crw;--ns_word_TX <= ch_s1crw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= ch_s1cr;--ns_word_TX <= ch_s1cr;
						  end if; 
             when ch_s1cr => --ps_word_TX <= ch_s1cr; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0D"; -- ASCII for CR
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= ch_s1cr;--ns_word_TX <= ch_s1cr;
                    else
                         n_state <= ch_s1lfw;--ns_word_TX <= ch_s1lfw;
						  end if;            
				when ch_s1lfw => --ps_word_TX <= ch_s1lfw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF 
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= ch_s1lfw;--ns_word_TX <= ch_s1lfw;
                    else 
                         n_state <= ch_s1lf;--ns_word_TX <= ch_s1lf;
						  end if; 
             when ch_s1lf => --ps_word_TX <= ch_s1lf; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0A"; -- ASCII for LF
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then
                        n_state <= ch_s1lf;--ns_word_TX <= ch_s1lf;
                    else
								if prng_done = '1' then
									n_state <= ch_s1lf; --ns_word_TX <= ch_s1lf;
								else
									n_state <= idle; --ns_word_TX <= idle;
								end if;
						  end if;
 					
-------------------------------------------------------------------------------------
-- Test states	display message: "wordTX OK"				
----------------------------------------------------------------------------------------						

				when Tw0sw => --ps_word_TX <= Tw0sw; -- wait till byte_TX accepts data (ready=0). Move to next state then.
						word_TX_ready <= '0';
						byte_out <= X"77"; -- ASCII for w
						byte_out_valid <= '1'; is_ascii <= '1';
						if byte_TX_ready  = '1' then -- byte_TX did not accept data, stay in same state.
							n_state <= Tw0sw; --ns_word_TX <= Tw0sw;
						else -- byte_TX just accepted data, go to next state.
							n_state <= Tw0s; --ns_word_TX <= Tw0s;	
						end if; 					
				when Tw0s => --ps_word_TX <= Tw0s; -- byte_TX now tramsmitting the data. Move to next state when byte_TX ready.
						word_TX_ready <= '0';
						byte_out <= X"77"; -- ASCII for w 
						byte_out_valid <= '1';	is_ascii <= '1'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '0' then  -- byte_TX just accepted data, stay in same state.
							n_state <= Tw0s; --ns_word_TX <= Tw0s;
						else  -- byte_TX ready for next data, go to next state.
							n_state <= Tw1sw; --ns_word_TX <= Tw1sw;	
						end if;
				when Tw1sw => --ps_word_TX <= Tw1sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
						byte_out <= X"6F"; -- ASCII for o
						byte_out_valid <= '1';	is_ascii <= '1';
						if byte_TX_ready  = '1' then 
							n_state <= Tw1sw; --ns_word_TX <= Tw1sw;
						else -- byte_TX just accepted data and is now busy transmitting
							n_state <= Tw1s; --ns_word_TX <= Tw1s;	
						end if;
				when Tw1s => --ps_word_TX <= Tw1s; -- byte_TX now tramsmitting the data. Move to next state when byte_TX ready.
						word_TX_ready <= '0';
						byte_out <= X"6F"; -- ASCII for o 
						byte_out_valid <= '1';	is_ascii <= '1'; -- byte_TX did not accept data to start transmit yet.
						if byte_TX_ready  = '0' then  -- byte_TX just accepted data, stay in same state.
							n_state <= Tw1s; --ns_word_TX <= Tw1s;
						else  -- byte_TX ready for next data, go to next state.
							n_state <= Tw2sw; --ns_word_TX <= Tw2sw;	
						end if;
             when Tw2sw => --ps_word_TX <= Tw2sw;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"72";  -- r
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then -- byte_TX did not accept data to start transmit yet.
                        n_state <= Tw2sw; --ns_word_TX <= Tw2sw;
                    else 
                         n_state <= Tw2s;--ns_word_TX <= Tw2s;
						  end if; 
             when Tw2s => --ps_word_TX <= Tw2s; -- byte_TX now tramsmitting the data 
						  word_TX_ready <= '0';
                    byte_out<= X"72";  -- r
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw2s; --ns_word_TX <= Tw2s;
                    else
                         n_state <= Tw3sw; --ns_word_TX <= Tw3sw;
						  end if;  
             when Tw3sw => --ps_word_TX <= Tw3sw;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"64"; -- d
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw3sw;--ns_word_TX <= Tw3sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw3s; --ns_word_TX <= Tw3s;
						  end if; 
             when Tw3s => --ps_word_TX <= Tw3s; -- byte_TX now tramsmitting the data 
						  word_TX_ready <= '0';
                    byte_out<= X"64"; -- d
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then
                        n_state <= Tw3s; --ns_word_TX <= Tw3s;
                    else
                         n_state <= Tw4sw; --ns_word_TX <= Tw4sw;
						  end if;   
             when Tw4sw => --ps_word_TX <= Tw4sw;  -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<= X"54"; -- T 
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw4sw;--ns_word_TX <= Tw4sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw4s;--ns_word_TX <= Tw4s;
						  end if; 
             when Tw4s => --ps_word_TX <= Tw4s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"54"; -- T
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw4s;--ns_word_TX <= Tw4s;
                    else
                         n_state <= Tw5sw; --ns_word_TX <= Tw5sw;
						  end if;   
             when Tw5sw => --ps_word_TX <= Tw5sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"58"; -- X 
                    byte_out_valid <= '1'; is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw5sw; --ns_word_TX <= Tw5sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw5s; --ns_word_TX <= Tw5s;
						  end if; 
             when Tw5s => --ps_word_TX <= Tw5s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"58"; -- X
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw5s; --ns_word_TX <= Tw5s;
                    else
                         n_state <= Tw6sw; --ns_word_TX <= Tw6sw;
						  end if; 
						  
	           when Tw6sw => --ps_word_TX <= Tw6sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"20"; -- SPACE
                    byte_out_valid <= '1'; is_ascii <= '0';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw6sw; --ns_word_TX <= Tw6sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw6s; --ns_word_TX <= Tw6s;
						  end if; 
             when Tw6s => --ps_word_TX <= Tw6s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"20"; -- SPACE
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw6s; --ns_word_TX <= Tw6s;
                    else
                         n_state <= Tw7sw; --ns_word_TX <= Tw7sw;
						  end if; 
						  
             when Tw7sw => --ps_word_TX <= Tw7sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"4F"; -- O 
                    byte_out_valid <= '1'; 
						  is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw7sw; --ns_word_TX <= Tw7sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw7s; --ns_word_TX <= Tw7s;
						  end if; 
						  
             when Tw7s => --ps_word_TX <= Tw7s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"4F"; -- O 
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw7s; --ns_word_TX <= Tw7s;
                    else
                         n_state <= Tw8sw; --ns_word_TX <= Tw8sw;
						  end if; 
						  
             when Tw8sw => --ps_word_TX <= Tw8sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"4B"; -- K 
                    byte_out_valid <= '1'; 
						  is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw8sw; --ns_word_TX <= Tw8sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw8s; --ns_word_TX <= Tw8s;
						  end if; 
						  
             when Tw8s => --ps_word_TX <= Tw8s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"4B"; -- K
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw8s; --ns_word_TX <= Tw8s;
                    else
                         n_state <= Tw9sw; --ns_word_TX <= Tw9sw;
						  end if;
						  
             when Tw9sw => --ps_word_TX <= Tw9sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"0D"; -- CR 
                    byte_out_valid <= '1'; 
						  is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw9sw; --ns_word_TX <= Tw9sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw9s; --ns_word_TX <= Tw9s;
						  end if; 
						  
             when Tw9s => --ps_word_TX <= Tw9s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0D"; -- CR
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw9s; --ns_word_TX <= Tw9s;
                    else
                         n_state <= Tw10sw; --ns_word_TX <= Tw10sw;
						  end if; 
						  
             when Tw10sw => --ps_word_TX <= Tw10sw; -- wait till byte_TX accepts data and becomes not ready.
						  word_TX_ready <= '0';
                    byte_out<=  X"0A"; -- LF 
                    byte_out_valid <= '1'; 
						  is_ascii <= '1';
                    if byte_TX_ready  = '1' then
                        n_state <= Tw10sw; --ns_word_TX <= Tw10sw;
                    else  -- byte_TX just accepted data and is now busy transmitting
                         n_state <= Tw10s; --ns_word_TX <= Tw10s;
						  end if; 
             when Tw10s => --ps_word_TX <= Tw10s; -- byte_TX now tramsmitting the data
						  word_TX_ready <= '0';
                    byte_out<= X"0A"; -- LF
                    byte_out_valid <= '1';
						  is_ascii <= '1';
                    if byte_TX_ready  = '0' then -- byte_TX just accepted data and is now busy transmitting
                        n_state <= Tw10s; --ns_word_TX <= Tw10s;
                    else
								if prng_done = '1' then
									n_state <= Tw10s; --ns_word_TX <= Tw10s;
								else
									n_state <= idle; --ns_word_TX <= idle;
								end if;
						  end if; 
								
----------------------------------------------------------------------------------------						
				when others => 
						 
						if byte_TX_ready = '1' then
							word_TX_ready <= '1';
						else
							word_TX_ready <= '0';
						end if;
						byte_out<= (others => '0');
						byte_out_valid <= '0'; is_ascii <= '0';
						n_state <= idle; --ns_word_TX <= idle;
				end CASE;

				
	end process ns_word_TX_update;
	----------------------------------------------------------------------------------
end architecture Behavioral;
