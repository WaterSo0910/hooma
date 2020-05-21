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
static const char *ng0 = "C:/Users/chang/Documents/NCTU/2_spring/Conputer Organization/Computer Organization Lab4/ALU_Ctrl.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {2U, 0U};
static unsigned int ng3[] = {1U, 0U};
static unsigned int ng4[] = {14U, 0U};
static unsigned int ng5[] = {8U, 0U};
static unsigned int ng6[] = {4U, 0U};
static unsigned int ng7[] = {9U, 0U};
static unsigned int ng8[] = {5U, 0U};
static unsigned int ng9[] = {6U, 0U};
static unsigned int ng10[] = {7U, 0U};
static unsigned int ng11[] = {3U, 0U};
static unsigned int ng12[] = {10U, 0U};
static unsigned int ng13[] = {15U, 0U};



static void Always_16_0(char *t0)
{
    char t9[8];
    char t19[8];
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
    int t16;
    char *t17;
    char *t18;
    char *t20;

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
LAB16:
LAB15:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(19, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1608);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 4);
    goto LAB17;

LAB9:    xsi_set_current_line(21, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t9, 0, 8);
    t3 = (t9 + 4);
    t7 = (t4 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (t10 >> 0);
    *((unsigned int *)t9) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 0);
    *((unsigned int *)t3) = t13;
    t14 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t14 & 7U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 7U);

LAB18:    t8 = ((char*)((ng3)));
    t16 = xsi_vlog_unsigned_case_compare(t9, 3, t8, 3);
    if (t16 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 3, t2, 3);
    if (t6 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 3, t2, 3);
    if (t6 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 3, t2, 3);
    if (t6 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t9, 3, t2, 3);
    if (t6 == 1)
        goto LAB27;

LAB28:
LAB29:    goto LAB17;

LAB11:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);

LAB30:    t3 = ((char*)((ng1)));
    t16 = xsi_vlog_unsigned_case_compare(t4, 4, t3, 4);
    if (t16 == 1)
        goto LAB31;

LAB32:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB33;

LAB34:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB35;

LAB36:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB37;

LAB38:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB39;

LAB40:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB41;

LAB42:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB43;

LAB44:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t6 == 1)
        goto LAB45;

LAB46:
LAB48:
LAB47:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB49:    goto LAB17;

LAB13:    xsi_set_current_line(55, ng0);
    t3 = (t0 + 1048U);
    t7 = *((char **)t3);
    memset(t19, 0, 8);
    t3 = (t19 + 4);
    t8 = (t7 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (t10 >> 0);
    *((unsigned int *)t19) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    *((unsigned int *)t3) = t13;
    t14 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t14 & 7U);
    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 7U);

LAB50:    t17 = ((char*)((ng1)));
    t16 = xsi_vlog_unsigned_case_compare(t19, 3, t17, 3);
    if (t16 == 1)
        goto LAB51;

LAB52:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB53;

LAB54:    t2 = ((char*)((ng10)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB55;

LAB56:    t2 = ((char*)((ng9)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB57;

LAB58:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB59;

LAB60:    t2 = ((char*)((ng8)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB61;

LAB62:    t2 = ((char*)((ng6)));
    t6 = xsi_vlog_unsigned_case_compare(t19, 3, t2, 3);
    if (t6 == 1)
        goto LAB63;

LAB64:
LAB65:    goto LAB17;

LAB19:    xsi_set_current_line(23, ng0);
    t17 = ((char*)((ng4)));
    t18 = (t0 + 1608);
    xsi_vlogvar_assign_value(t18, t17, 0, 0, 4);
    goto LAB29;

LAB21:    xsi_set_current_line(25, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 4);
    goto LAB29;

LAB23:    xsi_set_current_line(27, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 4);
    goto LAB29;

LAB25:    xsi_set_current_line(29, ng0);
    t3 = ((char*)((ng8)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 4);
    goto LAB29;

LAB27:    xsi_set_current_line(31, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 4);
    goto LAB29;

LAB31:    xsi_set_current_line(36, ng0);
    t7 = ((char*)((ng2)));
    t8 = (t0 + 1608);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 4);
    goto LAB49;

LAB33:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng9)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB35:    xsi_set_current_line(40, ng0);
    t3 = ((char*)((ng1)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB37:    xsi_set_current_line(42, ng0);
    t3 = ((char*)((ng3)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB39:    xsi_set_current_line(44, ng0);
    t3 = ((char*)((ng6)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB41:    xsi_set_current_line(46, ng0);
    t3 = ((char*)((ng10)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB43:    xsi_set_current_line(48, ng0);
    t3 = ((char*)((ng11)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB45:    xsi_set_current_line(50, ng0);
    t3 = ((char*)((ng12)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB49;

LAB51:    xsi_set_current_line(57, ng0);
    t18 = ((char*)((ng2)));
    t20 = (t0 + 1608);
    xsi_vlogvar_assign_value(t20, t18, 0, 0, 4);
    goto LAB65;

LAB53:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng10)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

LAB55:    xsi_set_current_line(61, ng0);
    t3 = ((char*)((ng1)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

LAB57:    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng3)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

LAB59:    xsi_set_current_line(65, ng0);
    t3 = ((char*)((ng11)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

LAB61:    xsi_set_current_line(67, ng0);
    t3 = ((char*)((ng13)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

LAB63:    xsi_set_current_line(69, ng0);
    t3 = ((char*)((ng6)));
    t7 = (t0 + 1608);
    xsi_vlogvar_assign_value(t7, t3, 0, 0, 4);
    goto LAB65;

}


extern void work_m_00000000001562425219_3492611789_init()
{
	static char *pe[] = {(void *)Always_16_0};
	xsi_register_didat("work_m_00000000001562425219_3492611789", "isim/testbench_isim_beh.exe.sim/work/m_00000000001562425219_3492611789.didat");
	xsi_register_executes(pe);
}
