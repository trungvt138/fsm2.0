//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H

#include "actions.h"
#include "contextdata.h"
#include "rootfsm/basestate.h"

class Context{
private:
    BaseState *state;
    Actions *action;
    ContextData data;


public:

    Context(Actions *shared_action);
    virtual ~Context();

    void ss_t_est2_pressed();
    void ss_t_est2_unpressed();

    void showState();

    void ss_ls_str1_continuous();
    void ss_ls_str1_interrupted();
    void lightbarrier_height1_continuous();
    void lightbarrier_height1_interrupted();
    void height_ok1_active();
    void height_ok1_unactive();
    void ss_ls_srt1_continuous();
    void ss_ls_srt1_interrupted();
    void ss_ms1_erkannt();
    void ss_ms1_fall();
    void switch1_open();
    void switch1_unopen();
    void ss_ls_sli1_rise();
    void ss_ls_sli1_full();
    void ss_ls_end1_continuous();
    void ss_ls_end1_interrupted();
    void ss_t_str1_unpressed();
    void ss_t_stp1_unpressed();
    void ss_t_stp1_pressed();
    void ss_t_rst1_pressed();
    void ss_t_rst1_unpressed();
    void ss_t_est1_unpressed();
    void ss_t_est1_pressed();
    void ss_t_str1_longpressed();
    void ss_t_str1_shortpressed();
    void ss_t_str1_pressed();

    void ss_ls_str2_continuous();
    void ss_ls_str2_interrupted();
    void lightbarrier_height2_continuous();
    void lightbarrier_height2_interrupted();
    void height_ok2_active();
    void height_ok2_unactive();
    void ss_ls_srt2_continuous();
    void ss_ls_srt2_interrupted();
    void ss_ms2_erkannt();
    void ss_ms2_fall();
    void switch2_open();
    void switch2_unopen();
    void ss_ls_sli2_rise();
    void ss_ls_sli2_full();
    void ss_ls_end2_continuous();
    void ss_ls_end2_interrupted();
    void ss_t_str2_unpressed();
    void ss_t_stp2_unpressed();
    void ss_t_stp2_pressed();
    void ss_t_rst2_pressed();
    void ss_t_rst2_unpressed();
    void ss_t_str2_longpressed();
    void ss_t_str2_shortpressed();
    void ss_t_str2_pressed();

    void ws_missing();
    void both_slide_full();
    void ws_false_placement();
    void connection_lost();
    void connection_back();
    void ws_gone();
    void height_high();
    void height_flat();
    void height_calibration();
    void height_hole();
    void height_band();

    void slide1_free();
    void slide2_free();
    void right_order();
    void unwanted_ws();
};



#endif //CONTEXT_H
