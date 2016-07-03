library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

-- This module accepts 32-bit inputs and produces serial bits 
entity UA_TX is
    Port ( -- inputs
           seed : in  STD_LOGIC_VECTOR (31 downto 0); -- initial seed
           s : in  STD_LOGIC_VECTOR (31 downto 0); -- resulting random number
           prng_done : in  STD_LOGIC;
           baud_sel : in  STD_LOGIC_VECTOR (2 downto 0);
			  clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           test_word_TX : in  STD_LOGIC; -- Test module word_TX
           test_byte_TX : in  STD_LOGIC; -- Test module 
			  
			  -- debug outputs
			  -- word_TX debug outputs
--			  word_TX_ready_display : out std_logic;
--			  word_TX_byte_out_display: out std_logic_vector (7 downto 0);
--			  word_TX_byte_out_valid_display: out std_logic;
--           ns_word_TX : out  word_TX_state_type;
--           ps_word_TX : out  word_TX_state_type;
			  -- byte_TX debug outputs
--			  byte_TX_ready_display: out std_logic;
--			  byte_TX_byte_out_display: out std_logic_vector (7 downto 0);
--			  byte_TX_byte_out_valid_display: out std_logic;
--           ns_byte_TX : out  byte_TX_state_type;
--           ps_byte_TX : out  byte_TX_state_type;
			  -- bit_TX debug outputs
--			  bit_TX_ready_display: out std_logic;
--           ns_bit_TX : out  bit_TX_state_type;
--           ps_bit_TX : out  bit_TX_state_type;
			  -- slow_clk debug outputs
--           slow_clk_out_display : out  STD_LOGIC;
			  -- debouncer debug outputs
--			  ns_debouncer_display: out debouncer_state_type;
--			  ps_debouncer_display: out debouncer_state_type;
--			  prng_done_display: out std_logic;
--			  test_word_TX_display: out std_logic;
--			  test_byte_TX_display: out std_logic;
			  
			   --outputs
           UA_TX_ready : out  STD_LOGIC;
           bit_out : out  STD_LOGIC
			  );
end UA_TX;

architecture Behavioral of UA_TX is

component word_TX is 
    Port ( -- inputs
			  seed : in  STD_LOGIC_VECTOR (31 downto 0);
           s : in  STD_LOGIC_VECTOR (31 downto 0);
           prng_done : in  STD_LOGIC;
           byte_TX_ready : in  STD_LOGIC; -- byte_TX_ready  comes from serial interface. 
           clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           test_word_TX : in  STD_LOGIC; -- test word_TX
			  ---- debug outputs
			  --ns_word_TX: out word_TX_state_type; ps_word_TX: out word_TX_state_type;			  
			  ---- outputs 
			  word_TX_ready : out  STD_LOGIC; -- module is ready to accept new seed and s inputs
			  byte_out : out STD_LOGIC_VECTOR (7 downto 0);
			  byte_out_valid : out  STD_LOGIC; -- module has a byte send
			  is_ascii: out std_logic
           );
