LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
 
ENTITY divider_tb IS
END divider_tb;
 
ARCHITECTURE behavior OF divider_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT divider
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

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: divider PORT MAP (
          Y => Y,
          X => X,
          R => R,
          Q => Q,
          clk => clk,
          rst => rst,
          start => start,
          output_ready => output_ready,
			 operands_valid_dbg => operands_valid_dbg,
			 divider_busy_dbg => divider_busy_dbg,
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
      --wait for 100 ns;
      --wait for clk_period*2;

      -- insert stimulus here 
		--Y <= "00111111111111111111110111111111";
		--Y <= "00000000000000000000000000000000";
		--X <= "00000110110001100010000111111110";
		Y <= X"7B818935";
		X <= X"0001F31D";
		start <= '1';
		wait for 10 ns;
		start <= '0';

      wait;
   end process;

END;
