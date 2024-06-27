//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H
#include "actions.h"
#include "contextdata.h"
#include "rootfsm/basestate.h"

class Context {
private:
    BaseState *state;
    Actions *action;
    ContextData data;
public:
    explicit Context(Actions *shared_action);
    virtual ~Context();

    void ss_t_str1_longpressed();
    void ss_t_str1_shortpressed();
    void ss_t_stp1_pressed();
    void ss_t_str2_longpressed();
    void ss_t_str2_shortpressed();
    void ss_t_stp2_pressed();
    void ws_false_placement();
    void ws_missing();
    void both_slide_full();
    void ss_t_est1_pressed();
    void ss_t_est2_pressed();
    void connection_lost();
    void ss_t_est1_unpressed();
    void ss_t_est2_unpressed();
    void connection_back();
    void ss_t_rst1_pressed();
    void ss_t_rst2_pressed();
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
    void ss_t_rst1_unpressed();
    void ss_t_str1_pressed();
    void slide1_free();
    void slide2_free();
};





#endif //CONTEXT_H