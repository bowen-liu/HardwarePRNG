--This module is used to test the individual subcomponents of the main divider, minus the main division control process

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity divider is

	generic(width : integer := 32);
	
   Port ( Y : in  STD_LOGIC_VECTOR (width-1 downto 0);
          X : in  STD_LOGIC_VECTOR (width-1 downto 0);
          R : out  STD_LOGIC_VECTOR (width-1 downto 0);
          Q : out  STD_LOGIC_VECTOR (width-1 downto 0);
          clk : in  STD_LOGIC;
          rst : in  STD_LOGIC;
          start : in  STD_LOGIC;
          output_ready : out  STD_LOGIC;
			
			--Debug signals
          Y_buf_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          X_buf_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          Z_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          px_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          py_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          mu1_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          mu2_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0);
          delta_dbg : OUT STD_LOGIC_VECTOR (width-1 downto 0)
           );
end divider;

architecture Behavioral of divider is
	
	--Primary registers that holds the operands and accumulates the results during each iteration
	signal Y_buffer : SIGNED (width-1 downto 0);
	signal X_buffer : SIGNED (width-1 downto 0);
	signal Z : SIGNED (width-1 downto 0) := (others => '0');
	
	--Secondary registers holding independant function results needed by iteration
	signal px, py : Integer;
	signal mu_phase1 : Integer;
	signal mu_phase2 : Integer;
	signal delta_pos : integer;
	signal delta : SIGNED (width-1 downto 0);
	
	--Given a STL input X, find the most significant bit of X that's 1.
	function findMS1(X : in  SIGNED) return Integer is
	begin
			for i in width-1 downto 0 loop
				if (X(i) = '1') then
					return i;
				end if;
			end loop;
			
			--Return 0 if X = 0
			return 0;		
	end function findMS1;
	
	--Given a STL input X, find the most significant bit of X that's 0.
	function findMS0(X : in  SIGNED) return Integer is
		variable negated_x : SIGNED (width-1 downto 0);
	begin
			negated_x := not X;
			for i in width-1 downto 0 loop
				if (negated_x(i) = '1') then
					return i;
				end if;
			end loop;
			
			--Return 0 if X = -1
			return 0;		
	end function findMS0;
	
	--Turn X into a negative number if MU is -1. X remains positive if MU is 1 or anything else.
	--Since multiplying any integer X by MU will either result in -X or X, this function will replace a multiplication op.
	function mu_multiply(X: in integer; mu: in integer) return Integer is
	begin
		case mu is
			--If MU = -1, X's signs are switched
			when -1 => 
				return 0 - X;
			--If MU = 1, X is unchanged
			when 1 => 
				return X;
			--MU is an unexpected value, X remains unchanged
			when others => 	
				report "mu_multiply: ERR MU IS NOT -1 OR 1";
				return X;
		end case;
	end function mu_multiply;
	
