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
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;
extern char *IEEE_P_2592010699;
static const char *ng3 = "C:/Users/OWner/Documents/ceng441/UvicSummer2016Ceng441/PRNG_VHDL/PRNG/divide_2.vhd";

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
unsigned char ieee_p_1242562249_sub_2479218856_1035706684(char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2479290730_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_2720006528_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_3840967975_1035706684(char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_4081755647_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_1837678034_503743352(char *, char *, char *, char *);


int work_a_3147582278_3212880686_sub_3659340636_3057020925(char *t1, char *t2, char *t3)
{
    char t5[24];
    char t26[16];
    char t32[16];
    char t34[16];
    char t41[16];
    char t43[16];
    char t47[16];
    char t51[16];
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
    char *t24;
    char *t27;
    int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t33;
    char *t35;
    char *t36;
    int t37;
    unsigned int t38;
    char *t40;
    char *t42;
    char *t44;
    char *t45;
    int t46;
    char *t48;
    char *t49;
    char *t50;
    char *t52;
    char *t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;

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

LAB8:    t24 = (t1 + 21128);
    t27 = ((STD_STANDARD) + 384);
    t28 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t3);
    t29 = xsi_int_to_mem(t28);
    t30 = xsi_string_variable_get_image(t26, t27, t29);
    t33 = ((STD_STANDARD) + 1008);
    t35 = (t34 + 0U);
    t36 = (t35 + 0U);
    *((int *)t36) = 1;
    t36 = (t35 + 4U);
    *((int *)t36) = 11;
    t36 = (t35 + 8U);
    *((int *)t36) = 1;
    t37 = (11 - 1);
    t38 = (t37 * 1);
    t38 = (t38 + 1);
    t36 = (t35 + 12U);
    *((unsigned int *)t36) = t38;
    t31 = xsi_base_array_concat(t31, t32, t33, (char)97, t24, t34, (char)97, t30, t26, (char)101);
    t36 = (t1 + 21139);
    t42 = ((STD_STANDARD) + 1008);
    t44 = (t43 + 0U);
    t45 = (t44 + 0U);
    *((int *)t45) = 1;
    t45 = (t44 + 4U);
    *((int *)t45) = 3;
    t45 = (t44 + 8U);
    *((int *)t45) = 1;
    t46 = (3 - 1);
    t38 = (t46 * 1);
    t38 = (t38 + 1);
    t45 = (t44 + 12U);
    *((unsigned int *)t45) = t38;
    t40 = xsi_base_array_concat(t40, t41, t42, (char)97, t31, t32, (char)97, t36, t43, (char)101);
    t45 = ((STD_STANDARD) + 384);
    t48 = xsi_int_to_mem(t9);
    t49 = xsi_string_variable_get_image(t47, t45, t48);
    t52 = ((STD_STANDARD) + 1008);
    t50 = xsi_base_array_concat(t50, t51, t52, (char)97, t40, t41, (char)97, t49, t47, (char)101);
    t53 = (t26 + 12U);
    t38 = *((unsigned int *)t53);
    t54 = (11U + t38);
    t55 = (t54 + 3U);
    t56 = (t47 + 12U);
    t57 = *((unsigned int *)t56);
    t58 = (t55 + t57);
    xsi_report(t50, t58, 0);
    t0 = t9;
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
    char t35[16];
    char t37[16];
    char t44[16];
    char t46[16];
    char t50[16];
    char t54[16];
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
    int t33;
    char *t34;
    char *t36;
    char *t38;
    char *t39;
    int t40;
    unsigned int t41;
    char *t43;
    char *t45;
    char *t47;
    char *t48;
    int t49;
    char *t51;
    char *t52;
    char *t53;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;

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

LAB8:    t16 = (t1 + 21142);
    t22 = ((STD_STANDARD) + 384);
    t33 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t3);
    t23 = xsi_int_to_mem(t33);
    t24 = xsi_string_variable_get_image(t20, t22, t23);
    t36 = ((STD_STANDARD) + 1008);
    t38 = (t37 + 0U);
    t39 = (t38 + 0U);
    *((int *)t39) = 1;
    t39 = (t38 + 4U);
    *((int *)t39) = 11;
    t39 = (t38 + 8U);
    *((int *)t39) = 1;
    t40 = (11 - 1);
    t41 = (t40 * 1);
    t41 = (t41 + 1);
    t39 = (t38 + 12U);
    *((unsigned int *)t39) = t41;
    t34 = xsi_base_array_concat(t34, t35, t36, (char)97, t16, t37, (char)97, t24, t20, (char)101);
    t39 = (t1 + 21153);
    t45 = ((STD_STANDARD) + 1008);
    t47 = (t46 + 0U);
    t48 = (t47 + 0U);
    *((int *)t48) = 1;
    t48 = (t47 + 4U);
    *((int *)t48) = 3;
    t48 = (t47 + 8U);
    *((int *)t48) = 1;
    t49 = (3 - 1);
    t41 = (t49 * 1);
    t41 = (t41 + 1);
    t48 = (t47 + 12U);
    *((unsigned int *)t48) = t41;
    t43 = xsi_base_array_concat(t43, t44, t45, (char)97, t34, t35, (char)97, t39, t46, (char)101);
    t48 = ((STD_STANDARD) + 384);
    t51 = xsi_int_to_mem(t9);
    t52 = xsi_string_variable_get_image(t50, t48, t51);
    t55 = ((STD_STANDARD) + 1008);
    t53 = xsi_base_array_concat(t53, t54, t55, (char)97, t43, t44, (char)97, t52, t50, (char)101);
    t56 = (t20 + 12U);
    t41 = *((unsigned int *)t56);
    t57 = (11U + t41);
    t58 = (t57 + 3U);
    t59 = (t50 + 12U);
    t60 = *((unsigned int *)t59);
    t61 = (t58 + t60);
    xsi_report(t53, t61, 0);
    t0 = t9;
    goto LAB1;

LAB11:    goto LAB9;

LAB13:;
}

