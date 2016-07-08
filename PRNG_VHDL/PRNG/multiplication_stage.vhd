library IEEE;
library work;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.PRNG_CONST.ALL;

entity multiplication_stage is
    Port ( Y : in  STD_LOGIC_VECTOR (31 downto 0);
           Z : in  STD_LOGIC_VECTOR (31 downto 0);
           output : out  STD_LOGIC_VECTOR (31 downto 0));
end multiplication_stage;

architecture Behavioral of multiplication_stage is
	signal ay, rz: integer;
begin

	--a*y
	process(Y)
	begin
		ay <= to_integer(signed(Y)) * CONST_A;
	end process;
		
	--z*r
	process(Z)
	begin
		rz <= to_integer(signed(Z)) * CONST_R;
	end process;
	
	--aY - rZ
	process(ay, rz)
		variable temp : SIGNED (31 downto 0);
	begin
		temp := to_signed(ay-rz, output'length);
		
		--Add M to aY-rZ if the result is negative. Replacement for mod M?
		if(temp <= 0) then
			temp := temp + to_signed(CONST_M, temp'length);
		end if;
		
		output <= std_logic_vector(temp);
		
	end process;
		

end Behavioral;

