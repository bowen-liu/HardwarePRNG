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
static const char *ng0 = "C:/Users/bowenliu/Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/control_fsm.vhd";
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

LAB0:    xsi_set_current_line(81, ng0);
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
LAB2:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 1032U);
    t5 = *((char **)t1);
    t1 = (t0 + 10052);
    t7 = xsi_mem_cmp(t1, t5, 2U);
    if (t7 == 1)
        goto LAB6;

LAB11:    t8 = (t0 + 10054);
    t10 = xsi_mem_cmp(t8, t5, 2U);
    if (t10 == 1)
        goto LAB7;

LAB12:    t11 = (t0 + 10056);
    t13 = xsi_mem_cmp(t11, t5, 2U);
    if (t13 == 1)
        goto LAB8;

LAB13:    t14 = (t0 + 10058);
    t16 = xsi_mem_cmp(t14, t5, 2U);
    if (t16 == 1)
        goto LAB9;

LAB14:
LAB10:    xsi_set_current_line(96, ng0);
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
    xsi_set_current_line(97, ng0);
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

LAB6:    xsi_set_current_line(84, ng0);
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
    xsi_set_current_line(85, ng0);
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

LAB7:    xsi_set_current_line(87, ng0);
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
    xsi_set_current_line(88, ng0);
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

LAB8:    xsi_set_current_line(90, ng0);
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
    xsi_set_current_line(91, ng0);
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

LAB9:    xsi_set_current_line(93, ng0);
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
    xsi_set_current_line(94, ng0);
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
LAB16:    xsi_set_current_line(102, ng0);
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

LAB21:    xsi_set_current_line(103, ng0);
    t5 = (t0 + 3272U);
    t8 = *((char **)t5);
    t5 = (t0 + 5536);
    t9 = (t5 + 56U);
    t11 = *((char **)t9);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    memcpy(t14, t8, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(104, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB24;

LAB26:
LAB25:    goto LAB22;

LAB24:    xsi_set_current_line(105, ng0);
    t1 = (t0 + 3272U);
    t5 = *((char **)t1);
    t1 = (t0 + 5664);
    t6 = (t1 + 56U);
    t8 = *((char **)t6);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memcpy(t11, t5, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB25;

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
    unsigned char t12;
    unsigned char t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(117, ng0);
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
LAB2:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(119, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(124, ng0);
    t5 = (t0 + 3432U);
    t6 = *((char **)t5);
    t11 = *((int *)t6);
    if (t11 == 0)
        goto LAB11;

LAB19:    if (t11 == 1)
        goto LAB12;

LAB20:    if (t11 == 2)
        goto LAB13;

LAB21:    if (t11 == 3)
        goto LAB14;

LAB22:    if (t11 == 4)
        goto LAB15;

LAB23:    if (t11 == 5)
        goto LAB16;

LAB24:    if (t11 == 6)
        goto LAB17;

LAB25:
LAB18:    xsi_set_current_line(178, ng0);
    t1 = (t0 + 10060);
    xsi_report(t1, 21U, 0);

LAB10:    goto LAB3;

LAB7:    t1 = (t0 + 1312U);
    t10 = xsi_signal_has_event(t1);
    t3 = t10;
    goto LAB9;

LAB11:    xsi_set_current_line(128, ng0);
    t5 = (t0 + 1512U);
    t7 = *((char **)t5);
    t12 = *((unsigned char *)t7);
    t13 = (t12 == (unsigned char)3);
    if (t13 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 5920);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(135, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(137, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB28:    goto LAB10;

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
        goto LAB30;

LAB32:    xsi_set_current_line(150, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 2;
    xsi_driver_first_trans_fast(t1);

LAB31:    goto LAB10;

LAB14:    xsi_set_current_line(155, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 4;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB15:    xsi_set_current_line(159, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 5;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB16:    xsi_set_current_line(163, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(166, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB33;

LAB35:    xsi_set_current_line(169, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 5;
    xsi_driver_first_trans_fast(t1);

LAB34:    goto LAB10;

LAB17:    xsi_set_current_line(174, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(175, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB10;

LAB26:;
LAB27:    xsi_set_current_line(129, ng0);
    t5 = (t0 + 5920);
    t8 = (t5 + 56U);
    t14 = *((char **)t8);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 5728);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = 1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(131, ng0);
    t1 = (t0 + 5792);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 5856);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB28;

LAB30:    xsi_set_current_line(148, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 3;
    xsi_driver_first_trans_fast(t1);
    goto LAB31;

LAB33:    xsi_set_current_line(167, ng0);
    t1 = (t0 + 5728);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 6;
    xsi_driver_first_trans_fast(t1);
    goto LAB34;

}


extern void work_a_1955880404_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1955880404_3212880686_p_0,(void *)work_a_1955880404_3212880686_p_1};
	xsi_register_didat("work_a_1955880404_3212880686", "isim/prng_tl_tb_isim_beh.exe.sim/work/a_1955880404_3212880686.didat");
	xsi_register_executes(pe);
}