static void work_a_3147582278_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(86, ng3);

LAB3:    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 12304);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 12016);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(87, ng3);

LAB3:    t1 = (t0 + 5032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 12368);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 12032);
    *((int *)t8) = 1;

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

LAB0:    xsi_set_current_line(88, ng3);

LAB3:    t1 = (t0 + 4552U);
    t2 = *((char **)t1);
    t1 = (t0 + 12432);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 12048);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(89, ng3);

LAB3:    t1 = (t0 + 4712U);
    t2 = *((char **)t1);
    t1 = (t0 + 12496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 12064);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(90, ng3);

LAB3:    t1 = (t0 + 5192U);
    t2 = *((char **)t1);
    t1 = (t0 + 12560);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 12080);
    *((int *)t7) = 1;

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

LAB0:    xsi_set_current_line(91, ng3);

LAB3:    t2 = (t0 + 5352U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 12624);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 12096);
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

LAB0:    xsi_set_current_line(92, ng3);

LAB3:    t2 = (t0 + 5512U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 12688);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 12112);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_7(char *t0)
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

LAB0:    xsi_set_current_line(93, ng3);

LAB3:    t2 = (t0 + 5672U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 12752);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 12128);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_8(char *t0)
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

LAB0:    xsi_set_current_line(94, ng3);

LAB3:    t2 = (t0 + 5832U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t4, 32);
    t5 = (t0 + 12816);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast_port(t5);

LAB2:    t10 = (t0 + 12144);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_9(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(95, ng3);

LAB3:    t1 = (t0 + 5992U);
    t2 = *((char **)t1);
    t1 = (t0 + 12880);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 12160);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3147582278_3212880686_p_10(char *t0)
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
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;

