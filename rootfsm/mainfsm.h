//
// Created by trung on 31/05/2024.
//

#ifndef MAIN_FSM_H
#define  MAIN_FSM_H
#include "basestate.h"


class MainFsm : public BaseState {
public:
    void enterByDefaultEntryPoint() override;

    void entry() override;
    void exit() override;


    void ss_ls_str1_continuous() override;
    void ss_ls_str1_interrupted() override;
    void lightbarrier_height1_continuous() override;
    void lightbarrier_height1_interrupted() override;
    void height_ok1_active() override;
    void height_ok1_unactive() override;
    void ss_ls_srt1_continuous() override;
    void ss_ls_srt1_interrupted() override;
    void ss_ms1_erkannt() override;
    void ss_ms1_fall() override;
    void switch1_open() override;
    void switch1_unopen() override;
    void ss_ls_sli1_rise() override;
    void ss_ls_sli1_full() override;
    void ss_ls_end1_continuous() override;
    void ss_ls_end1_interrupted() override;
    void ss_t_str1_unpressed() override;
    void ss_t_stp1_unpressed() override;
    void ss_t_stp1_pressed() override;
    void ss_t_rst1_pressed() override;
    void ss_t_rst1_unpressed() override;
    void ss_t_est1_unpressed() override;
    void ss_t_est1_pressed() override;
    void ss_t_str1_longpressed() override;
    void ss_t_str1_shortpressed() override;
    void ss_t_str1_pressed() override;

    // Group 2
    void ss_ls_str2_continuous() override;
    void ss_ls_str2_interrupted() override;
    void lightbarrier_height2_continuous() override;
    void lightbarrier_height2_interrupted() override;
    void height_ok2_active() override;
    void height_ok2_unactive() override;
    void ss_ls_srt2_continuous() override;
    void ss_ls_srt2_interrupted() override;
    void ss_ms2_erkannt() override;
    void ss_ms2_fall() override;
    void switch2_open() override;
    void switch2_unopen() override;
    void ss_ls_sli2_rise() override;
    void ss_ls_sli2_full() override;
    void ss_ls_end2_continuous() override;
    void ss_ls_end2_interrupted() override;
    void ss_t_str2_unpressed() override;
    void ss_t_stp2_unpressed() override;
    void ss_t_stp2_pressed() override;
    void ss_t_rst2_pressed() override;
    void ss_t_rst2_unpressed() override;
    void ss_t_est2_unpressed() override;
    void ss_t_est2_pressed() override;
    void ss_t_str2_longpressed() override;
    void ss_t_str2_shortpressed() override;
    void ss_t_str2_pressed() override;

    // Group 3
    void ws_missing() override;
    void both_slide_full() override;
    void ws_false_placement() override;
    void connection_lost() override;
    void connection_back() override;
    void ws_gone() override;
    void height_high() override;
    void height_flat() override;
    void height_calibration() override;
    void height_hole() override;
    void height_band() override;

    void slide1_free() override;
    void slide2_free() override;
    void unwanted_ws() override;
    void right_order() override;

    void showState() override;
};



#endif // MAIN_FSM_H
