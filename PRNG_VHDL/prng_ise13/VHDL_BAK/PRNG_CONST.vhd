library IEEE;
use IEEE.STD_LOGIC_1164.all;

package PRNG_CONST is

--Global Constants for all calculations
constant CONST_A : integer := 16807;
constant CONST_M : integer := 2147483647;
constant CONST_Q : integer := 127773;
constant CONST_R : integer := 2836;

--Different initial seeds
constant SEED_0 : integer := 2072086837;
constant SEED_1 : integer := 338579150;
constant SEED_2 : integer := 1749629467;
constant SEED_3 : integer := 1945185409;

end PRNG_CONST;


package body PRNG_CONST is
end PRNG_CONST;
