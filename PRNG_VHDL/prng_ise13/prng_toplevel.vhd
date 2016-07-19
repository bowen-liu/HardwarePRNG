library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity prng_toplevel is
    generic(width : integer := 32);
	 Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           start : in  STD_LOGIC;
           test_word_TX : in  STD_LOGIC;
			  test_byte_TX : in  STD_LOGIC;
			  seed_sel : in  STD_LOGIC_VECTOR (1 downto 0);
           baud_sel : in  STD_LOGIC_VECTOR (2 downto 0);
			  PRNG_busy : out  STD_LOGIC;
           UA_TX_ready : out  STD_LOGIC;
           bit_out : out  STD_LOGIC;
			  
			  --debug
			  prng_seed_out : out  STD_LOGIC_VECTOR (width-1 downto 0)
			  );
end prng_toplevel;

architecture Behavioral of prng_toplevel is

	--Output buffers for the main PRNG system
	signal prng_s, prng_seed : STD_LOGIC_VECTOR (width-1 downto 0);
	signal prng_pdone, prng_pbusy : STD_LOGIC;

	--Output buffer for UART
	signal UATX_rdy : STD_LOGIC;

	component control_fsm is
   Port ( seed_sel : in  STD_LOGIC_VECTOR (1 downto 0);
          UA_TX_ready : in  STD_LOGIC;
          clk : in  STD_LOGIC;
          start : in  STD_LOGIC;
          reset : in  STD_LOGIC;
          s : out  STD_LOGIC_VECTOR (width-1 downto 0);
          seed : out  STD_LOGIC_VECTOR (width-1 downto 0);
          prng_done : out  STD_LOGIC;
          prng_busy : out  STD_LOGIC);
	end component;

	component UA_TX is
	Port (  seed : in  STD_LOGIC_VECTOR (31 downto 0); -- initial seed
           s : in  STD_LOGIC_VECTOR (31 downto 0); -- resulting random number
           prng_done : in  STD_LOGIC;
           baud_sel : in  STD_LOGIC_VECTOR (2 downto 0);
			  clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           test_word_TX : in  STD_LOGIC; -- Test module word_TX
           test_byte_TX : in  STD_LOGIC; -- Test module 
           UA_TX_ready : out  STD_LOGIC;
           bit_out : out  STD_LOGIC);
	end component;

begin
	
	PRNG : control_fsm PORT MAP (
		seed_sel => seed_sel,
		UA_TX_ready => UATX_rdy,
		clk => clk,
		start => start,
		reset => reset,
		s => prng_s,
		seed => prng_seed,
		prng_done => prng_pdone,
		prng_busy => prng_pbusy);
	
	
	UART : ua_tx PORT MAP (
		seed => prng_seed,
		s => prng_s,
		prng_done => prng_pdone,
		baud_sel => baud_sel,
		clk => clk,
		reset => reset,
		test_word_TX => test_word_TX,
		test_byte_TX =>test_byte_TX,
		UA_TX_ready => UATX_rdy,
		bit_out => bit_out);
	
	--Output signals
	PRNG_busy <= prng_pbusy;
	UA_TX_ready <= UATX_rdy;
	
	--Debug signals
	prng_seed_out <= prng_s;

end Behavioral;

