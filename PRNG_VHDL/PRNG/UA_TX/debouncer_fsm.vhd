library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

entity debouncer_fsm is
    Port ( -- inputs
			  clk : in  STD_LOGIC;
			  reset: in std_logic;
           x_in : in  STD_LOGIC;
			  count_in: in std_logic_vector (19 downto 0);
			  -- debug outputs
			  n_state_copy, p_state_copy: out debouncer_state_type;
			  -- output
			  enable : out std_logic;
           x_out : out  STD_LOGIC
			  );
end debouncer_fsm;

architecture Behavioral of debouncer_fsm is
	-- declare signals to display internal states
	signal p_state, n_state: debouncer_state_type;
	
begin
---------------------------------------------------------------------------------	
	ps_debouncer_update: PROCESS (clk, reset) is
	BEGIN
		IF reset = '1' THEN -- asynchronous reset
			p_state <= dbnce0;
		ELSIF rising_edge (clk) THEN
			p_state <= n_state; -- implied FF
		END IF;
	END PROCESS ps_debouncer_update;

	----------------------------------------------------------------------------------------						
	ns_debouncer_update: process (p_state, count_in, x_in) is
	begin
		case p_state is
		
				when dbnce0 =>  p_state_copy <= dbnce0;
						x_out <= '0';
						enable <= '0';
						if x_in = '0' then
							n_state <= dbnce0; n_state_copy <= dbnce0;
						elsif	x_in = '1'   then
							n_state <= dbnce1; n_state_copy <= dbnce1;
						else
							n_state <= dbnce0; n_state_copy <= dbnce0;
						end if; 	
	----------------------------------------------------------------------------------------						
				when dbnce1 =>  p_state_copy <= dbnce1;
						enable <= '1';
						if	((x_in = '1') and (count_in = std_logic_vector(delay_value)))   then
							n_state <= dbnce2; n_state_copy <= dbnce2;
							enable <= '0'; x_out <= '1';
						elsif ((x_in = '1') and (count_in < std_logic_vector(delay_value)))   then
							n_state <= dbnce1; n_state_copy <= dbnce1;
							enable <= '1'; x_out <= '0';
						else
							n_state <= dbnce0; n_state_copy <= dbnce0;
							enable <= '0'; x_out <= '0';
						end if; 	
----------------------------------------------------------------------------------------						
				when dbnce2 =>  p_state_copy <= dbnce2;
						enable <= '0'; x_out <= '0';
						if x_in = '1' then
							n_state <= dbnce2; n_state_copy <= dbnce2;
						else
							n_state <= dbnce0; n_state_copy <= dbnce0;
						end if;
	
	----------------------------------------------------------------------------------------						
				when others => 
						n_state <= dbnce0; n_state_copy <= dbnce0;
						enable <= '0';	
						x_out<= '0';			
				end CASE;
				
	end process ns_debouncer_update;
	
end Behavioral;