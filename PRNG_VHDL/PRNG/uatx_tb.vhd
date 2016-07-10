LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
 
ENTITY uatx_tb IS
END uatx_tb;
 
ARCHITECTURE behavior OF uatx_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT UA_TX
    PORT(
         seed : IN  std_logic_vector(31 downto 0);
         s : IN  std_logic_vector(31 downto 0);
         prng_done : IN  std_logic;
         baud_sel : IN  std_logic_vector(2 downto 0);
         clk : IN  std_logic;
         reset : IN  std_logic;
         test_word_TX : IN  std_logic;
         test_byte_TX : IN  std_logic;
         UA_TX_ready : OUT  std_logic;
         bit_out : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal seed : std_logic_vector(31 downto 0) := (others => '0');
   signal s : std_logic_vector(31 downto 0) := (others => '0');
   signal prng_done : std_logic := '0';
   signal baud_sel : std_logic_vector(2 downto 0) := (others => '0');
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal test_word_TX : std_logic := '0';
   signal test_byte_TX : std_logic := '0';

 	--Outputs
   signal UA_TX_ready : std_logic;
   signal bit_out : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: UA_TX PORT MAP (
          seed => seed,
          s => s,
          prng_done => prng_done,
          baud_sel => baud_sel,
          clk => clk,
          reset => reset,
          test_word_TX => test_word_TX,
          test_byte_TX => test_byte_TX,
          UA_TX_ready => UA_TX_ready,
          bit_out => bit_out
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
		
		--Set all input signals while UATX is in reset state
		reset <= '1';
		baud_sel <= "010";
		s <= X"01234567";
		seed <= X"76543210";
		prng_done <= '0';
		test_word_TX <= '0';
		test_byte_TX <= '0';
      wait for clk_period*10;
		
		--Exit Reset state after 10 clock cycles
		reset <= '0';
		prng_done <= '1';
		
		--Turn off prng_done once UA_TX module has read in the seed
		wait until ua_tx_ready = '0';
		prng_done <= '0';
		wait for clk_period;

      wait;
   end process;

END;
