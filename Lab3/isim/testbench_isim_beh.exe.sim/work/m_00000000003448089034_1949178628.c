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
static const char *ng0 = "C:/Users/chang/Documents/NCTU/2_spring/Conputer Organization/Computer Organization Lab3/testbench.v";
static const char *ng1 = "lab3.vcd";
static int ng2[] = {0, 0};
static const char *ng3 = "CO_Result.txt";
static int ng4[] = {1, 0};
static int ng5[] = {100, 0};
static const char *ng6 = "r0 = %3d, r1 = %3d, r2 = %3d, r3 = %3d, \nr4 = %3d, r5 = %3d, r6 = %3d, r7 = %3d, \nr8 = %3d, r9 = %3d, r10 = %2d, r11 = %2d";
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};
static int ng9[] = {4, 0};
static int ng10[] = {5, 0};
static int ng11[] = {6, 0};
static int ng12[] = {7, 0};
static int ng13[] = {8, 0};
static int ng14[] = {9, 0};
static int ng15[] = {10, 0};
static int ng16[] = {11, 0};



static void Always_22_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 2688U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(22, ng0);
    t2 = (t0 + 2496);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(22, ng0);
    t4 = (t0 + 1288);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1288);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_24_1(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(24, ng0);

LAB2:    xsi_set_current_line(25, ng0);
    xsi_vcd_dumpfile(ng1);
    xsi_set_current_line(26, ng0);
    t1 = ((char*)((ng2)));
    xsi_vcd_dumpvars_args(*((unsigned int *)t1), t0, (char)109, t0, (char)101);

LAB1:    return;
}

static void Initial_29_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;

LAB0:    t1 = (t0 + 3184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);

LAB4:    xsi_set_current_line(30, ng0);
    *((int *)t3) = xsi_vlogfile_file_open_of_cname(ng3);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = (t0 + 1768);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1288);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    xsi_set_current_line(33, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 1608);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 32);
    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2992);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(34, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t0 + 1448);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2992);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(35, ng0);
    t4 = (t0 + 1768);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_fclose(*((unsigned int *)t6));
    xsi_set_current_line(35, ng0);
    xsi_vlog_stop(1);
    goto LAB1;

}

static void Always_38_3(char *t0)
{
    char t8[8];
    char t20[8];
    char t34[8];
    char t48[8];
    char t62[8];
    char t76[8];
    char t90[8];
    char t104[8];
    char t118[8];
    char t132[8];
    char t146[8];
    char t160[8];
    char t174[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t91;
    char *t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    char *t101;
    char *t102;
    char *t103;
    char *t105;
    char *t106;
    char *t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t112;
    char *t113;
    char *t114;
    char *t115;
    char *t116;
    char *t117;
    char *t119;
    char *t120;
    char *t121;
    char *t122;
    char *t123;
    char *t124;
    char *t125;
    char *t126;
    char *t127;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    char *t137;
    char *t138;
    char *t139;
    char *t140;
    char *t141;
    char *t142;
    char *t143;
    char *t144;
    char *t145;
    char *t147;
    char *t148;
    char *t149;
    char *t150;
    char *t151;
    char *t152;
    char *t153;
    char *t154;
    char *t155;
    char *t156;
    char *t157;
    char *t158;
    char *t159;
    char *t161;
    char *t162;
    char *t163;
    char *t164;
    char *t165;
    char *t166;
    char *t167;
    char *t168;
    char *t169;
    char *t170;
    char *t171;
    char *t172;
    char *t173;
    char *t175;
    char *t176;
    char *t177;
    char *t178;
    char *t179;
    char *t180;
    char *t181;
    char *t182;
    char *t183;

LAB0:    t1 = (t0 + 3432U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 3752);
    *((int *)t2) = 1;
    t3 = (t0 + 3464);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(39, ng0);
    t4 = (t0 + 1608);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 32, t6, 32, t7, 32);
    t9 = (t0 + 1608);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 32);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1608);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t8, 0, 8);
    xsi_vlog_signed_equal(t8, 32, t4, 32, t5, 32);
    t6 = (t8 + 4);
    t10 = *((unsigned int *)t6);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t13 = (t12 & t11);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(40, ng0);

