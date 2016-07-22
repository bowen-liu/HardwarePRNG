LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use IEEE.NUMERIC_STD.all;

ENTITY mod_multiplier_tb IS

	generic(width : integer := 32);
	
END mod_multiplier_tb;
 
ARCHITECTURE behavior OF mod_multiplier_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
	
    COMPONENT mod_multiplier
    PORT(
         X : IN  std_logic_vector(31 downto 0);
         Y : IN  std_logic_vector(31 downto 0);
         M : IN  std_logic_vector(31 downto 0);
         P_OUT : OUT  std_logic_vector(31 downto 0);
         clk : IN  std_logic;
         rst : IN  std_logic;
         start : IN  std_logic;
         output_ready : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(31 downto 0) := (others => '0');
   signal Y : std_logic_vector(31 downto 0) := (others => '0');
   signal M : std_logic_vector(31 downto 0) := (others => '0');
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';
   signal start : std_logic := '0';

 	--Outputs
   signal P_OUT : std_logic_vector(31 downto 0);
   signal output_ready : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mod_multiplier PORT MAP (
          X => X,
          Y => Y,
          M => M,
          P_OUT => P_OUT,
          clk => clk,
          rst => rst,
          start => start,
          output_ready => output_ready
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
	
		rst <= '1';
      wait for clk_period;
		rst <= '0';
      wait for clk_period*10;

      -- insert stimulus here 
		
		--Answer: 1
		X <= std_logic_vector(to_signed(256, width));
		Y <= std_logic_vector(to_signed(1, width));
		M <= std_logic_vector(to_signed(3, width));
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		wait until output_ready = '1';
		wait for clk_period;
		
		--Answer: 3
		X <= std_logic_vector(to_signed(1337, width));
		Y <= std_logic_vector(to_signed(3, width));
		M <= std_logic_vector(to_signed(24, width));
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		wait until output_ready = '1';
		wait for clk_period;
		
      wait;
   end process;

END;
