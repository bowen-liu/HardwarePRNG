LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
 
ENTITY divider_test2tb IS
END divider_test2tb;
 
ARCHITECTURE behavior OF divider_test2tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT divider_test
    PORT(
         Y : IN  std_logic_vector(31 downto 0);
         X : IN  std_logic_vector(31 downto 0);
         R : OUT  std_logic_vector(31 downto 0);
         Q : OUT  std_logic_vector(31 downto 0);
         clk : IN  std_logic;
         rst : IN  std_logic;
         start : IN  std_logic;
         output_ready : OUT  std_logic;
			
			Y_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			X_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			Z_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			px_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			py_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu1_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu2_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			delta_dbg : OUT STD_LOGIC_VECTOR (31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Y : std_logic_vector(31 downto 0) := (others => '0');
   signal X : std_logic_vector(31 downto 0) := (others => '0');
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';
   signal start : std_logic := '0';

 	--Outputs
   signal R : std_logic_vector(31 downto 0);
   signal Q : std_logic_vector(31 downto 0);
   signal output_ready : std_logic;
	
	--debugs
	signal Y_buf_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal X_buf_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal Z_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal px_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal py_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal mu1_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal mu2_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal delta_dbg : STD_LOGIC_VECTOR (31 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: divider_test PORT MAP (
          Y => Y,
          X => X,
          R => R,
          Q => Q,
          clk => clk,
          rst => rst,
          start => start,
          output_ready => output_ready,
			 Z_dbg => Z_dbg,
			 Y_buf_dbg => Y_buf_dbg,
			 X_buf_dbg => X_buf_dbg,
			 px_dbg => px_dbg,
			 py_dbg => py_dbg,
			 mu1_dbg => mu1_dbg,
			 mu2_dbg => mu2_dbg,
			 delta_dbg => delta_dbg
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
      wait for 5 ns;
      --wait for clk_period*2;

      --test1 
--		Y <= X"7B818935";
--		X <= X"0001F31D";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
		
		--test2
--		Y <= X"142E4ECE";
--		X <= X"6C37C0BB";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
		
		--test3
--		Y <= X"68493A1B";
--		X <= X"0001F31D";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;

		--test4
		Y <= X"73F12C81";
		X <= X"0001F31D";
		start <= '1';
		wait for clk_period;
		start <= '0';

      wait;
   end process;

END;
