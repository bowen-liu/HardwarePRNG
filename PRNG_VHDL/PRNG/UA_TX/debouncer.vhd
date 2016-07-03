library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE work.prng_package.ALL;

entity debouncer is
    Port ( -- inputs
			  clk : in  STD_LOGIC;
			  reset: in std_logic;
           x_in : in  STD_LOGIC;
			  -- debug outputs
			  enable_copy, load_copy: out std_logic;
			  count_out_copy : out std_logic_vector (19 downto 0);
			  n_state_copy, p_state_copy: out debouncer_state_type;
			  -- output
           x_out : out  STD_LOGIC
			  );
end debouncer;

architecture Behavioral of debouncer is
	
	component debouncer_fsm is
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
	end component debouncer_fsm;

	component  debouncer_counter is
    Port (
		-- inputs
      enable :in  std_logic;                     -- Enable counting
      clk    :in  std_logic;                     -- Input clock
      reset  :in  std_logic;                      -- Input reset
		-- output
		count_out: out std_logic_vector (19 downto 0)
			  );
	end component debouncer_counter;
	
	-- declare internal signals
	-- internal signals where fsm is source
	signal enable_internal: std_logic;
	-- internal signals where counter is source	
	signal count_out_internal : std_logic_vector (19 downto 0);
	
begin

	debouncer_fsm_instance: debouncer_fsm port map (
		clk => clk,
		reset => reset,
		x_in => x_in,
		count_in => count_out_internal,
		n_state_copy => n_state_copy,
		p_state_copy => p_state_copy,
		enable => enable_internal,
		x_out => x_out
	);
	enable_copy <= enable_internal;
	
	debouncer_counter_instance: debouncer_counter port map (
			 enable => enable_internal,
          clk => clk,
          reset => reset,
			 count_out => count_out_internal
	);
	count_out_copy <= count_out_internal;
end Behavioral;