LAB9:    xsi_set_current_line(41, ng0);
    t7 = (t0 + 1768);
    t9 = (t7 + 56U);
    t15 = *((char **)t9);
    t16 = (t0 + 5436);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 56U);
    t19 = *((char **)t18);
    t21 = (t0 + 5460);
    t22 = *((char **)t21);
    t23 = ((((char*)(t22))) + 72U);
    t24 = *((char **)t23);
    t25 = (t0 + 5484);
    t26 = *((char **)t25);
    t27 = ((((char*)(t26))) + 64U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t20, 32, t19, t24, t28, 1, 1, t29, 32, 1);
    t30 = (t0 + 5508);
    t31 = *((char **)t30);
    t32 = ((((char*)(t31))) + 56U);
    t33 = *((char **)t32);
    t35 = (t0 + 5532);
    t36 = *((char **)t35);
    t37 = ((((char*)(t36))) + 72U);
    t38 = *((char **)t37);
    t39 = (t0 + 5556);
    t40 = *((char **)t39);
    t41 = ((((char*)(t40))) + 64U);
    t42 = *((char **)t41);
    t43 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t34, 32, t33, t38, t42, 1, 1, t43, 32, 1);
    t44 = (t0 + 5580);
    t45 = *((char **)t44);
    t46 = ((((char*)(t45))) + 56U);
    t47 = *((char **)t46);
    t49 = (t0 + 5604);
    t50 = *((char **)t49);
    t51 = ((((char*)(t50))) + 72U);
    t52 = *((char **)t51);
    t53 = (t0 + 5628);
    t54 = *((char **)t53);
    t55 = ((((char*)(t54))) + 64U);
    t56 = *((char **)t55);
    t57 = ((char*)((ng7)));
    xsi_vlog_generic_get_array_select_value(t48, 32, t47, t52, t56, 1, 1, t57, 32, 1);
    t58 = (t0 + 5652);
    t59 = *((char **)t58);
    t60 = ((((char*)(t59))) + 56U);
    t61 = *((char **)t60);
    t63 = (t0 + 5676);
    t64 = *((char **)t63);
    t65 = ((((char*)(t64))) + 72U);
    t66 = *((char **)t65);
    t67 = (t0 + 5700);
    t68 = *((char **)t67);
    t69 = ((((char*)(t68))) + 64U);
    t70 = *((char **)t69);
    t71 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t62, 32, t61, t66, t70, 1, 1, t71, 32, 1);
    t72 = (t0 + 5724);
    t73 = *((char **)t72);
    t74 = ((((char*)(t73))) + 56U);
    t75 = *((char **)t74);
    t77 = (t0 + 5748);
    t78 = *((char **)t77);
    t79 = ((((char*)(t78))) + 72U);
    t80 = *((char **)t79);
    t81 = (t0 + 5772);
    t82 = *((char **)t81);
    t83 = ((((char*)(t82))) + 64U);
    t84 = *((char **)t83);
    t85 = ((char*)((ng9)));
    xsi_vlog_generic_get_array_select_value(t76, 32, t75, t80, t84, 1, 1, t85, 32, 1);
    t86 = (t0 + 5796);
    t87 = *((char **)t86);
    t88 = ((((char*)(t87))) + 56U);
    t89 = *((char **)t88);
    t91 = (t0 + 5820);
    t92 = *((char **)t91);
    t93 = ((((char*)(t92))) + 72U);
    t94 = *((char **)t93);
    t95 = (t0 + 5844);
    t96 = *((char **)t95);
    t97 = ((((char*)(t96))) + 64U);
    t98 = *((char **)t97);
    t99 = ((char*)((ng10)));
    xsi_vlog_generic_get_array_select_value(t90, 32, t89, t94, t98, 1, 1, t99, 32, 1);
    t100 = (t0 + 5868);
    t101 = *((char **)t100);
    t102 = ((((char*)(t101))) + 56U);
    t103 = *((char **)t102);
    t105 = (t0 + 5892);
    t106 = *((char **)t105);
    t107 = ((((char*)(t106))) + 72U);
    t108 = *((char **)t107);
    t109 = (t0 + 5916);
    t110 = *((char **)t109);
    t111 = ((((char*)(t110))) + 64U);
    t112 = *((char **)t111);
    t113 = ((char*)((ng11)));
    xsi_vlog_generic_get_array_select_value(t104, 32, t103, t108, t112, 1, 1, t113, 32, 1);
    t114 = (t0 + 5940);
    t115 = *((char **)t114);
    t116 = ((((char*)(t115))) + 56U);
    t117 = *((char **)t116);
    t119 = (t0 + 5964);
    t120 = *((char **)t119);
    t121 = ((((char*)(t120))) + 72U);
    t122 = *((char **)t121);
    t123 = (t0 + 5988);
    t124 = *((char **)t123);
    t125 = ((((char*)(t124))) + 64U);
    t126 = *((char **)t125);
    t127 = ((char*)((ng12)));
    xsi_vlog_generic_get_array_select_value(t118, 32, t117, t122, t126, 1, 1, t127, 32, 1);
    t128 = (t0 + 6012);
    t129 = *((char **)t128);
    t130 = ((((char*)(t129))) + 56U);
    t131 = *((char **)t130);
    t133 = (t0 + 6036);
    t134 = *((char **)t133);
    t135 = ((((char*)(t134))) + 72U);
    t136 = *((char **)t135);
    t137 = (t0 + 6060);
    t138 = *((char **)t137);
    t139 = ((((char*)(t138))) + 64U);
    t140 = *((char **)t139);
    t141 = ((char*)((ng13)));
    xsi_vlog_generic_get_array_select_value(t132, 32, t131, t136, t140, 1, 1, t141, 32, 1);
    t142 = (t0 + 6084);
    t143 = *((char **)t142);
    t144 = ((((char*)(t143))) + 56U);
    t145 = *((char **)t144);
    t147 = (t0 + 6108);
    t148 = *((char **)t147);
    t149 = ((((char*)(t148))) + 72U);
    t150 = *((char **)t149);
    t151 = (t0 + 6132);
    t152 = *((char **)t151);
    t153 = ((((char*)(t152))) + 64U);
    t154 = *((char **)t153);
    t155 = ((char*)((ng14)));
    xsi_vlog_generic_get_array_select_value(t146, 32, t145, t150, t154, 1, 1, t155, 32, 1);
    t156 = (t0 + 6156);
    t157 = *((char **)t156);
    t158 = ((((char*)(t157))) + 56U);
    t159 = *((char **)t158);
    t161 = (t0 + 6180);
    t162 = *((char **)t161);
    t163 = ((((char*)(t162))) + 72U);
    t164 = *((char **)t163);
    t165 = (t0 + 6204);
    t166 = *((char **)t165);
    t167 = ((((char*)(t166))) + 64U);
    t168 = *((char **)t167);
    t169 = ((char*)((ng15)));
    xsi_vlog_generic_get_array_select_value(t160, 32, t159, t164, t168, 1, 1, t169, 32, 1);
    t170 = (t0 + 6228);
    t171 = *((char **)t170);
    t172 = ((((char*)(t171))) + 56U);
    t173 = *((char **)t172);
    t175 = (t0 + 6252);
    t176 = *((char **)t175);
    t177 = ((((char*)(t176))) + 72U);
    t178 = *((char **)t177);
    t179 = (t0 + 6276);
    t180 = *((char **)t179);
    t181 = ((((char*)(t180))) + 64U);
    t182 = *((char **)t181);
    t183 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t174, 32, t173, t178, t182, 1, 1, t183, 32, 1);
    xsi_vlogfile_fwrite(*((unsigned int *)t15), 1, 0, 0, ng6, 13, t0, (char)119, t20, 32, (char)119, t34, 32, (char)119, t48, 32, (char)119, t62, 32, (char)119, t76, 32, (char)119, t90, 32, (char)119, t104, 32, (char)119, t118, 32, (char)119, t132, 32, (char)119, t146, 32, (char)119, t160, 32, (char)119, t174, 32);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 6300);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 6324);
    t7 = *((char **)t6);
    t9 = ((((char*)(t7))) + 72U);
    t15 = *((char **)t9);
    t16 = (t0 + 6348);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 64U);
    t19 = *((char **)t18);
    t21 = ((char*)((ng2)));
    xsi_vlog_generic_get_array_select_value(t8, 32, t5, t15, t19, 1, 1, t21, 32, 1);
    t22 = (t0 + 6372);
    t23 = *((char **)t22);
    t24 = ((((char*)(t23))) + 56U);
    t25 = *((char **)t24);
    t26 = (t0 + 6396);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 72U);
    t29 = *((char **)t28);
    t30 = (t0 + 6420);
    t31 = *((char **)t30);
    t32 = ((((char*)(t31))) + 64U);
    t33 = *((char **)t32);
    t35 = ((char*)((ng4)));
    xsi_vlog_generic_get_array_select_value(t20, 32, t25, t29, t33, 1, 1, t35, 32, 1);
    t36 = (t0 + 6444);
    t37 = *((char **)t36);
    t38 = ((((char*)(t37))) + 56U);
    t39 = *((char **)t38);
    t40 = (t0 + 6468);
    t41 = *((char **)t40);
    t42 = ((((char*)(t41))) + 72U);
    t43 = *((char **)t42);
    t44 = (t0 + 6492);
    t45 = *((char **)t44);
    t46 = ((((char*)(t45))) + 64U);
    t47 = *((char **)t46);
    t49 = ((char*)((ng7)));
    xsi_vlog_generic_get_array_select_value(t34, 32, t39, t43, t47, 1, 1, t49, 32, 1);
    t50 = (t0 + 6516);
    t51 = *((char **)t50);
    t52 = ((((char*)(t51))) + 56U);
    t53 = *((char **)t52);
    t54 = (t0 + 6540);
    t55 = *((char **)t54);
    t56 = ((((char*)(t55))) + 72U);
    t57 = *((char **)t56);
    t58 = (t0 + 6564);
    t59 = *((char **)t58);
    t60 = ((((char*)(t59))) + 64U);
    t61 = *((char **)t60);
    t63 = ((char*)((ng8)));
    xsi_vlog_generic_get_array_select_value(t48, 32, t53, t57, t61, 1, 1, t63, 32, 1);
    t64 = (t0 + 6588);
    t65 = *((char **)t64);
    t66 = ((((char*)(t65))) + 56U);
    t67 = *((char **)t66);
    t68 = (t0 + 6612);
    t69 = *((char **)t68);
    t70 = ((((char*)(t69))) + 72U);
    t71 = *((char **)t70);
    t72 = (t0 + 6636);
    t73 = *((char **)t72);
    t74 = ((((char*)(t73))) + 64U);
    t75 = *((char **)t74);
    t77 = ((char*)((ng9)));
    xsi_vlog_generic_get_array_select_value(t62, 32, t67, t71, t75, 1, 1, t77, 32, 1);
    t78 = (t0 + 6660);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 56U);
    t81 = *((char **)t80);
    t82 = (t0 + 6684);
    t83 = *((char **)t82);
    t84 = ((((char*)(t83))) + 72U);
    t85 = *((char **)t84);
    t86 = (t0 + 6708);
    t87 = *((char **)t86);
    t88 = ((((char*)(t87))) + 64U);
    t89 = *((char **)t88);
    t91 = ((char*)((ng10)));
    xsi_vlog_generic_get_array_select_value(t76, 32, t81, t85, t89, 1, 1, t91, 32, 1);
    t92 = (t0 + 6732);
    t93 = *((char **)t92);
    t94 = ((((char*)(t93))) + 56U);
    t95 = *((char **)t94);
    t96 = (t0 + 6756);
    t97 = *((char **)t96);
    t98 = ((((char*)(t97))) + 72U);
    t99 = *((char **)t98);
    t100 = (t0 + 6780);
    t101 = *((char **)t100);
    t102 = ((((char*)(t101))) + 64U);
    t103 = *((char **)t102);
    t105 = ((char*)((ng11)));
    xsi_vlog_generic_get_array_select_value(t90, 32, t95, t99, t103, 1, 1, t105, 32, 1);
    t106 = (t0 + 6804);
    t107 = *((char **)t106);
    t108 = ((((char*)(t107))) + 56U);
    t109 = *((char **)t108);
    t110 = (t0 + 6828);
    t111 = *((char **)t110);
    t112 = ((((char*)(t111))) + 72U);
    t113 = *((char **)t112);
    t114 = (t0 + 6852);
    t115 = *((char **)t114);
    t116 = ((((char*)(t115))) + 64U);
    t117 = *((char **)t116);
    t119 = ((char*)((ng12)));
    xsi_vlog_generic_get_array_select_value(t104, 32, t109, t113, t117, 1, 1, t119, 32, 1);
    t120 = (t0 + 6876);
    t121 = *((char **)t120);
    t122 = ((((char*)(t121))) + 56U);
    t123 = *((char **)t122);
    t124 = (t0 + 6900);
    t125 = *((char **)t124);
    t126 = ((((char*)(t125))) + 72U);
    t127 = *((char **)t126);
    t128 = (t0 + 6924);
    t129 = *((char **)t128);
    t130 = ((((char*)(t129))) + 64U);
    t131 = *((char **)t130);
    t133 = ((char*)((ng13)));
    xsi_vlog_generic_get_array_select_value(t118, 32, t123, t127, t131, 1, 1, t133, 32, 1);
    t134 = (t0 + 6948);
    t135 = *((char **)t134);
    t136 = ((((char*)(t135))) + 56U);
    t137 = *((char **)t136);
    t138 = (t0 + 6972);
    t139 = *((char **)t138);
    t140 = ((((char*)(t139))) + 72U);
    t141 = *((char **)t140);
    t142 = (t0 + 6996);
    t143 = *((char **)t142);
    t144 = ((((char*)(t143))) + 64U);
    t145 = *((char **)t144);
    t147 = ((char*)((ng14)));
    xsi_vlog_generic_get_array_select_value(t132, 32, t137, t141, t145, 1, 1, t147, 32, 1);
    t148 = (t0 + 7020);
    t149 = *((char **)t148);
    t150 = ((((char*)(t149))) + 56U);
    t151 = *((char **)t150);
    t152 = (t0 + 7044);
    t153 = *((char **)t152);
    t154 = ((((char*)(t153))) + 72U);
    t155 = *((char **)t154);
    t156 = (t0 + 7068);
    t157 = *((char **)t156);
    t158 = ((((char*)(t157))) + 64U);
    t159 = *((char **)t158);
    t161 = ((char*)((ng15)));
    xsi_vlog_generic_get_array_select_value(t146, 32, t151, t155, t159, 1, 1, t161, 32, 1);
    t162 = (t0 + 7092);
    t163 = *((char **)t162);
    t164 = ((((char*)(t163))) + 56U);
    t165 = *((char **)t164);
    t166 = (t0 + 7116);
    t167 = *((char **)t166);
    t168 = ((((char*)(t167))) + 72U);
    t169 = *((char **)t168);
    t170 = (t0 + 7140);
    t171 = *((char **)t170);
    t172 = ((((char*)(t171))) + 64U);
    t173 = *((char **)t172);
    t175 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t160, 32, t165, t169, t173, 1, 1, t175, 32, 1);
    xsi_vlogfile_write(1, 0, 0, ng6, 13, t0, (char)119, t8, 32, (char)119, t20, 32, (char)119, t34, 32, (char)119, t48, 32, (char)119, t62, 32, (char)119, t76, 32, (char)119, t90, 32, (char)119, t104, 32, (char)119, t118, 32, (char)119, t132, 32, (char)119, t146, 32, (char)119, t160, 32);
    goto LAB8;

}


extern void work_m_00000000003448089034_1949178628_init()
{
	static char *pe[] = {(void *)Always_22_0,(void *)Initial_24_1,(void *)Initial_29_2,(void *)Always_38_3};
	xsi_register_didat("work_m_00000000003448089034_1949178628", "isim/testbench_isim_beh.exe.sim/work/m_00000000003448089034_1949178628.didat");
	xsi_register_executes(pe);
}
