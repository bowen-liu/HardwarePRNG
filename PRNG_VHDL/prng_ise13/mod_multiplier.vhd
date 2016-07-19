library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity mod_multiplier is

    generic(width : integer := 32);
	 
	 Port ( X : in  STD_LOGIC_VECTOR (31 downto 0);
           Y : in  STD_LOGIC_VECTOR (31 downto 0);
           M : in  STD_LOGIC_VECTOR (31 downto 0);
           P_OUT : out  STD_LOGIC_VECTOR (31 downto 0);
			  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           start : in  STD_LOGIC;
           output_ready : out  STD_LOGIC
			  );
			  
end mod_multiplier;

architecture Behavioral of mod_multiplier is

	--Primary registers that holds the operands and accumulates the results during each iteration
	signal Y_buffer : signed (width-1 downto 0);
	signal X_buffer : signed (width-1 downto 0);
	signal M_buffer : signed (width-1 downto 0);
	signal P : signed (width-1 downto 0);
	
	--Secondary registers holding independant function results needed by iteration
	signal iteration : integer;
	
	--One iteration of the interleaved modular multiplication algorithm
	impure function one_iteration (X_buffer: in signed;
									Y_buffer: in signed;
									M_buffer: in signed;
									P: in signed) return signed is
		
		variable P_temp : signed (width-1 downto 0);
	begin
		p_temp := (P sll 1);
		
		--Replaces an multiplication function for I = Xi * Y
		--If Xi is 1, add Y. If Xi is 0, no need to modify p.
		if(X_buffer(iteration) = '1') then
					p_temp := p_temp + Y_buffer;
		end if;
				
		if(p_temp >= M_buffer) then
			p_temp := p_temp - M_buffer;
			
			if(p_temp >= M_buffer) then
				p_temp := p_temp - M_buffer;
			end if;	
		end if;
		
		return p_temp;
	end function one_iteration;
	
begin

	process(clk, rst)
		
	begin
			
		--Reset is asynchronous. All other iterations of the division algorithm happens on the rising edge
		if(rst = '1') then
		
			Y_buffer <= (others => '0');
			X_buffer <= (others => '0');
			M_buffer <= (others => '0');
			
			P <= (others => '0');
			iteration <= -2;			--Setting iteration at reset to -2, because -1 indicates completion
			output_ready <= '0';
			
		elsif(clk = '1' and clk'event) then
			
			--Load the initial operand values when the divider's idle
			if(start = '1') then
				
				--Operand sanity check
				assert(signed(X) >= 0 and signed(Y) <= signed(M)) report "Invalid Operands" severity failure;
				
				--Buffer input operands
				Y_buffer <= signed(Y);
				X_buffer <= signed(X);
				M_buffer <= signed(M);
			
				--Reset all registers
				P <= (others => '0');
				iteration <= width-1;
				output_ready <= '0';
			
			--Run one iteration of the algorithm on the rising edge
			elsif(iteration >= 0) then
				output_ready <= '0';
				P <= one_iteration(X_buffer, Y_buffer, M_buffer, P);
				iteration <= iteration - 1;
			
			--Output the value when all iterations has executed
			elsif(iteration = -1) then
				P_OUT <= std_logic_vector(P);
				output_ready <= '1';
			end if;
		end if;
	end process;


end Behavioral;























