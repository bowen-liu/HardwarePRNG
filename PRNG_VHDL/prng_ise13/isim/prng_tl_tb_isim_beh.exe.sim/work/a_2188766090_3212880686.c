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
static const char *ng0 = "C:/Users/bowenliu/Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/multiplication_stage.vhd";
extern char *IEEE_P_1242562249;
extern char *WORK_P_3849459504;

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_3273497107_1035706684(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_3838596133_1035706684(char *, char *, char *, int );


static void work_a_2188766090_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(20, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 6408U);
    t3 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = ((WORK_P_3849459504) + 1168U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t7 = (t3 * t6);
    t4 = (t0 + 3880);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = t7;
    xsi_driver_first_trans_fast(t4);
    t1 = (t0 + 3768);
    *((int *)t1) = 1;

LAB1:    return;
}

static void work_a_2188766090_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(26, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t1 = (t0 + 6424U);
    t3 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = ((WORK_P_3849459504) + 1528U);
    t5 = *((char **)t4);
    t6 = *((int *)t5);
    t7 = (t3 * t6);
    t4 = (t0 + 3944);
    t8 = (t4 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = t7;
    xsi_driver_first_trans_fast(t4);
    t1 = (t0 + 3784);
    *((int *)t1) = 1;

LAB1:    return;
}

static void work_a_2188766090_3212880686_p_2(char *t0)
{
    char t1[16];
    char t13[16];
    char *t2;
    char *t3;
    int t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned char t12;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;

LAB0:    xsi_set_current_line(35, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t4 = *((int *)t3);
    t2 = (t0 + 1672U);
    t5 = *((char **)t2);
    t6 = *((int *)t5);
    t7 = (t4 - t6);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t1, t7, 32);
    t8 = (t0 + 1968U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    t10 = (t1 + 12U);
    t11 = *((unsigned int *)t10);
    t11 = (t11 * 1U);
    memcpy(t8, t2, t11);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1968U);
    t3 = *((char **)t2);
    t2 = (t0 + 6456U);
    t12 = ieee_p_1242562249_sub_3838596133_1035706684(IEEE_P_1242562249, t3, t2, 0);
    if (t12 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1968U);
    t3 = *((char **)t2);
    t2 = (t0 + 4008);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t3, 32U);
    xsi_driver_first_trans_fast_port(t2);
    t2 = (t0 + 3800);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(40, ng0);
    t5 = (t0 + 1968U);
    t8 = *((char **)t5);
    t5 = (t0 + 6456U);
    t9 = ((WORK_P_3849459504) + 1288U);
    t10 = *((char **)t9);
    t4 = *((int *)t10);
    t9 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t13, t4, 32);
    t14 = ieee_p_1242562249_sub_3273497107_1035706684(IEEE_P_1242562249, t1, t8, t5, t9, t13);
    t15 = (t0 + 1968U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    t17 = (t1 + 12U);
    t11 = *((unsigned int *)t17);
    t18 = (1U * t11);
    memcpy(t15, t14, t18);
    goto LAB3;

}


extern void work_a_2188766090_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2188766090_3212880686_p_0,(void *)work_a_2188766090_3212880686_p_1,(void *)work_a_2188766090_3212880686_p_2};
	xsi_register_didat("work_a_2188766090_3212880686", "isim/prng_tl_tb_isim_beh.exe.sim/work/a_2188766090_3212880686.didat");
	xsi_register_executes(pe);
}
