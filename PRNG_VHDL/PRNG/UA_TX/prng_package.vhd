library IEEE;
use IEEE.STD_LOGIC_1164.all;
USE ieee.numeric_std.ALL;
package prng_package is


TYPE divider_fsm_state_type IS (
	idle, initialize, iterate, phase2, final);

TYPE prng_alg_1_fsm_state_type IS (
	idle, 
	mov_q_ALUa, mov_s0_ALUb,  -- load q and s0 in ALU a and b inputs, respectively,
	start_divider,wait_divider, -- start and wait for divider to finish division
	mov_Y_ram, mov_Z_ram, -- store Y, Z
	mov_Y_ALUa, mov_a_ALUb,  -- load Y and a in ALU a and b inputs, respectively, and multiply. 
	mov_aY_RAM, -- store product in location B of RAM
	mov_Z_ALUa, mov_r_ALUb,  -- load Z and r to multiply. 
	mov_rZ_RAM, -- last product in location C of RAM
	mov_aY_ALUa, mov_rZ_ALUb,-- last state stores subtraction in s
	mov_aYrZ_RAM, mov_aYrZ_ALUa,
	mov_s_RAM_ALUs,
	-- Memory trace states
	mov_ram_0, mov_ram_1, wait_0_1, send_0_1,
	mov_ram_2, mov_ram_3, wait_2_3, send_2_3,
	mov_ram_4, mov_ram_5, wait_4_5, send_4_5,
	mov_ram_6, mov_ram_7, wait_6_7, send_6_7,
	mov_ram_8, mov_ram_9, wait_8_9, send_8_9,
	mov_ram_A, mov_ram_B, wait_A_B, send_A_B,
	mov_ram_C, mov_ram_D, wait_C_D, send_C_D,
	mov_ram_E, mov_ram_F, wait_E_F, send_E_F,
	finish);
	
Type word_TX_details_state_type is (idle,
				--
				sends00w  , sends01w, sends02w , sends03w, -- bytes of s0 (seed)
				sends00   , sends01 , sends02  , sends03 ,
				--
				sends10w  , sends11w, sends12w , sends13w, -- bytes of s1 (random number)
				sends10   , sends11 , sends12  , sends13);
				
Type word_TX_state_type is (idle,
				Tw0sw		, Tw0s,	-- "w"  -- Tw is for Test Word
				Tw1sw		, Tw1s,	-- "o"
				Tw2sw		, Tw2s,	-- "r"
				Tw3sw		, Tw3s,	-- "d"
				Tw4sw		, Tw4s,	-- "T"
				Tw5sw		, Tw5s,	-- "X"
				Tw6sw		, Tw6s,	-- "-"
				Tw7sw		, Tw7s,	-- "O"
				Tw8sw		, Tw8s,  -- "K"
				Tw9sw		, Tw9s,	-- "cr"
				Tw10sw	, Tw10s,	-- "lf"
				--
				ch_s0w    , ch_s0   , -- Type character s (s)
				ch_0w     , ch_0    ,  -- Type character 0 (s0) 
				ch_s0eqw  , ch_s0eq , -- Type  character = (s0=)
				ch_s0crw  , ch_s0cr , ch_s0lfw, ch_s0lf, -- new line
				--
				ch_s1w    , ch_s1   , -- Type s to represent the random number
				ch_s1eqw  , ch_s1eq , -- Type = (s=) 
				ch_s1crw  , ch_s1cr , ch_s1lfw, ch_s1lf, -- new line
				--
				sendT10w  , sendT11w, sendT12w , sendT13w, -- bytes of T1 word
				sendT10   , sendT11 , sendT12  , sendT13 ,
				--
				sends00w  , sends01w, sends02w , sends03w, -- bytes of s0 (seed)
				sends00   , sends01 , sends02  , sends03 ,
				--
				sends10w  , sends11w, sends12w , sends13w, -- bytes of s1 (random number)
				sends10   , sends11 , sends12  , sends13);
				
Type byte_TX_state_type is ( -- ASCII
				idle, 
				byte_asciiw, byte_ascii,
				nibble0w , nibble1w,
				nibble0  , nibble1,
				Tb0sw		, Tb0s,	-- "b"  -- Tb is for Test Byte
				Tb1sw		, Tb1s,	-- "y"
				Tb2sw		, Tb2s,	-- "t"
				Tb3sw		, Tb3s,	-- "e"
				Tb4sw		, Tb4s,	-- "T"
				Tb5sw		, Tb5s,	-- "X"
				Tb6sw		, Tb6s,	-- "-"
				Tb7sw		, Tb7s,	-- "O"
				Tb8sw		, Tb8s,	-- "K"
				Tb9sw		, Tb9s,	-- "cr"
				Tb10sw	, Tb10s	-- "lf"
				);
				
type bit_Tx_state_type is (
	idle, start_bit, bit0, bit1, bit2, bit3, bit4, bit5, 
	bit6, bit7, stop_bit);

-- Debouncer
type debouncer_state_type is (dbnce0, dbnce1, dbnce2);
--constant delay_value: signed (19 downto 0) := x"00008"; 
constant delay_value: signed (19 downto 0) := x"186A0"; -- this is 100,000 equiv. 2 ms using 50 MHz clk

-- processor  
constant word_width: integer := 32; -- processor word width

constant word_truncated : integer := 20; 

constant ram_address_width : integer := 4; -- 16 locations in RAM
type RAM_type is array (0 to 2**ram_address_width-1) of std_logic_vector (word_width-1 downto 0); 
type ROM_type is array (0 to word_width-1) of std_logic_vector (word_width-1 downto 0); -- first bit is address 0

--Initial test values
constant a : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(16807,32));

constant M : std_logic_vector(word_width-1 downto 0):= x"7FFFFFFF";

constant M_bar : std_logic_vector(word_width-1 downto 0):= x"80000001";

constant q : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(127773,32));

constant r : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(2836,32));

constant seed_00 : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(2072086837,32));

constant seed_01 : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(338579150,32));

constant seed_10 : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(1749629467,32));

constant seed_11 : std_logic_vector(word_width-1 downto 0):= std_logic_vector(to_signed(1945185409,32));

constant x_package: std_logic_vector (word_width-1 downto 0):= std_logic_vector(to_signed(127773,32));
-- this y gives only phase 1 and no need for phase 2
--constant y_package: std_logic_vector (word_width-1 downto 0) := x"0011fword_width-1d"; --  y =  1176349
-- this y gives -ve y at end of phase 1
constant y_package: std_logic_vector (word_width-1 downto 0):= std_logic_vector(to_signed(1300000,32));  

constant z_package: std_logic_vector (word_width-1 downto 0)   := (OTHERS => '0'); 

constant initial_shift_value_package: integer := 14; -- x can at most be shifted 14 places left to
-- put its bit at power 2^16 in position 2^30.

end prng_package;
