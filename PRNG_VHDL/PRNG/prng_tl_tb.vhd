LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY prng_tl_tb IS
	generic(width : integer := 32);
END prng_tl_tb;
 
ARCHITECTURE behavior OF prng_tl_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT prng_toplevel
    PORT(
         clk : IN  std_logic;
         reset : IN  std_logic;
         start : IN  std_logic;
         test_word_TX : IN  std_logic;
         test_byte_TX : IN  std_logic;
         seed_sel : IN  std_logic_vector(1 downto 0);
         baud_sel : IN  std_logic_vector(2 downto 0);
         PRNG_busy : OUT  std_logic;
         UA_TX_ready : OUT  std_logic;
         bit_out : OUT  std_logic;
			
			--debug
			prng_seed_out : out  STD_LOGIC_VECTOR (width-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal start : std_logic := '0';
   signal test_word_TX : std_logic := '0';
   signal test_byte_TX : std_logic := '0';
   signal seed_sel : std_logic_vector(1 downto 0) := (others => '0');
   signal baud_sel : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal PRNG_busy : std_logic;
   signal UA_TX_ready : std_logic;
   signal bit_out : std_logic;
	
	--debig
	signal prng_seed_out :  STD_LOGIC_VECTOR (width-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: prng_toplevel PORT MAP (
          clk => clk,
          reset => reset,
          start => start,
          test_word_TX => test_word_TX,
          test_byte_TX => test_byte_TX,
          seed_sel => seed_sel,
          baud_sel => baud_sel,
          PRNG_busy => PRNG_busy,
          UA_TX_ready => UA_TX_ready,
          bit_out => bit_out,
			 prng_seed_out => prng_seed_out
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
	
		baud_sel <= "010";
		seed_sel <= "00";
		reset <= '1';
		wait for clk_period;
		reset <= '0';
      wait for clk_period;		
		start <= '1';
		wait for clk_period;
		--start <= '0';
		--wait until PRNG_busy = '0';

      wait;
   end process;

END;