begin

	--Output intermediate debug values
	Y_buf_dbg <= std_logic_vector(Y_buffer);
	X_buf_dbg <= std_logic_vector(X_buffer);
	Z_dbg <= std_logic_vector(Z);
	px_dbg <= std_logic_vector(to_signed(px, X'length));
	py_dbg <= std_logic_vector(to_signed(py, Y'length));
	mu1_dbg <= std_logic_vector(to_signed(mu_phase1, Y'length));
	mu2_dbg <= std_logic_vector(to_signed(mu_phase2, Y'length));
	delta_dbg <= std_logic_vector(delta);
	
	
	--Generates values for PY on the falling edge
	process(clk, rst)
	begin
		if(rst = '1') then
			py <= 0;
		elsif(clk = '0' and clk'event) then
			if(Y_buffer < 0) then				--Find the Most Significant 0 if Y<0. 
				py <= findMS0(Y_buffer);
			elsif(Y_buffer > 0) then			--If Y>0, the MS 1 is found instead. 
				py <= findMS1(Y_buffer);
			else												--If Y=0, the process will return a 0 since a MS 1 cannot be found.
				py <= 0;
			end if;
		end if;
	end process;
	
	--Generates values for PX. 
	--Since the X is unchanged throughout a division cycle, PX is updated asynchronously when X changes.
	process(X_buffer, rst)
	begin
		if(rst = '1') then
			px <= 0;
		else
			px <= findMS1(X_buffer);
		end if;
	end process;
	
	--Generates Delta. Note that the value for Delta has one bit set to 1 at any given time, where the rest are 0s.
	--In this implementation, both the value of delta AND the 1's bit position of delta is returned
	--Since Delta depends on py and px, the process is asynchronous and updates the value whenever py or px changes.
	process(py, px, rst)
		variable bit_pos : integer;
		variable delta_temp : SIGNED (width-1 downto 0);
	begin
		if(rst = '1') then
			delta_pos <= 0;
			delta <= (others => '0');
		else
			bit_pos := py - px;
			
			--Only return the new delta value (and the bit position that's 1) if bit_pos is in a valid range
			if(bit_pos > 0 and bit_pos < width-1) then
				delta_temp := (others => '0');
				delta_temp(bit_pos) := '1';
				delta <= delta_temp;
				delta_pos <= bit_pos;
			end if;
		end if;
	end process;
	
	--Generates the "mu" signal for the first phase of the division algorithm on the falling edge
	process(clk, rst)
	begin
		if(rst = '1') then
			mu_phase1 <= 0;
		elsif(clk = '0' and clk'event) then
			if(Y_buffer >= 0) then
				mu_phase1 <= 1;
			else
				mu_phase1 <= -1;
			end if;
		end if;
	end process;
	
	--Generates the "mu" signal for the second phase of the division algorithm on the falling edge
	process(clk, rst)
	begin
		if(rst = '1') then
			mu_phase2 <= 0;
		elsif(clk = '0' and clk'event) then
			if(Y_buffer >= X_buffer) then
				mu_phase2 <= 1;
			else
				mu_phase2 <= -1;	--When Y<0
			end if;
		end if;
	end process;
	
	--Main Division algorithm and controls
	process(clk, rst)
		--variable temp1, temp2, temp3, temp4 : signed(31 downto 0);
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
				Y_buffer <= signed(Y);
				X_buffer <= signed(X);
		
				--Reset all registers
				Z <= (others => '0');
				Q <= (others => '0');
				R <= (others => '0'); 
				output_ready <= '0';
				
			--Run one iteration of Algorithm Phase 1
			elsif (py > px) then
				
				--Calculate Y value for this iteration. Y = Y - mu * delta * X.
				--We can use logical shift left to accomplish the multiplication of delta and X, since delta is always a power of 2.
				tempi1 := to_integer(X_buffer sll delta_pos);
				tempi2 := to_integer(Y_buffer) - mu_multiply(tempi1, mu_phase1);	
				Y_buffer <= to_signed(tempi2,Y_buffer'length);
				
				--Calculate Z value for this iteration. Z = Z + delta * mu
				tempi3 := to_integer(Z) + mu_multiply(to_integer(delta), mu_phase1);	
				Z <= to_signed(tempi3,Z'length);
				
			--Run one iteration of Algorithm Phase 2
			else	
				--Does quotient and remainder needs adjustments?
				if(not(Y_buffer >= 0 and Y_buffer < X_buffer)) then
					
					--Calculate Y value for this iteration. Y = Y - X * mu_2
					tempi1 := to_integer(Y_buffer) - mu_multiply(to_integer(X_buffer), mu_phase2);	
					Y_buffer <= to_signed(tempi1,Y_buffer'length);
					
					--Calculate Z value for this iteration. Z = Z + mu_2
					tempi2 := to_integer(Z) + mu_phase2;				
					Z <= to_signed(tempi2,Z'length);
				else
					--Output the results
					R <= std_logic_vector(Y_buffer);
					Q <= std_logic_vector(Z);
					output_ready <= '1';	
				end if;	
			end if;
		end if;
	end process;

end Behavioral;

