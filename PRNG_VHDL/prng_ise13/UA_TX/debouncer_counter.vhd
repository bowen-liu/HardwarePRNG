library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;
USE work.prng_package.ALL;

entity debouncer_counter is
 port (
		-- inputs
      enable :in  std_logic;                     -- Enable counting
      clk    :in  std_logic;                     -- Input clock
      reset  :in  std_logic;                      -- Input reset
		-- output
		count_out: out std_logic_vector (19 downto 0)
    );
  end entity debouncer_counter;
  
  architecture rtl of debouncer_counter is
  begin
      process (clk, reset, enable) IS
			variable count :signed (19 downto 0);
		begin
          if reset = '1' then -- asynchronous reset
              count := x"00000";
          elsif (rising_edge(clk) and (enable = '1')) then
					if count < delay_value then
						count := count +1;
					else
						count := x"00000";
					end if;
          end if; -- rising edge
			 
			 count_out <= std_logic_vector(count);
			 
      end process;
  end architecture rtl;

