
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name prng_ise13 -dir "C:/Users/bowenliu/prng_ise13/planAhead_run_2" -part xc3s1200efg320-5
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "prng_toplevel.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/prng_package.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/debouncer_fsm.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/debouncer_counter.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/PRNG_CONST.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/word_TX.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/slow_clk.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/debouncer.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/byte_TX.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/bit_TX.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/multiplication_stage.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/divide_2.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/UA_TX.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/control_fsm.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {../Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/prng_toplevel.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top prng_toplevel $srcset
add_files [list {prng_toplevel.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc3s1200efg320-5
