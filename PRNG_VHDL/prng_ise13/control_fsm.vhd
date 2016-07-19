library IEEE;
library work;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.PRNG_CONST.ALL;

library work;
use work.PRNG_CONST.ALL;

entity control_fsm is

    generic(width : integer := 32);
    Port ( seed_sel : in  STD_LOGIC_VECTOR (1 downto 0);
           UA_TX_ready : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           start : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           s : out  STD_LOGIC_VECTOR (width-1 downto 0);
           seed : out  STD_LOGIC_VECTOR (width-1 downto 0);
           prng_done : out  STD_LOGIC;
           prng_busy : out  STD_LOGIC);
			  
end control_fsm;

architecture Behavioral of control_fsm is

	--Other VHDL componments needed for the overall FSM
	component divider is
	port ( Y : in  STD_LOGIC_VECTOR (width-1 downto 0);
          X : in  STD_LOGIC_VECTOR (width-1 downto 0);
          R : out  STD_LOGIC_VECTOR (width-1 downto 0);
          Q : out  STD_LOGIC_VECTOR (width-1 downto 0);
          clk : in  STD_LOGIC;
          rst : in  STD_LOGIC;
          start : in  STD_LOGIC;
          output_ready : out  STD_LOGIC);
	end component;
	
	component multiplication_stage is
    Port ( Y : in  STD_LOGIC_VECTOR (width-1 downto 0);
           Z : in  STD_LOGIC_VECTOR (width-1 downto 0);
           output : out  STD_LOGIC_VECTOR (width-1 downto 0));
	end component;
	
	--Divider register declarations
	signal s0 : STD_LOGIC_VECTOR (width-1 downto 0);
	signal Y_out, Z_out : STD_LOGIC_VECTOR (width-1 downto 0);
	signal div_start, div_complete : STD_LOGIC;
	
	--Multiplication stage register declarations
	signal mul_out : STD_LOGIC_VECTOR (width-1 downto 0);
	
	--FSM state tracker
	signal fsm_stage : Integer;

begin
	
	--Instantiating the datapath divider 
	DIV : divider PORT MAP (
		Y => s0, 
		X => STD_LOGIC_VECTOR(to_signed(CONST_Q, width)), 
		R => Y_out, 
		Q => Z_out, 
		clk => clk,
		rst => reset,
		start => div_start,
		output_ready => div_complete);
	
	--Instantiating the datapath multiplier and subtractor 
	MUL : multiplication_stage PORT MAP (
		Y => Y_out,							
		Z => Z_out,
		output => mul_out);
		
		
	--Sets the initial seed and seed value for every iterations (s0)
	process(clk, reset)
	begin
	
		--When reset is asynchronously asserted, load the select initial seed into s0.
		if(reset = '1') then
			case seed_sel is
				when "00" => 
					s0 <= STD_LOGIC_VECTOR(to_signed(SEED_0, width));
					seed <= STD_LOGIC_VECTOR(to_signed(SEED_0, width));
				when "01" => 
					s0 <= STD_LOGIC_VECTOR(to_signed(SEED_1, width));
					seed <= STD_LOGIC_VECTOR(to_signed(SEED_1, width));
				when "10" => 
					s0 <= STD_LOGIC_VECTOR(to_signed(SEED_2, width));
					seed <= STD_LOGIC_VECTOR(to_signed(SEED_2, width));
				when "11" => 
					s0 <= STD_LOGIC_VECTOR(to_signed(SEED_3, width));
					seed <= STD_LOGIC_VECTOR(to_signed(SEED_3, width));
				when others => 
					s0 <= STD_LOGIC_VECTOR(to_signed(SEED_0, width));
					seed <= STD_LOGIC_VECTOR(to_signed(SEED_0, width));
			end case;	
		
		--When a new value has been calculated at the end of a generation cycle
		elsif(clk = '0' and clk'event) then 
			if(fsm_stage = 5) then
				s0 <= mul_out;		--Store the latest seed 
				if(UA_TX_ready = '1') then
					s <= mul_out;		--Output the latest seed
				end if;
			end if;
		end if;
	end process;
	
	
	--Main sequencing process
	process(clk, start, reset)
	begin
		
		--Return to the reset state if the rst signal has been asynchronously asserted
		if(reset = '1') then
			fsm_stage <= 0;
			prng_busy <= '0';
			prng_done <= '0';
		
		--All iterative state changes happens on rising edges
		elsif(clk = '1' and clk'event) then 
			case fsm_stage is
			
				--In reset state. Start the divider
				when 0 =>
					if(start = '1') then
						div_start <= '1';
						fsm_stage <= 1;
						prng_busy <= '1';
						prng_done <= '0';
					else
						div_start <= '0';
						fsm_stage <= 0;
						prng_busy <= '0';
						prng_done <= '0';
					end if;
				
				--Turn off the divider start signal
				when 1 =>
					div_start <= '0';
					fsm_stage <= 2;
				
				--Wait for divider to complete
				when 2 =>
					if(div_complete = '1') then
						fsm_stage <= 3;
					else
						fsm_stage <= 2;
					end if;
				
				--Wait one cycle for mul, sub, and mod to complete
				when 3 =>
					fsm_stage <= 4;
					
				--Wait one more cycle for mul, sub, and mod to complete
				when 4 =>
					fsm_stage <= 5;
					
				--Wait one more cycle for mul, sub, and mod to complete
				--The result is outputted to the UART at the falling edge by the other process in this file
				when 5 =>
					fsm_stage <= 6;
				
				--Write the result back as the new seed and output the seed when UART is ready
				when 6 =>
					prng_busy <= '0';
					
					--Only change the state if UA_TX is ready. Otherwise, we wait.
					if(UA_TX_ready = '1') then
						fsm_stage <= 7;
					else
						fsm_stage <= 6;
					end if;
				
				--Assert PRNG_DONE so UART will accept the seed
				when 7 =>
					prng_done <= '1';
					fsm_stage <= 0;
					
				when others =>
					report "ERROR! INVALID STATE!";
			end case;
					
		end if;
	end process;
	

end Behavioral;
















































