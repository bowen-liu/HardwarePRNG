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
static const char *ng0 = "C:/Users/bowenliu/Desktop/UvicSummer2016Ceng441-master/PRNG_VHDL/PRNG/UA_TX/debouncer_counter.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;
extern char *WORK_P_3206588008;

unsigned char ieee_p_1242562249_sub_2720006528_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_2931903318_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1909880560_1516540902_p_0(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned char t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;

LAB0:    xsi_set_current_line(22, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 1152U);
    t4 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t4 == 1)
        goto LAB7;

LAB8:    t3 = (unsigned char)0;

LAB9:    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 1808U);
    t2 = *((char **)t1);
    t1 = (t0 + 3192);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t10 = *((char **)t7);
    memcpy(t10, t2, 20U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3112);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(23, ng0);
    t1 = (t0 + 5387);
    t6 = (t0 + 1808U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    memcpy(t6, t1, 20U);
    goto LAB3;

LAB5:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 1808U);
    t6 = *((char **)t2);
    t2 = (t0 + 5340U);
    t7 = ((WORK_P_3206588008) + 1168U);
    t10 = *((char **)t7);
    t7 = ((WORK_P_3206588008) + 10240U);
    t11 = ieee_p_1242562249_sub_2720006528_1035706684(IEEE_P_1242562249, t6, t2, t10, t7);
    if (t11 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(28, ng0);
    t1 = (t0 + 5407);
    t5 = (t0 + 1808U);
    t6 = *((char **)t5);
    t5 = (t6 + 0);
    memcpy(t5, t1, 20U);

LAB11:    goto LAB3;

LAB7:    t2 = (t0 + 1032U);
    t5 = *((char **)t2);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)3);
    t3 = t9;
    goto LAB9;

LAB10:    xsi_set_current_line(26, ng0);
    t13 = (t0 + 1808U);
    t14 = *((char **)t13);
    t13 = (t0 + 5340U);
    t15 = ieee_p_1242562249_sub_2931903318_1035706684(IEEE_P_1242562249, t12, t14, t13, 1);
    t16 = (t0 + 1808U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    t18 = (t12 + 12U);
    t19 = *((unsigned int *)t18);
    t20 = (1U * t19);
    memcpy(t16, t15, t20);
    goto LAB11;

}


extern void work_a_1909880560_1516540902_init()
{
	static char *pe[] = {(void *)work_a_1909880560_1516540902_p_0};
	xsi_register_didat("work_a_1909880560_1516540902", "isim/prng_tl_tb_isim_beh.exe.sim/work/a_1909880560_1516540902.didat");
	xsi_register_executes(pe);
}
