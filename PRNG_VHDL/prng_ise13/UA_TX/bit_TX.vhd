library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

-- We send a byte at a time
-- LSB is sent first
-- We have one start bit and one stop bit
-- There is a byte_in_valid bit value = 1

entity bit_Tx is 
    Port (	-- output
				byte_in : in  STD_LOGIC_VECTOR (7 downto 0);	
				byte_in_valid: in  STD_LOGIC;
				slow_clk_in : in  STD_LOGIC;
				reset : in std_logic;
				-- debug outputs
				--ns_bit_Tx, ps_bit_Tx: out bit_Tx_state_type;				
				-- outputs
				bit_out : out STD_LOGIC;
				bit_Tx_ready : out  STD_LOGIC
			);
end entity bit_Tx; 

architecture Behavioral of bit_Tx is

	signal p_state, n_state: bit_Tx_state_type;
begin
	
	process (slow_clk_in, reset) is begin
		if reset = '1' then
			p_state <= idle;
		elsif rising_edge(slow_clk_in) then
			p_state <= n_state;
		end if;
	end process; 
	
	process (p_state, byte_in_valid) is begin
		case p_state  is
			when idle => --ps_bit_Tx <= idle; 
				bit_Tx_ready <= '1'; bit_out<= '1';
				if byte_in_valid = '1' then
					n_state <= start_bit; --ns_bit_Tx <= start_bit;
				else
					n_state <= idle;  --ns_bit_Tx <= idle;
				end if;
			when start_bit => --ps_bit_Tx <= start_bit;
				bit_Tx_ready <= '0'; bit_out <= '0';
				n_state <= bit0;  --ns_bit_Tx <= bit0;
				 
			when bit0 =>  --ps_bit_Tx <= bit0; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(0);
				n_state <= bit1; --ns_bit_Tx <= bit1;
				
			when bit1 => --ps_bit_Tx <= bit1; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(1);
				n_state <= bit2; --ns_bit_Tx <= bit2;
				
			when bit2 => --ps_bit_Tx <= bit2; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(2);
				n_state <= bit3; --ns_bit_Tx <= bit3;
				
			when bit3 => --ps_bit_Tx <= bit3; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(3);
				n_state <= bit4; --ns_bit_Tx <= bit4;
				
			when bit4 => --ps_bit_Tx <= bit4; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(4);
				n_state <= bit5; --ns_bit_Tx <= bit5;
				
			when bit5 => --ps_bit_Tx <= bit5; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(5);
				n_state <= bit6; --ns_bit_Tx <= bit6;
				
			when bit6 => --ps_bit_Tx <= bit6; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(6);
				n_state <= bit7; --ns_bit_Tx <= bit7;
				
			when bit7 => --ps_bit_Tx <= bit7; 
				bit_Tx_ready <= '0'; bit_out <= byte_in(7);
				n_state <= stop_bit; --ns_bit_Tx <= stop_bit;
				
			when stop_bit => --ps_bit_Tx <= stop_bit; 
				bit_Tx_ready <= '0'; bit_out <= '1';
				n_state <= idle; --ns_bit_Tx <= idle;
				
			when others => --ps_bit_Tx <= stop_bit; 
				bit_Tx_ready <= '0'; bit_out <= '1';
				n_state <= idle; --ns_bit_Tx <= idle;
							
			
		end case;
	end process;
end Behavioral;