LAB0:    xsi_set_current_line(104, ng3);
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
LAB3:    t2 = (t0 + 12176);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(108, ng3);
    t7 = (t0 + 4552U);
    t8 = *((char **)t7);
    t7 = (t0 + 20628U);
    t9 = ieee_p_1242562249_sub_2479218856_1035706684(IEEE_P_1242562249, t8, t7, 0);
    if (t9 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 4552U);
    t3 = *((char **)t2);
    t2 = (t0 + 20628U);
    t1 = ieee_p_1242562249_sub_2479290730_1035706684(IEEE_P_1242562249, t3, t2, 0);
    if (t1 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(113, ng3);
    t2 = (t0 + 6648U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB9:    xsi_set_current_line(116, ng3);
    t2 = (t0 + 6648U);
    t3 = *((char **)t2);
    t12 = *((int *)t3);
    t2 = (t0 + 12944);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = t12;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(119, ng3);
    t2 = (t0 + 6648U);
    t3 = *((char **)t2);
    t12 = *((int *)t3);
    t2 = (t0 + 5352U);
    t7 = *((char **)t2);
    t15 = *((int *)t7);
    t16 = (t12 - t15);
    t2 = (t0 + 6408U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t16;
    xsi_set_current_line(120, ng3);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t3 = t2;
    memset(t3, (unsigned char)2, 32U);
    t7 = (t0 + 6528U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t2, 32U);
    xsi_set_current_line(122, ng3);
    t2 = (t0 + 6408U);
    t3 = *((char **)t2);
    t12 = *((int *)t3);
    t1 = (t12 > 0);
    if (t1 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(125, ng3);
    t2 = (t0 + 21156);
    xsi_report(t2, 25U, (unsigned char)1);

LAB14:    xsi_set_current_line(128, ng3);
    t2 = (t0 + 6528U);
    t3 = *((char **)t2);
    t2 = (t0 + 13008);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 32U);
    xsi_driver_first_trans_fast(t2);
    goto LAB3;

LAB5:    t2 = (t0 + 1632U);
    t6 = xsi_signal_has_event(t2);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(109, ng3);
    t10 = (t0 + 4552U);
    t11 = *((char **)t10);
    t10 = (t0 + 20628U);
    t12 = work_a_3147582278_3212880686_sub_4177263305_3057020925(t0, t11, t10);
    t13 = (t0 + 6648U);
    t14 = *((char **)t13);
    t13 = (t14 + 0);
    *((int *)t13) = t12;
    goto LAB9;

LAB11:    xsi_set_current_line(111, ng3);
    t7 = (t0 + 4552U);
    t8 = *((char **)t7);
    t7 = (t0 + 20628U);
    t12 = work_a_3147582278_3212880686_sub_3659340636_3057020925(t0, t8, t7);
    t10 = (t0 + 6648U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    *((int *)t10) = t12;
    goto LAB9;

LAB13:    xsi_set_current_line(123, ng3);
    t2 = (t0 + 6528U);
    t7 = *((char **)t2);
    t2 = (t0 + 6408U);
    t8 = *((char **)t2);
    t15 = *((int *)t8);
    t16 = (t15 - 31);
    t17 = (t16 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t15);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t2 = (t7 + t19);
    *((unsigned char *)t2) = (unsigned char)3;
    goto LAB14;

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

LAB0:    xsi_set_current_line(136, ng3);
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
LAB3:    t2 = (t0 + 12192);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(137, ng3);
    t7 = (t0 + 4552U);
    t8 = *((char **)t7);
    t7 = (t0 + 20628U);
    t9 = ieee_p_1242562249_sub_3840967975_1035706684(IEEE_P_1242562249, t8, t7, 0);
    if (t9 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(140, ng3);
    t15 = (-(1));
    t2 = (t0 + 13072);
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

LAB8:    xsi_set_current_line(138, ng3);
    t10 = (t0 + 13072);
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

LAB0:    xsi_set_current_line(151, ng3);
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
LAB3:    t2 = (t0 + 12208);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(152, ng3);
    t7 = (t0 + 4552U);
    t8 = *((char **)t7);
    t7 = (t0 + 20628U);
    t9 = (t0 + 4712U);
    t10 = *((char **)t9);
    t9 = (t0 + 20644U);
    t11 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t8, t7, t10, t9);
    if (t11 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(155, ng3);
    t17 = (-(1));
    t2 = (t0 + 13136);
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

LAB8:    xsi_set_current_line(153, ng3);
    t12 = (t0 + 13136);
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
    char t22[16];
    char t23[16];
    char t28[16];
    char t30[16];
    char t33[16];
    char t38[16];
    char t43[16];
    char t45[16];
    char t48[16];
    char t54[16];
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    int t16;
    int t17;
    int t19;
    int t20;
    int t21;
    char *t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t29;
    char *t31;
    char *t32;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t42;
    char *t44;
    char *t46;
    char *t47;
    char *t49;
    char *t50;
    int t51;
    char *t52;
    char *t53;
    char *t55;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;

LAB0:    xsi_set_current_line(168, ng3);
    t2 = (t0 + 1672U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 12224);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(170, ng3);
    t7 = (t0 + 1992U);
    t8 = *((char **)t7);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:    t2 = (t0 + 5512U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = (t0 + 5352U);
    t7 = *((char **)t2);
    t17 = *((int *)t7);
    t1 = (t16 > t17);
    if (t1 != 0)
        goto LAB11;

LAB12:    xsi_set_current_line(199, ng3);
    t2 = (t0 + 4552U);
    t3 = *((char **)t2);
    t2 = (t0 + 20628U);
    t4 = ieee_p_1242562249_sub_3840967975_1035706684(IEEE_P_1242562249, t3, t2, 0);
    if (t4 == 1)
        goto LAB16;

LAB17:    t1 = (unsigned char)0;

LAB18:    t6 = (!(t1));
    if (t6 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(211, ng3);
    t2 = (t0 + 4552U);
    t3 = *((char **)t2);
    t2 = (t0 + 13520);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 32U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(212, ng3);
    t2 = (t0 + 5192U);
    t3 = *((char **)t2);
    t2 = (t0 + 13456);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 32U);
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(213, ng3);
    t2 = (t0 + 13584);
    t3 = (t2 + 56U);
    t7 = *((char **)t3);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(215, ng3);
    t2 = (t0 + 21308);
    xsi_report(t2, 21U, 0);

LAB9:    goto LAB3;

LAB5:    t2 = (t0 + 1632U);
    t6 = xsi_signal_has_event(t2);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(171, ng3);
    t7 = (t0 + 1032U);
    t11 = *((char **)t7);
    t7 = (t0 + 13200);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t11, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(172, ng3);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t2 = (t0 + 13264);
    t7 = (t2 + 56U);
    t8 = *((char **)t7);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 32U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(174, ng3);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t2 = (t0 + 20388U);
    t16 = work_a_3147582278_3212880686_sub_3659340636_3057020925(t0, t3, t2);
    t7 = (t0 + 13328);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((int *)t13) = t16;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(177, ng3);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t3 = t2;
    memset(t3, (unsigned char)2, 32U);
    t7 = (t0 + 13392);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(178, ng3);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t3 = t2;
    memset(t3, (unsigned char)2, 32U);
    t7 = (t0 + 13456);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(179, ng3);
    t2 = xsi_get_transient_memory(32U);
    memset(t2, 0, 32U);
    t3 = t2;
    memset(t3, (unsigned char)2, 32U);
    t7 = (t0 + 13520);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(180, ng3);
    t2 = (t0 + 13584);
    t3 = (t2 + 56U);
    t7 = *((char **)t3);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(182, ng3);
    t2 = (t0 + 21181);
    xsi_report(t2, 31U, 0);
    goto LAB9;

LAB11:    xsi_set_current_line(186, ng3);
    t2 = (t0 + 13584);
    t8 = (t2 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(187, ng3);
    t2 = (t0 + 5672U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t17 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t18);
    t7 = (t0 + 5992U);
    t8 = *((char **)t7);
    t7 = (t0 + 20676U);
    t19 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t8, t7);
    t20 = (t17 * t19);
    t11 = (t0 + 7248U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    *((int *)t11) = t20;
    xsi_set_current_line(188, ng3);
    t2 = (t0 + 4552U);
    t3 = *((char **)t2);
    t2 = (t0 + 20628U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t3, t2);
    t7 = (t0 + 7248U);
    t8 = *((char **)t7);
    t17 = *((int *)t8);
    t7 = (t0 + 4712U);
    t11 = *((char **)t7);
    t7 = (t0 + 20644U);
    t19 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t11, t7);
    t20 = (t17 * t19);
    t21 = (t16 - t20);
    t12 = (t0 + 7368U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    *((int *)t12) = t21;
    xsi_set_current_line(189, ng3);
    t2 = (t0 + 7368U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t7 = (t0 + 13200);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(191, ng3);
    t2 = (t0 + 5192U);
    t3 = *((char **)t2);
    t2 = (t0 + 20660U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t3, t2);
    t7 = (t0 + 7248U);
    t8 = *((char **)t7);
    t17 = *((int *)t8);
    t19 = (t16 + t17);
    t7 = (t0 + 7488U);
    t11 = *((char **)t7);
    t7 = (t11 + 0);
    *((int *)t7) = t19;
    xsi_set_current_line(192, ng3);
    t2 = (t0 + 7488U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t7 = (t0 + 13392);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(194, ng3);
    t2 = (t0 + 21212);
    t7 = ((STD_STANDARD) + 384);
    t8 = (t0 + 7248U);
    t11 = *((char **)t8);
    t16 = *((int *)t11);
    t8 = xsi_int_to_mem(t16);
    t12 = xsi_string_variable_get_image(t18, t7, t8);
    t14 = ((STD_STANDARD) + 1008);
    t15 = (t23 + 0U);
    t24 = (t15 + 0U);
    *((int *)t24) = 1;
    t24 = (t15 + 4U);
    *((int *)t24) = 29;
    t24 = (t15 + 8U);
    *((int *)t24) = 1;
    t17 = (29 - 1);
    t25 = (t17 * 1);
    t25 = (t25 + 1);
    t24 = (t15 + 12U);
    *((unsigned int *)t24) = t25;
    t13 = xsi_base_array_concat(t13, t22, t14, (char)97, t2, t23, (char)97, t12, t18, (char)101);
    t24 = (t0 + 21241);
    t29 = ((STD_STANDARD) + 1008);
    t31 = (t30 + 0U);
    t32 = (t31 + 0U);
    *((int *)t32) = 1;
    t32 = (t31 + 4U);
    *((int *)t32) = 9;
    t32 = (t31 + 8U);
    *((int *)t32) = 1;
    t19 = (9 - 1);
    t25 = (t19 * 1);
    t25 = (t25 + 1);
    t32 = (t31 + 12U);
    *((unsigned int *)t32) = t25;
    t27 = xsi_base_array_concat(t27, t28, t29, (char)97, t13, t22, (char)97, t24, t30, (char)101);
    t32 = ((STD_STANDARD) + 384);
    t34 = (t0 + 7368U);
    t35 = *((char **)t34);
    t20 = *((int *)t35);
    t34 = xsi_int_to_mem(t20);
    t36 = xsi_string_variable_get_image(t33, t32, t34);
    t39 = ((STD_STANDARD) + 1008);
    t37 = xsi_base_array_concat(t37, t38, t39, (char)97, t27, t28, (char)97, t36, t33, (char)101);
    t40 = (t0 + 21250);
    t44 = ((STD_STANDARD) + 1008);
    t46 = (t45 + 0U);
    t47 = (t46 + 0U);
    *((int *)t47) = 1;
    t47 = (t46 + 4U);
    *((int *)t47) = 9;
    t47 = (t46 + 8U);
    *((int *)t47) = 1;
    t21 = (9 - 1);
    t25 = (t21 * 1);
    t25 = (t25 + 1);
    t47 = (t46 + 12U);
    *((unsigned int *)t47) = t25;
    t42 = xsi_base_array_concat(t42, t43, t44, (char)97, t37, t38, (char)97, t40, t45, (char)101);
    t47 = ((STD_STANDARD) + 384);
    t49 = (t0 + 7488U);
    t50 = *((char **)t49);
    t51 = *((int *)t50);
    t49 = xsi_int_to_mem(t51);
    t52 = xsi_string_variable_get_image(t48, t47, t49);
    t55 = ((STD_STANDARD) + 1008);
    t53 = xsi_base_array_concat(t53, t54, t55, (char)97, t42, t43, (char)97, t52, t48, (char)101);
    t56 = (t18 + 12U);
    t25 = *((unsigned int *)t56);
    t57 = (29U + t25);
    t58 = (t57 + 9U);
    t59 = (t33 + 12U);
    t60 = *((unsigned int *)t59);
    t61 = (t58 + t60);
    t62 = (t61 + 9U);
    t63 = (t48 + 12U);
    t64 = *((unsigned int *)t63);
    t65 = (t62 + t64);
    xsi_report(t53, t65, 0);
    goto LAB9;

LAB13:    xsi_set_current_line(201, ng3);
    t13 = (t0 + 4552U);
    t14 = *((char **)t13);
    t13 = (t0 + 20628U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t14, t13);
    t15 = (t0 + 5832U);
    t24 = *((char **)t15);
    t17 = *((int *)t24);
    t15 = (t0 + 4712U);
    t26 = *((char **)t15);
    t15 = (t0 + 20644U);
    t19 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t26, t15);
    t20 = (t17 * t19);
    t21 = (t16 - t20);
    t27 = (t0 + 7248U);
    t29 = *((char **)t27);
    t27 = (t29 + 0);
    *((int *)t27) = t21;
    xsi_set_current_line(202, ng3);
    t2 = (t0 + 7248U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t7 = (t0 + 13200);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(204, ng3);
    t2 = (t0 + 5192U);
    t3 = *((char **)t2);
    t2 = (t0 + 20660U);
    t16 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t3, t2);
    t7 = (t0 + 5832U);
    t8 = *((char **)t7);
    t17 = *((int *)t8);
    t19 = (t16 + t17);
    t7 = (t0 + 7368U);
    t11 = *((char **)t7);
    t7 = (t11 + 0);
    *((int *)t7) = t19;
    xsi_set_current_line(205, ng3);
    t2 = (t0 + 7368U);
    t3 = *((char **)t2);
    t16 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t18, t16, 32);
    t7 = (t0 + 13392);
    t8 = (t7 + 56U);
    t11 = *((char **)t8);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(207, ng3);
    t2 = (t0 + 21259);
    xsi_report(t2, 49U, 0);
    goto LAB14;

LAB16:    t7 = (t0 + 4552U);
    t8 = *((char **)t7);
    t7 = (t0 + 20628U);
    t11 = (t0 + 4712U);
    t12 = *((char **)t11);
    t11 = (t0 + 20644U);
    t5 = ieee_p_1242562249_sub_2720006528_1035706684(IEEE_P_1242562249, t8, t7, t12, t11);
    t1 = t5;
    goto LAB18;

}


extern void work_a_3147582278_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3147582278_3212880686_p_0,(void *)work_a_3147582278_3212880686_p_1,(void *)work_a_3147582278_3212880686_p_2,(void *)work_a_3147582278_3212880686_p_3,(void *)work_a_3147582278_3212880686_p_4,(void *)work_a_3147582278_3212880686_p_5,(void *)work_a_3147582278_3212880686_p_6,(void *)work_a_3147582278_3212880686_p_7,(void *)work_a_3147582278_3212880686_p_8,(void *)work_a_3147582278_3212880686_p_9,(void *)work_a_3147582278_3212880686_p_10,(void *)work_a_3147582278_3212880686_p_11,(void *)work_a_3147582278_3212880686_p_12,(void *)work_a_3147582278_3212880686_p_13};
	static char *se[] = {(void *)work_a_3147582278_3212880686_sub_3659340636_3057020925,(void *)work_a_3147582278_3212880686_sub_4177263305_3057020925};
	xsi_register_didat("work_a_3147582278_3212880686", "isim/divider_test2tb_isim_beh.exe.sim/work/a_3147582278_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
