library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- clk_out is 1 for a number of clk_in pulses equal to Baudrate_Divisor
-- clk_out is 0 for a number of clk_in pulses equal to Baudrate_Divisor

entity slow_clk is  
	port( 
		clk_in : in STD_LOGIC;
		baud_sel : in std_logic_vector (2 downto 0);
		-- debug outputs
		--count_out: out integer;
		-- output
		clk_out : out STD_LOGIC
	);
end slow_clk;

architecture slow_clk of slow_clk is

	signal Rate : integer range 0 to 16383 := 0;
	
begin
	
	process(clk_in, Rate ) IS 
		variable count : integer range 0 to 16383 := 0;
		variable Toggle: STD_LOGIC := '0';
	begin
		if rising_edge( clk_in ) then
			if ( count = Rate ) then
				Toggle := not(Toggle); -- complement Toggle
				count := 0; 
			else
			   Toggle := Toggle;
				count := count + 1;
			end if;
		end if;		
		--count_out <= count;
		clk_out <= Toggle;
		
	end process; 
	
	baud_selection: process ( baud_sel ) is
	begin
	-- assume 50 MHZ clk
	-- if baud rate is 9600, then period should be:
	-- 50X10^6/9600 = 5200.
	-- half-period of the clock should be 2600
		case baud_sel is
			when "000" => Rate <= 650*16; -- 10,400 =  4,800 baud
			when "001" => Rate <= 325*16; --  5,200 =  9,600 baud
			when "010" => Rate <= 162*16; --  2,592 = 19,200 baud
			when "011" => Rate <=  80*16; --  1,280 = 38,400 baud
			when "100" => Rate <=  40*16; --    640 = 76,800 baud
			when others => Rate <= 650*16;
		end case;
	end process baud_selection;

end architecture slow_clk;
