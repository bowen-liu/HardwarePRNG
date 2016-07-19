/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_1242562249;
char *WORK_P_3206588008;
char *WORK_P_3849459504;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    work_p_3849459504_init();
    work_p_3206588008_init();
    work_a_0114832023_3212880686_init();
    work_a_2188766090_3212880686_init();
    work_a_1955880404_3212880686_init();
    work_a_1338761290_3212880686_init();
    work_a_2635998694_3212880686_init();
    work_a_2779326271_3212880686_init();
    work_a_1787585657_3316374769_init();
    work_a_0028412107_3212880686_init();
    work_a_1909880560_1516540902_init();
    work_a_1473390551_3212880686_init();
    work_a_4272675976_3212880686_init();
    work_a_0458153245_3212880686_init();
    work_a_3141230461_2372691052_init();


    xsi_register_tops("work_a_3141230461_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    WORK_P_3206588008 = xsi_get_engine_memory("work_p_3206588008");
    WORK_P_3849459504 = xsi_get_engine_memory("work_p_3849459504");

    return xsi_run_simulation(argc, argv);

}
