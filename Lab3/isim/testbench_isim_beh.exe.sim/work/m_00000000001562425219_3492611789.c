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
static const char *ng0 = "C:/hooma/Computer Organization Lab3/ALU_Ctrl.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {14U, 0U};
static unsigned int ng5[] = {8U, 0U};
static unsigned int ng6[] = {6U, 0U};
static unsigned int ng7[] = {7U, 0U};
static unsigned int ng8[] = {4U, 0U};
static int ng9[] = {11, 0};
static int ng10[] = {1010, 0};
static unsigned int ng11[] = {3U, 0U};
static unsigned int ng12[] = {5U, 0U};
static int ng13[] = {1111, 0};



static void Always_16_0(char *t0)
{
    char t9[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    int t23;
    char *t24;

LAB0:    t1 = (t0 + 2528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(16, ng0);
    t2 = (t0 + 2848);
    *((int *)t2) = 1;
    t3 = (t0 + 2560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(16, ng0);

LAB5:    xsi_set_current_line(17, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t4, 2);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng11)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 2, t2, 2);
    if (t6 == 1)
        goto LAB13;

LAB14:
LAB15:    goto LAB2;

LAB7:    xsi_set_current_line(19, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1608);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 4);
    goto LAB15;

LAB9:    xsi_set_current_line(21, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t9 + 4);
    t7 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    t12 = (t11 & 1);
    *((unsigned int *)t9) = t12;
    t13 = *((unsigned int *)t7);
    t14 = (t13 >> 0);
    t15 = (t14 & 1);
    *((unsigned int *)t3) = t15;
    t8 = (t9 + 4);
    t16 = *((unsigned int *)t8);
    t17 = (~(t16));
    t18 = *((unsigned int *)t9);
    t19 = (t18 & t17);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(24, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB18:    goto LAB15;

LAB11:    xsi_set_current_line(26, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);

LAB19:    t3 = ((char*)((ng1)));
    t23 = xsi_vlog_unsigned_case_compare(t4, 4, t3, 4);
    if (t23 == 1)
        goto LAB20;

LAB21:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB22;

LAB23:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB24;

LAB25:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB26;

LAB27:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB28;

LAB29:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB30;

LAB31:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB32;

LAB33:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB34;

LAB35:
LAB36:    goto LAB15;

LAB13:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 1048U);
    t7 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t9 + 4);
    t8 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t9) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    *((unsigned int *)t3) = t13;
    t14 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t14 & 15U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 15U);

LAB37:    t21 = ((char*)((ng1)));
    t23 = xsi_vlog_unsigned_case_compare(t9, 4, t21, 4);
    if (t23 == 1)
        goto LAB38;

LAB39:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 4, t2, 4);
    if (t6 == 1)
        goto LAB40;

LAB41:    t2 = ((char*)((ng7)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 4, t2, 4);
    if (t6 == 1)
        goto LAB42;

LAB43:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 4, t2, 4);
    if (t6 == 1)
        goto LAB44;

LAB45:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 4, t2, 4);
    if (t6 == 1)
        goto LAB46;

LAB47:    t2 = ((char*)((ng12)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 4, t2, 4);
    if (t6 == 1)
        goto LAB48;

LAB49:
LAB50:    goto LAB15;

LAB16:    xsi_set_current_line(22, ng0);
    t21 = ((char*)((ng4)));
    t22 = (t0 + 1608);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 4);
    goto LAB18;

LAB20:    xsi_set_current_line(28, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1608);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 4);
    goto LAB36;

LAB22:    xsi_set_current_line(30, ng0);
    t3 = ((char*)((ng6)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB24:    xsi_set_current_line(32, ng0);
    t3 = ((char*)((ng1)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB26:    xsi_set_current_line(34, ng0);
    t3 = ((char*)((ng3)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB28:    xsi_set_current_line(36, ng0);
    t3 = ((char*)((ng8)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB30:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng7)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB32:    xsi_set_current_line(40, ng0);
    t3 = ((char*)((ng9)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB34:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng10)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB36;

LAB38:    xsi_set_current_line(47, ng0);
    t22 = ((char*)((ng2)));
    t24 = (t0 + 1608);
    xsi_vlogvar_assign_value(t24, t22, 0, 0, 4);
    goto LAB50;

LAB40:    xsi_set_current_line(49, ng0);
    t3 = ((char*)((ng7)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB50;

LAB42:    xsi_set_current_line(51, ng0);
    t3 = ((char*)((ng1)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB50;

LAB44:    xsi_set_current_line(53, ng0);
    t3 = ((char*)((ng3)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB50;

LAB46:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng9)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB50;

LAB48:    xsi_set_current_line(57, ng0);
    t3 = ((char*)((ng13)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB50;

}


extern void work_m_00000000001562425219_3492611789_init()
{
	static char *pe[] = {(void *)Always_16_0};
	xsi_register_didat("work_m_00000000001562425219_3492611789", "isim/testbench_isim_beh.exe.sim/work/m_00000000001562425219_3492611789.didat");
	xsi_register_executes(pe);
}
