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

/* This file is designed for use with ISim build 0xc3576ebc */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/bowenliu/Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/prng_ise13/control_fsm.vhd";
extern char *IEEE_P_1242562249;
extern char *WORK_P_3849459504;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


static void work_a_1955880404_3212880686_p_0(char *t0)
{
    char t17[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    int t16;
    char *t18;
    char *t19;
    int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned char t26;
    unsigned char t27;
    unsigned char t28;

LAB0:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t26 = (t4 == (unsigned char)3);
    if (t26 == 1)
        goto LAB18;

LAB19:    t3 = (unsigned char)0;

LAB20:    if (t3 != 0)
        goto LAB16;

LAB17:
LAB3:    t1 = (t0 + 5440);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 1032U);
    t5 = *((char **)t1);
    t1 = (t0 + 10188);
    t7 = xsi_mem_cmp(t1, t5, 2U);
    if (t7 == 1)
        goto LAB6;

LAB11:    t8 = (t0 + 10190);
    t10 = xsi_mem_cmp(t8, t5, 2U);
    if (t10 == 1)
        goto LAB7;

LAB12:    t11 = (t0 + 10192);
    t13 = xsi_mem_cmp(t11, t5, 2U);
    if (t13 == 1)
        goto LAB8;

LAB13:    t14 = (t0 + 10194);
    t16 = xsi_mem_cmp(t14, t5, 2U);
    if (t16 == 1)
        goto LAB9;

LAB14:
LAB10:    xsi_set_current_line(98, ng0);
    t1 = ((WORK_P_3849459504) + 1648U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5536);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(99, ng0);
    t1 = ((WORK_P_3849459504) + 1648U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5600);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(86, ng0);
    t18 = ((WORK_P_3849459504) + 1648U);
    t19 = *((char **)t18);
    t20 = *((int *)t19);
    t18 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t20, 32);
    t21 = (t0 + 5536);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t18, 32U);
    xsi_driver_first_trans_fast(t21);
    xsi_set_current_line(87, ng0);
    t1 = ((WORK_P_3849459504) + 1648U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5600);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB5;

LAB7:    xsi_set_current_line(89, ng0);
    t1 = ((WORK_P_3849459504) + 1768U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5536);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(90, ng0);
    t1 = ((WORK_P_3849459504) + 1768U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5600);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB5;

LAB8:    xsi_set_current_line(92, ng0);
    t1 = ((WORK_P_3849459504) + 1888U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5536);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(93, ng0);
    t1 = ((WORK_P_3849459504) + 1888U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5600);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB5;

LAB9:    xsi_set_current_line(95, ng0);
    t1 = ((WORK_P_3849459504) + 2008U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5536);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(96, ng0);
    t1 = ((WORK_P_3849459504) + 2008U);
    t2 = *((char **)t1);
    t7 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t17, t7, 32);
    t5 = (t0 + 5600);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB5;

LAB15:;
LAB16:    xsi_set_current_line(105, ng0);
    t5 = (t0 + 3432U);
    t6 = *((char **)t5);
    t7 = *((int *)t6);
    t28 = (t7 == 4);
    if (t28 != 0)
        goto LAB21;

LAB23:
LAB22:    goto LAB3;

LAB18:    t1 = (t0 + 1312U);
    t27 = xsi_signal_has_event(t1);
    t3 = t27;
    goto LAB20;

LAB21:    xsi_set_current_line(106, ng0);
    t5 = (t0 + 3272U);
    t8 = *((char **)t5);
    t5 = (t0 + 5536);
    t9 = (t5 + 56U);
    t11 = *((char **)t9);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    memcpy(t14, t8, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 3272U);
    t2 = *((char **)t1);
    t1 = (t0 + 5664);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB22;

}

static void work_a_1955880404_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    int t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t9 = (t4 == (unsigned char)3);
    if (t9 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 5456);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(125, ng0);
    t5 = (t0 + 3432U);
    t6 = *((char **)t5);
    t11 = *((int *)t6);
    if (t11 == 0)
        goto LAB11;

LAB18:    if (t11 == 1)
        goto LAB12;

LAB19:    if (t11 == 2)
        goto LAB13;

LAB20:    if (t11 == 3)
        goto LAB14;

LAB21:    if (t11 == 4)
        goto LAB15;

LAB22:    if (t11 == 5)
        goto LAB16;

LAB23:
LAB17:    xsi_set_current_line(175, ng0);
    t1 = (t0 + 10196);
    xsi_report(t1, 21U, 0);

LAB10:    goto LAB3;

LAB7:    t1 = (t0 + 1312U);
    t10 = xsi_signal_has_event(t1);
    t3 = t10;
    goto LAB9;

LAB11:    xsi_set_current_line(129, ng0);
    t5 = (t0 + 5856);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t12 = (t8 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(135, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 5920);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(137, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB26:    goto LAB10;

LAB12:    xsi_set_current_line(142, ng0);
    t1 = (t0 + 5920);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(143, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 2;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB13:    xsi_set_current_line(147, ng0);
    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(150, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 2;
    xsi_driver_first_trans_fast(t1);

LAB29:    goto LAB10;

LAB14:    xsi_set_current_line(156, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 4;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB15:    xsi_set_current_line(160, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(163, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB31;

LAB33:    xsi_set_current_line(166, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 4;
    xsi_driver_first_trans_fast(t1);

LAB32:    goto LAB10;

LAB16:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(172, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB24:;
LAB25:    xsi_set_current_line(131, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 5920);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(133, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB26;

LAB28:    xsi_set_current_line(148, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 3;
    xsi_driver_first_trans_fast(t1);
    goto LAB29;

LAB31:    xsi_set_current_line(164, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 5;
    xsi_driver_first_trans_fast(t1);
    goto LAB32;

}


extern void work_a_1955880404_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1955880404_3212880686_p_0,(void *)work_a_1955880404_3212880686_p_1};
	xsi_register_didat("work_a_1955880404_3212880686", "isim/control_fsm_tb_isim_beh.exe.sim/work/a_1955880404_3212880686.didat");
	xsi_register_executes(pe);
}
