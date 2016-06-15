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

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
extern char *IEEE_P_2592010699;
static const char *ng1 = "Function mu_multiply ended without a return statement";
static const char *ng2 = "C:/Users/OWner/Documents/ceng441/UvicSummer2016Ceng441/PRNG_VHDL/PRNG/divide_2.vhd";
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
unsigned char ieee_p_1242562249_sub_2479218856_1035706684(char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2479290730_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_2720006528_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_3840967975_1035706684(char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_4081755647_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_4230814580_1035706684(char *, char *, char *, char *, int );
char *ieee_p_2592010699_sub_1837678034_503743352(char *, char *, char *, char *);


int work_a_3147582278_3212880686_sub_3659340636_3057020925(char *t1, char *t2, char *t3)
{
    char t5[24];
    int t0;
    char *t6;
    unsigned char t7;
    char *t8;
    int t9;
    int t10;
    char *t11;
    int t12;
    char *t13;
    int t14;
    int t15;
    unsigned int t16;
    char *t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned char t22;
    unsigned char t23;

LAB0:    t6 = (t5 + 4U);
    t7 = (t2 != 0);
    if (t7 == 1)
        goto LAB3;

LAB2:    t8 = (t5 + 12U);
    *((char **)t8) = t3;
    t9 = 31;
    t10 = 0;

LAB4:    if (t9 >= t10)
        goto LAB5;

LAB7:    t0 = 0;

LAB1:    return t0;
LAB3:    *((char **)t6) = t2;
    goto LAB2;

LAB5:    t11 = (t3 + 0U);
    t12 = *((int *)t11);
    t13 = (t3 + 8U);
    t14 = *((int *)t13);
    t15 = (t9 - t12);
    t16 = (t15 * t14);
    t17 = (t3 + 4U);
    t18 = *((int *)t17);
    xsi_vhdl_check_range_of_index(t12, t18, t14, t9);
    t19 = (1U * t16);
    t20 = (0 + t19);
    t21 = (t2 + t20);
    t22 = *((unsigned char *)t21);
    t23 = (t22 == (unsigned char)3);
    if (t23 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    if (t9 == t10)
        goto LAB7;

LAB12:    t12 = (t9 + -1);
    t9 = t12;
    goto LAB4;

LAB8:    t0 = t9;
    goto LAB1;

LAB11:    goto LAB9;

LAB13:;
}

int work_a_3147582278_3212880686_sub_4177263305_3057020925(char *t1, char *t2, char *t3)
{
    char t4[128];
    char t5[24];
    char t6[16];
    char t13[32];
    char t20[16];
    int t0;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t25;
    int t26;
    int t27;
    int t28;
    int t29;
    int t30;
    unsigned int t31;
    unsigned char t32;

LAB0:    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 31;
    t8 = (t7 + 4U);
    *((int *)t8) = 0;
    t8 = (t7 + 8U);
    *((int *)t8) = -1;
    t9 = (0 - 31);
    t10 = (t9 * -1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    t8 = (t4 + 4U);
    t11 = ((IEEE_P_2592010699) + 4024);
    t12 = (t8 + 88U);
    *((char **)t12) = t11;
    t14 = (t8 + 56U);
    *((char **)t14) = t13;
    xsi_type_set_default_value(t11, t13, t6);
    t15 = (t8 + 64U);
    *((char **)t15) = t6;
    t16 = (t8 + 80U);
    *((unsigned int *)t16) = 32U;
    t17 = (t5 + 4U);
    t18 = (t2 != 0);
    if (t18 == 1)
        goto LAB3;

LAB2:    t19 = (t5 + 12U);
    *((char **)t19) = t3;
    t21 = ieee_p_2592010699_sub_1837678034_503743352(IEEE_P_2592010699, t20, t2, t3);
    t22 = (t8 + 56U);
    t23 = *((char **)t22);
    t22 = (t23 + 0);
    t24 = (t20 + 12U);
    t10 = *((unsigned int *)t24);
    t25 = (1U * t10);
    memcpy(t22, t21, t25);
    t9 = 31;
    t26 = 0;

LAB4:    if (t9 >= t26)
        goto LAB5;

LAB7:    t0 = 0;

LAB1:    return t0;
LAB3:    *((char **)t17) = t2;
    goto LAB2;

LAB5:    t7 = (t8 + 56U);
    t11 = *((char **)t7);
    t7 = (t6 + 0U);
    t27 = *((int *)t7);
    t12 = (t6 + 8U);
    t28 = *((int *)t12);
    t29 = (t9 - t27);
    t10 = (t29 * t28);
    t14 = (t6 + 4U);
    t30 = *((int *)t14);
    xsi_vhdl_check_range_of_index(t27, t30, t28, t9);
    t25 = (1U * t10);
    t31 = (0 + t25);
    t15 = (t11 + t31);
    t18 = *((unsigned char *)t15);
    t32 = (t18 == (unsigned char)3);
    if (t32 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    if (t9 == t26)
        goto LAB7;

LAB12:    t27 = (t9 + -1);
    t9 = t27;
    goto LAB4;

LAB8:    t0 = t9;
    goto LAB1;

LAB11:    goto LAB9;

LAB13:;
}

int work_a_3147582278_3212880686_sub_1151219312_3057020925(char *t1, int t2, int t3)
{
    char t5[16];
    int t0;
    char *t6;
    char *t7;
    int t8;
    int t9;
    char *t10;

LAB0:    t6 = (t5 + 4U);
    *((int *)t6) = t2;
    t7 = (t5 + 8U);
    *((int *)t7) = t3;
    t8 = (-(1));
    if (t3 == t8)
        goto LAB3;

LAB6:    if (t3 == 1)
        goto LAB4;

LAB7:
LAB5:    t10 = (t1 + 18012);
    xsi_report(t10, 34U, 0);
    t0 = t2;

LAB1:    return t0;
LAB2:    xsi_error(ng1);
    t0 = 0;
    goto LAB1;

LAB3:    t9 = (0 - t2);
    t0 = t9;
    goto LAB1;

LAB4:    t0 = t2;
    goto LAB1;

LAB8:;
LAB9:    goto LAB2;

LAB10:    goto LAB2;

LAB11:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(95, ng2);

LAB3:    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t1 = (t0 + 10584);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 10296);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(96, ng2);

LAB3:    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t1 = (t0 + 10648);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 10312);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(97, ng2);

LAB3:    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    t1 = (t0 + 10712);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 10328);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_3(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(98, ng2);

LAB3:    t2 = (t0 + 4072U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 10776);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 10344);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_4(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(99, ng2);

LAB3:    t2 = (t0 + 4232U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 10840);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 10360);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_5(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(100, ng2);

LAB3:    t2 = (t0 + 4392U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 10904);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 10376);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_6(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(101, ng2);

LAB3:    t2 = (t0 + 4552U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 10968);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 10392);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(102, ng2);

LAB3:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    t1 = (t0 + 11032);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 10408);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_8(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    unsigned char t9;
    char *t10;
    char *t11;
    int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(108, ng2);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 10424);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(110, ng2);
    t7 = (t0 + 3592U);
    t8 = *((char **)t7);
    t7 = (t0 + 17656U);
    t9 = ieee_p_1242562249_sub_2479218856_1035706684(IEEE_P_1242562249, t8, t7, 0);
    if (t9 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 3592U);
    t3 = *((char **)t2);
    t2 = (t0 + 17656U);
    t1 = ieee_p_1242562249_sub_2479290730_1035706684(IEEE_P_1242562249, t3, t2, 0);
    if (t1 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(115, ng2);
    t2 = (t0 + 11096);
    t3 = (t2 + 56U);
    t7 = *((char **)t3);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t2);

LAB9:    goto LAB3;

LAB5:    t2 = (t0 + 1632U);
    t6 = xsi_signal_has_event(t2);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(111, ng2);
    t10 = (t0 + 3592U);
    t11 = *((char **)t10);
    t10 = (t0 + 17656U);
    t12 = work_a_3147582278_3212880686_sub_4177263305_3057020925(t0, t11, t10);
    t13 = (t0 + 11096);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((int *)t17) = t12;
    xsi_driver_first_trans_fast(t13);
    goto LAB9;

LAB11:    xsi_set_current_line(113, ng2);
    t7 = (t0 + 3592U);
    t8 = *((char **)t7);
    t7 = (t0 + 17656U);
    t12 = work_a_3147582278_3212880686_sub_3659340636_3057020925(t0, t8, t7);
    t10 = (t0 + 11096);
    t11 = (t10 + 56U);
    t13 = *((char **)t11);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((int *)t15) = t12;
    xsi_driver_first_trans_fast(t10);
    goto LAB9;

}

static void work_a_3147582278_3212880686_p_9(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(125, ng2);
    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t1 = (t0 + 17672U);
    t3 = work_a_3147582278_3212880686_sub_3659340636_3057020925(t0, t2, t1);
    t4 = (t0 + 11160);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t3;
    xsi_driver_first_trans_fast(t4);
    t1 = (t0 + 10440);
    *((int *)t1) = 1;

LAB1:    return;
}

static void work_a_3147582278_3212880686_p_10(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    int t5;
    int t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    xsi_set_current_line(135, ng2);
    t1 = (t0 + 4232U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t1 = (t0 + 4072U);
    t4 = *((char **)t1);
    t5 = *((int *)t4);
    t6 = (t3 - t5);
    t1 = (t0 + 5288U);
    t7 = *((char **)t1);
    t1 = (t7 + 0);
    *((int *)t1) = t6;
    xsi_set_current_line(138, ng2);
    t1 = (t0 + 5288U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t9 = (t3 > 0);
    if (t9 == 1)
        goto LAB5;

LAB6:    t8 = (unsigned char)0;

LAB7:    if (t8 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10456);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(139, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t7 = t1;
    memset(t7, (unsigned char)2, 32U);
    t11 = (t0 + 5408U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    memcpy(t11, t1, 32U);
    xsi_set_current_line(140, ng2);
    t1 = (t0 + 5408U);
    t2 = *((char **)t1);
    t1 = (t0 + 5288U);
    t4 = *((char **)t1);
    t3 = *((int *)t4);
    t5 = (t3 - 31);
    t13 = (t5 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t3);
    t14 = (1U * t13);
    t15 = (0 + t14);
    t1 = (t2 + t15);
    *((unsigned char *)t1) = (unsigned char)3;
    xsi_set_current_line(141, ng2);
    t1 = (t0 + 5408U);
    t2 = *((char **)t1);
    t1 = (t0 + 11224);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(142, ng2);
    t1 = (t0 + 5288U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t1 = (t0 + 11288);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = t3;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    t1 = (t0 + 5288U);
    t4 = *((char **)t1);
    t5 = *((int *)t4);
    t6 = (32 - 1);
    t10 = (t5 < t6);
    t8 = t10;
    goto LAB7;

}

static void work_a_3147582278_3212880686_p_11(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;

LAB0:    xsi_set_current_line(149, ng2);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 10472);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(150, ng2);
    t7 = (t0 + 3592U);
    t8 = *((char **)t7);
    t7 = (t0 + 17656U);
    t9 = ieee_p_1242562249_sub_3840967975_1035706684(IEEE_P_1242562249, t8, t7, 0);
    if (t9 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(153, ng2);
    t15 = (-(1));
    t2 = (t0 + 11352);
    t3 = (t2 + 56U);
    t7 = *((char **)t3);
    t8 = (t7 + 56U);
    t10 = *((char **)t8);
    *((int *)t10) = t15;
    xsi_driver_first_trans_fast(t2);

LAB9:    goto LAB3;

LAB5:    t2 = (t0 + 1632U);
    t6 = xsi_signal_has_event(t2);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(151, ng2);
    t10 = (t0 + 11352);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((int *)t14) = 1;
    xsi_driver_first_trans_fast(t10);
    goto LAB9;

}

static void work_a_3147582278_3212880686_p_12(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;

LAB0:    xsi_set_current_line(161, ng2);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 10488);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(162, ng2);
    t7 = (t0 + 3592U);
    t8 = *((char **)t7);
    t7 = (t0 + 17656U);
    t9 = (t0 + 3752U);
    t10 = *((char **)t9);
    t9 = (t0 + 17672U);
    t11 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t8, t7, t10, t9);
    if (t11 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(165, ng2);
    t17 = (-(1));
    t2 = (t0 + 11416);
    t3 = (t2 + 56U);
    t7 = *((char **)t3);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t17;
    xsi_driver_first_trans_fast(t2);

LAB9:    goto LAB3;

LAB5:    t2 = (t0 + 1632U);
    t6 = xsi_signal_has_event(t2);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(163, ng2);
    t12 = (t0 + 11416);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((int *)t16) = 1;
    xsi_driver_first_trans_fast(t12);
    goto LAB9;

}

static void work_a_3147582278_3212880686_p_13(char *t0)
{
    char t18[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    int t16;
    int t17;
    int t19;
    int t20;
    int t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(177, ng2);
    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t4 = *((unsigned char *)t2);
    t11 = (t4 == (unsigned char)3);
    if (t11 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 10504);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(179, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t5 = t1;
    memset(t5, (unsigned char)2, 32U);
    t6 = (t0 + 11480);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(180, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11544);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(182, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(183, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11672);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(184, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11736);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(185, ng2);
    t1 = (t0 + 11800);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(190, ng2);
    t5 = (t0 + 1992U);
    t6 = *((char **)t5);
    t13 = *((unsigned char *)t6);
    t14 = (t13 == (unsigned char)3);
    if (t14 != 0)
        goto LAB10;

LAB12:    t1 = (t0 + 4232U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t1 = (t0 + 4072U);
    t5 = *((char **)t1);
    t17 = *((int *)t5);
    t3 = (t16 > t17);
    if (t3 != 0)
        goto LAB13;

LAB14:    xsi_set_current_line(216, ng2);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t1 = (t0 + 17656U);
    t4 = ieee_p_1242562249_sub_3840967975_1035706684(IEEE_P_1242562249, t2, t1, 0);
    if (t4 == 1)
        goto LAB18;

LAB19:    t3 = (unsigned char)0;

LAB20:    t12 = (!(t3));
    if (t12 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(229, ng2);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t1 = (t0 + 11736);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(230, ng2);
    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    t1 = (t0 + 11672);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(231, ng2);
    t1 = (t0 + 11800);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);

LAB11:    goto LAB3;

LAB7:    t1 = (t0 + 1632U);
    t12 = xsi_signal_has_event(t1);
    t3 = t12;
    goto LAB9;

LAB10:    xsi_set_current_line(191, ng2);
    t5 = (t0 + 1032U);
    t7 = *((char **)t5);
    t5 = (t0 + 11480);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t15 = *((char **)t10);
    memcpy(t15, t7, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(192, ng2);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 11544);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(195, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(196, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11672);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(197, ng2);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 11736);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(198, ng2);
    t1 = (t0 + 11800);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB11;

LAB13:    xsi_set_current_line(205, ng2);
    t1 = (t0 + 3752U);
    t6 = *((char **)t1);
    t1 = (t0 + 17672U);
    t7 = (t0 + 4872U);
    t8 = *((char **)t7);
    t19 = *((int *)t8);
    t7 = ieee_p_1242562249_sub_4230814580_1035706684(IEEE_P_1242562249, t18, t6, t1, t19);
    t20 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t7, t18);
    t9 = (t0 + 5528U);
    t10 = *((char **)t9);
    t9 = (t10 + 0);
    *((int *)t9) = t20;
    xsi_set_current_line(206, ng2);
    t1 = (t0 + 3592U);
    t2 = *((char **)t1);
    t1 = (t0 + 17656U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t1);
    t5 = (t0 + 5528U);
    t6 = *((char **)t5);
    t17 = *((int *)t6);
    t5 = (t0 + 4392U);
    t7 = *((char **)t5);
    t19 = *((int *)t7);
    t20 = work_a_3147582278_3212880686_sub_1151219312_3057020925(t0, t17, t19);
    t21 = (t16 - t20);
    t5 = (t0 + 5648U);
    t8 = *((char **)t5);
    t5 = (t8 + 0);
    *((int *)t5) = t21;
    xsi_set_current_line(207, ng2);
    t1 = (t0 + 5648U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t5 = (t0 + 11480);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(210, ng2);
    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    t1 = (t0 + 17688U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t1);
    t5 = (t0 + 4712U);
    t6 = *((char **)t5);
    t5 = (t0 + 17704U);
    t17 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t6, t5);
    t7 = (t0 + 4392U);
    t8 = *((char **)t7);
    t19 = *((int *)t8);
    t20 = work_a_3147582278_3212880686_sub_1151219312_3057020925(t0, t17, t19);
    t21 = (t16 + t20);
    t7 = (t0 + 5768U);
    t9 = *((char **)t7);
    t7 = (t9 + 0);
    *((int *)t7) = t21;
    xsi_set_current_line(211, ng2);
    t1 = (t0 + 5768U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t5 = (t0 + 11608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    goto LAB11;

LAB15:    xsi_set_current_line(219, ng2);
    t9 = (t0 + 3592U);
    t10 = *((char **)t9);
    t9 = (t0 + 17656U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t10, t9);
    t15 = (t0 + 3752U);
    t22 = *((char **)t15);
    t15 = (t0 + 17672U);
    t17 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t22, t15);
    t23 = (t0 + 4552U);
    t24 = *((char **)t23);
    t19 = *((int *)t24);
    t20 = work_a_3147582278_3212880686_sub_1151219312_3057020925(t0, t17, t19);
    t21 = (t16 - t20);
    t23 = (t0 + 5528U);
    t25 = *((char **)t23);
    t23 = (t25 + 0);
    *((int *)t23) = t21;
    xsi_set_current_line(220, ng2);
    t1 = (t0 + 5528U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t5 = (t0 + 11480);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(223, ng2);
    t1 = (t0 + 3912U);
    t2 = *((char **)t1);
    t1 = (t0 + 17688U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t1);
    t5 = (t0 + 4552U);
    t6 = *((char **)t5);
    t17 = *((int *)t6);
    t19 = (t16 + t17);
    t5 = (t0 + 5648U);
    t7 = *((char **)t5);
    t5 = (t7 + 0);
    *((int *)t5) = t19;
    xsi_set_current_line(224, ng2);
    t1 = (t0 + 5648U);
    t2 = *((char **)t1);
    t16 = *((int *)t2);
    t1 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t5 = (t0 + 11608);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t5);
    goto LAB16;

LAB18:    t5 = (t0 + 3592U);
    t6 = *((char **)t5);
    t5 = (t0 + 17656U);
    t7 = (t0 + 3752U);
    t8 = *((char **)t7);
    t7 = (t0 + 17672U);
    t11 = ieee_p_1242562249_sub_2720006528_1035706684(IEEE_P_1242562249, t6, t5, t8, t7);
    t3 = t11;
    goto LAB20;

}


extern void work_a_3147582278_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3147582278_3212880686_p_0,(void *)work_a_3147582278_3212880686_p_1,(void *)work_a_3147582278_3212880686_p_2,(void *)work_a_3147582278_3212880686_p_3,(void *)work_a_3147582278_3212880686_p_4,(void *)work_a_3147582278_3212880686_p_5,(void *)work_a_3147582278_3212880686_p_6,(void *)work_a_3147582278_3212880686_p_7,(void *)work_a_3147582278_3212880686_p_8,(void *)work_a_3147582278_3212880686_p_9,(void *)work_a_3147582278_3212880686_p_10,(void *)work_a_3147582278_3212880686_p_11,(void *)work_a_3147582278_3212880686_p_12,(void *)work_a_3147582278_3212880686_p_13};
	static char *se[] = {(void *)work_a_3147582278_3212880686_sub_3659340636_3057020925,(void *)work_a_3147582278_3212880686_sub_4177263305_3057020925,(void *)work_a_3147582278_3212880686_sub_1151219312_3057020925};
	xsi_register_didat("work_a_3147582278_3212880686", "isim/divider_test2tb_isim_beh.exe.sim/work/a_3147582278_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
