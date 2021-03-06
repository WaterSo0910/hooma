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



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000004033461393_1957175458_init();
    work_m_00000000001970482688_2109230735_init();
    work_m_00000000003993185189_3207835014_init();
    work_m_00000000000625049819_1124448613_init();
    work_m_00000000000973235250_2035480523_init();
    work_m_00000000000763016046_4033376979_init();
    work_m_00000000000410538573_2512909904_init();
    work_m_00000000003309754896_1408530552_init();
    work_m_00000000001334887433_4033830893_init();
    work_m_00000000001562425219_3492611789_init();
    work_m_00000000003108274774_2725559894_init();
    work_m_00000000004151881959_1221802120_init();
    work_m_00000000001780420856_2979957399_init();
    work_m_00000000003880639205_1949178628_init();
    work_m_00000000004134447467_2073120511_init();


    xsi_register_tops("work_m_00000000003880639205_1949178628");
    xsi_register_tops("work_m_00000000004134447467_2073120511");


    return xsi_run_simulation(argc, argv);

}
