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
			
			operands_valid_dbg : out  STD_LOGIC;
			divider_busy_dbg : out STD_LOGIC;
			Y_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			X_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			Z_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			px_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			py_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu1_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu2_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			delta_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			temp1_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			temp2_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			temp3_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			temp4_dbg : OUT STD_LOGIC_VECTOR (31 downto 0)
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
	signal operands_valid_dbg : STD_LOGIC;
	signal divider_busy_dbg : STD_LOGIC;
	signal Y_buf_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal X_buf_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal Z_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal px_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal py_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal mu1_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal mu2_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal delta_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal temp1_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal temp2_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal temp3_dbg : STD_LOGIC_VECTOR (31 downto 0);
	signal temp4_dbg : STD_LOGIC_VECTOR (31 downto 0);

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
			 operands_valid_dbg => operands_valid_dbg,
			 divider_busy_dbg => divider_busy_dbg,
			 Y_buf_dbg => Y_buf_dbg,
			 X_buf_dbg => X_buf_dbg,
			 px_dbg => px_dbg,
			 py_dbg => py_dbg,
			 mu1_dbg => mu1_dbg,
			 mu2_dbg => mu2_dbg,
			 delta_dbg => delta_dbg,
			 temp1_dbg => temp1_dbg,
			 temp2_dbg => temp2_dbg,
			 temp3_dbg => temp3_dbg,
			 temp4_dbg => temp4_dbg
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

      -- insert stimulus here 
--		Y <= X"7B818935";
--		X <= X"0001F31D";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"FEBA4935";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"00AD6635";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"FFB3D7B5";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"00309EF5";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"FFF23B55";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;
--		
--		Y <= X"0001D43D";
--		start <= '1';
--		wait for clk_period;
--		start <= '0';
--		wait for clk_period;

		--test2

		Y <= X"73F12C81";
		X <= X"0001F31D";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"F729EC81";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"06C2D481";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"FEF66081";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"00E97D81";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"FFEFEF01";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"000F20D1";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;
		
		Y <= X"FFFF87E9";
		start <= '1';
		wait for clk_period;
		start <= '0';
		wait for clk_period;

      wait;
   end process;

END;
