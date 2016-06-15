--This module is used to test the individual subcomponents of the main divider, minus the main division control process

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity divider_test is

	generic(width : integer := 32);
	
   Port ( Y : in  STD_LOGIC_VECTOR (31 downto 0);
          X : in  STD_LOGIC_VECTOR (31 downto 0);
          R : out  STD_LOGIC_VECTOR (31 downto 0);
          Q : out  STD_LOGIC_VECTOR (31 downto 0);
          clk : in  STD_LOGIC;
			 rst : in  STD_LOGIC;
          start : in  STD_LOGIC;
          output_ready : out  STD_LOGIC;
			  
			Y_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			X_buf_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			Z_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			px_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			py_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu1_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			mu2_dbg : OUT STD_LOGIC_VECTOR (31 downto 0);
			delta_dbg : OUT STD_LOGIC_VECTOR (31 downto 0)
           );
end divider_test;

architecture Behavioral of divider_test is
	
	signal Y_buffer : STD_LOGIC_VECTOR (31 downto 0);
	signal X_buffer : STD_LOGIC_VECTOR (31 downto 0);
	
	signal operands_valid : STD_LOGIC := '0';
	
	signal Z : STD_LOGIC_VECTOR (31 downto 0) := (others => '0');
	signal px, py : Integer;
	signal mu_phase1 : Integer;
	signal mu_phase2 : Integer;
	signal delta : STD_LOGIC_VECTOR (31 downto 0);
	
	--Given a STL input X, find the most significant bit of X that's 1.
	function findMS1(X : in  STD_LOGIC_VECTOR) return Integer is
	begin
			for i in 31 downto 0 loop
				if (X(i) = '1') then
					return i;
				end if;
			end loop;
			
			--Return 0 if X = 0
			return 0;		
	end function findMS1;
	
	--Given a STL input X, find the most significant bit of X that's 0.
	function findMS0(X : in  STD_LOGIC_VECTOR) return Integer is
		variable negated_x : STD_LOGIC_VECTOR (31 downto 0);
	begin
			negated_x := not X;
			for i in 31 downto 0 loop
				if (negated_x(i) = '1') then
					return i;
				end if;
			end loop;
			
			--Return 0 if X = -1
			return 0;		
	end function findMS0;
	
begin

	--Output intermediate debug values
	Y_buf_dbg <= Y_buffer;
	X_buf_dbg <= X_buffer;
	Z_dbg <= Z;
	px_dbg <= std_logic_vector(to_signed(px, X'length));
	py_dbg <= std_logic_vector(to_signed(py, Y'length));
	mu1_dbg <= std_logic_vector(to_signed(mu_phase1, Y'length));
	mu2_dbg <= std_logic_vector(to_signed(mu_phase2, Y'length));
	delta_dbg <= delta;
	
	
	--Generates values for PY and Delta on the falling edge
	process(clk)
	begin
		if(clk = '0' and clk'event) then
		
			if(signed(Y_buffer) < 0) then				--Find the Most Significant 0 if Y<0. 
				py <= findMS0(Y_buffer);
			elsif(signed(Y_buffer) > 0) then			--If Y>0, the MS 1 is found instead. 
				py <= findMS1(Y_buffer);
			else												--If Y=0, the process will return a 0 since a MS 1 cannot be found.
				py <= 0;
			end if;
			
		end if;
	end process;
	
	--Generates alues for PX. 
	--Since the X is only changed once per division, and PX is only needed PX is updated asynchronously.
	process(X_buffer)
	begin
		px <= findMS1(X_buffer);	
	end process;
	
	--Generates Delta.
	--Since Delta depends on py and px, the process is asynchronous and updates the value whenever py or px changes.
	process(py,px)
		variable bit_pos : integer;
		variable delta_temp : std_logic_vector(31 downto 0);
	begin
		bit_pos := py - px;
		
		--Only calculate the new delta value if bit_pos is in a valid range
		if(bit_pos > 0 and bit_pos < width-1) then
			delta_temp := (others => '0');
			delta_temp(bit_pos) := '1';
			delta <= delta_temp;
		end if;
	end process;
	
	--Generates the "mu" signal for the first phase of the division algorithm on the falling edge
	process(clk)
	begin
		if(clk = '0' and clk'event) then
			if(signed(Y_buffer) >= 0) then
				mu_phase1 <= 1;
			else
				mu_phase1 <= -1;
			end if;
		end if;
	end process;
	
	--Generates the "mu" signal for the second phase of the division algorithm on the falling edge
	process(clk)
	begin
		if(clk = '0' and clk'event) then
			if(signed(Y_buffer) >= signed(X_buffer)) then
				mu_phase2 <= 1;
			else
				mu_phase2 <= -1;	--When Y<0
			end if;
		end if;
	end process;
	
	--Main Division algorithm and controls
	process(clk, rst)
		variable temp1, temp2, temp3, temp4 : signed(31 downto 0);
		variable tempi1, tempi2, tempi3 : integer;
	begin
		
		--Reset is asynchronous. All other iterations of the division algorithm happens on the rising edge
		if(rst = '1') then
		
			Y_buffer <= (others => '0');
			X_buffer <= (others => '0');
	
			Z <= (others => '0');
			Q <= (others => '0');
			R <= (others => '0');
			output_ready <= '0';
		
		elsif(clk = '1' and clk'event) then
			
			--Load the initial operand values when the divider's idle
			if(start = '1') then
				Y_buffer <= Y;
				X_buffer <= X;
		
				--Reset all registers
				Z <= (others => '0');
				Q <= (others => '0');
				R <= (others => '0');
				output_ready <= '0';
				
			--Run one iteration of Algorithm Phase 1
			elsif (py > px) then
				--Calculate Y value for this iteration
				tempi1 := to_integer(to_signed(mu_phase1,Y_buffer'length)) * to_integer(signed(delta));
				tempi2 := to_integer(signed(Y_buffer)) - tempi1 * to_integer(signed(X_buffer));
				Y_buffer <= std_logic_vector(to_signed(tempi2,Y_buffer'length));
				
				--Calculate Z value for this iteration
				tempi3 := to_integer(signed(Z)) + tempi1;
				Z <= std_logic_vector(to_signed(tempi3,Z'length));
				
			--Run one iteration of Algorithm Phase 2
			else	
				--Does quotient and remainder needs adjustments?
				if(not(signed(Y_buffer) >= 0 and signed(Y_buffer) < signed(X_buffer))) then
					
					--Calculate Y value for this iteration
					tempi1 := to_integer(signed(Y_buffer)) - mu_phase2 * to_integer(signed(X_buffer));
					Y_buffer <= std_logic_vector(to_signed(tempi1,Y_buffer'length));
					
					--Calculate Z value for this iteration
					tempi2 := to_integer(signed(Z)) + mu_phase2;
					Z <= std_logic_vector(to_signed(tempi2,Z'length));
					
				end if;
				
				--Output the results
				R <= Y_buffer;
				Q <= Z;
				output_ready <= '1';
				
			end if;
		end if;
	end process;

end Behavioral;