end component word_TX;

	component byte_TX port(-- inputs
			byte_in : in std_logic_vector (7 downto 0);
			byte_in_valid : in std_logic;
			is_ascii : in std_logic;
			bit_TX_ready : in std_logic;
			test_byte_TX: in std_logic; -- test byte_TX
			clk : in std_logic;
			reset : in std_logic;
			-- debug outputs
--			ns_byte_TX, ps_byte_TX : out byte_TX_state_type;
			-- outputs
			byte_out : out std_logic_vector (7 downto 0);
			byte_out_valid : out std_logic;
			byte_TX_ready : out std_logic
	);
	end component byte_TX;
	
	component bit_TX port(	-- output
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
	end component bit_TX;
	
	component slow_clk port ( 
		clk_in : in STD_LOGIC;
		baud_sel : in std_logic_vector (2 downto 0);
		-- debug outputs
		--count_out: out integer;
		-- output
		clk_out : out STD_LOGIC
	);
	end component slow_clk;
	
	-- need debouncer for test signals
	component debouncer is
    Port ( -- inputs
			  clk : in  STD_LOGIC;
			  reset: in std_logic;
           x_in : in  STD_LOGIC;
			  -- debug outputs
--			  next_state, present_state: out debouncer_state_type;
			  -- output
           x_out : out  STD_LOGIC
			  );
	end component debouncer;
	
	
	-- internal signals where word_TX is the source
	signal word_TX_byte_out_internal: std_logic_vector (7 downto 0);
	signal word_TX_byte_out_valid_internal: std_logic;
	--signal word_TX_ready_internal: std_logic;
	signal is_ascii_internal: std_logic;
	
	-- internal signals where byte_TX is the source
	signal byte_TX_byte_out_iternal: std_logic_vector (7 downto 0);
	signal byte_TX_byte_out_valid_internal: std_logic;
	signal byte_TX_ready_internal: std_logic;
	
	-- internal signals where bit_TX is the source
	signal bit_TX_ready_internal: std_logic;
	
	-- internal signals where slow_clk is the source
	signal slow_clk_internal: std_logic;
	
	-- internal signals where debouncers are the source
	signal test_word_TX_internal: std_logic;
	signal test_byte_TX_internal: std_logic;
	
begin
	
--	UA_TX_ready <= word_TX_ready_internal;
	-- Display internal signals due to word_TX
--	word_TX_ready_display <= word_TX_ready_internal;
--	word_TX_byte_out_display <= word_TX_byte_out_internal;
--	word_TX_byte_out_valid_display <= word_TX_byte_out_valid_internal;
--	word_TX_ready_display <= word_TX_ready_internal;
	-- Display internal signals due to byte_TX
--	byte_TX_byte_out_display <= byte_TX_byte_out_iternal;
--	byte_TX_byte_out_valid_display <= word_TX_byte_out_valid_internal;
--	byte_TX_ready_display <= byte_TX_ready_internal;
	-- display internal signals due to bit_TX
--	bit_TX_ready_display <= bit_TX_ready_internal;
	-- Display internal signals due to slow_clk
--	slow_clk_out_display <= slow_clk_internal;
	-- display debounced signals
--	prng_done_display <= prng_done_internal;
--	test_word_TX_display <= test_word_TX_internal;
--	test_byte_TX_display <= test_byte_TX_internal;

	word_TX_instance: word_TX 
		Port Map( 
			  -- inputs
			  seed => seed,
           s => s,
           prng_done => prng_done,
           byte_TX_ready => byte_TX_ready_internal,
           clk  => clk,
           reset => reset, 
			  test_word_TX => test_word_TX_internal,
			  -- debug outputs	
--			  ns_word_TX => ns_word_TX, 
--			  ps_word_TX  => ps_word_TX,
			  -- outputs
			  word_TX_ready => UA_TX_ready,
			  byte_out  => word_TX_byte_out_internal,
			  byte_out_valid  => word_TX_byte_out_valid_internal,
			  is_ascii => is_ascii_internal
           );
			  
	byte_TX_instance: byte_TX
		port map (-- inputs
		byte_in => word_TX_byte_out_internal,
		byte_in_valid => word_TX_byte_out_valid_internal,
		is_ascii => is_ascii_internal,
		bit_TX_ready => bit_TX_ready_internal,
		test_byte_TX => test_byte_TX_internal,
		clk => clk,
		reset => reset,
		-- debug outputs
--		ns_byte_TX => ns_byte_TX,
--		ps_byte_TX => ps_byte_TX,
		-- outputs
		byte_out => byte_TX_byte_out_iternal,
		byte_out_valid => byte_TX_byte_out_valid_internal,
		byte_TX_ready => byte_TX_ready_internal
	);
			  
	bit_TX_instance:  bit_TX 
		PORT MAP(
			byte_in  => byte_TX_byte_out_iternal,
			byte_in_valid => byte_TX_byte_out_valid_internal,
			slow_clk_in => slow_clk_internal,
			reset  => reset,
			-- debug outputs
--			ns_bit_TX => ns_bit_TX, 
--			ps_bit_TX => ps_bit_TX,
			-- outputs
			bit_out	 => bit_out,
			bit_Tx_ready => bit_TX_ready_internal
		);
		
	slow_clk_instance: slow_clk port map (
			clk_in => clk,
			baud_sel => baud_sel,
			clk_out => slow_clk_internal
	);
	

	test_word_instance: debouncer
		port map (
			clk => clk,
			reset => reset,
			x_in => test_word_TX,
			x_out => test_word_TX_internal
		);

	test_byte_instance: debouncer
		port map (
			clk => clk,
			reset => reset,
			x_in => test_byte_TX,
			x_out => test_byte_TX_internal
		);

	
end Behavioral;
