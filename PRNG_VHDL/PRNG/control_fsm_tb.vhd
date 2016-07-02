LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
 
ENTITY control_fsm_tb IS
END control_fsm_tb;
 
ARCHITECTURE behavior OF control_fsm_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT control_fsm
    PORT(
         seed_sel : IN  std_logic_vector(1 downto 0);
         UA_TX_ready : IN  std_logic;
         clk : IN  std_logic;
         start : IN  std_logic;
         reset : IN  std_logic;
         s : OUT  std_logic_vector(31 downto 0);
         seed : OUT  std_logic_vector(31 downto 0);
         prng_done : OUT  std_logic;
         prng_busy : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal seed_sel : std_logic_vector(1 downto 0) := (others => '0');
   signal UA_TX_ready : std_logic := '0';
   signal clk : std_logic := '0';
   signal start : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal s : std_logic_vector(31 downto 0);
   signal seed : std_logic_vector(31 downto 0);
   signal prng_done : std_logic;
   signal prng_busy : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: control_fsm PORT MAP (
          seed_sel => seed_sel,
          UA_TX_ready => UA_TX_ready,
          clk => clk,
          start => start,
          reset => reset,
          s => s,
          seed => seed,
          prng_done => prng_done,
          prng_busy => prng_busy
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
      -- hold reset state for 100 ns.
      seed_sel <= "01";
		reset <= '1';
		wait for 100 ns;
		reset <= '0';
      wait for clk_period*10;

      -- insert stimulus here 
		start <= '1';
		wait for clk_period;
		

      wait;
   end process;

END;
