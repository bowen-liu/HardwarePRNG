library IEEE;
library work;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.PRNG_CONST.ALL;

entity multiplication_stage is
    Port ( rst : in STD_LOGIC;
           Y : in  STD_LOGIC_VECTOR (31 downto 0);
           Z : in  STD_LOGIC_VECTOR (31 downto 0);
           output : out  STD_LOGIC_VECTOR (31 downto 0));
end multiplication_stage;

architecture Behavioral of multiplication_stage is
	signal ay, rz: integer;
begin

	--a*y
	process(Y, rst)
	begin
		case rst is
			when '1' => ay <= 0;
			when '0' => ay <= to_integer(signed(Y)) * CONST_A;
			when others => ay <= 0;
		end case;
	end process;
		
	--z*r
	process(Z, rst)
	begin
		case rst is
			when '1' => rz <= 0;
			when '0' => rz <= to_integer(signed(Z)) * CONST_R;
			when others => rz <= 0;
		end case;
	end process;
	
	--(aY - rZ) % M
	process(ay, rz)
		variable temp : SIGNED (31 downto 0);
	begin
	
		--aY - rZ
		temp := to_signed(ay-rz, output'length);
		
		--If the resulting seed is negative, add M to aY-rZ .This operation is the same as subtracting M_BAR from aY-rZ.
		--This step essentially performs the mod operation required by the algorithm.
		if(temp <= 0) then
			temp := temp + to_signed(CONST_M, temp'length);
		end if;
		
		--Outputs (aY - rZ) % M
		output <= std_logic_vector(temp);
	end process;

end Behavioral;

