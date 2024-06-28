//
// Created by trung on 31/05/2024.
//

#ifndef BASESTATE_H
#define BASESTATE_H
#include "../actions.h"
#include "../contextdata.h"
#include "../mainfsm/mainbasestate.h"
#include "../estfsm/estbasestate.h"


class BaseState {
protected:
    ContextData *data;
    Actions *action;
    EstBaseState *estoppsubmachine;
    MainBaseState *mainsubmachine;
public:
    virtual ~BaseState() {
        delete estoppsubmachine;
        delete mainsubmachine;
    };

    virtual void initSubStateMachines();

    void setData(ContextData *data);
    void setAction(Actions *action);

    virtual bool isPseudoStartState() {return false;};
    virtual bool isPseudoEndState() {return false;};

    virtual void enterByDefaultEntryPoint(){entry();};
    virtual void enterByDeepHistoryEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaPseudoStart();
    virtual void enterViaPortE1(){};
    virtual void enterViaPortE2(){};
    virtual void enterViaPortCL(){};
    virtual void handleDefaultExit(const TriggerProcessingState &handled) {};

    // entry/exit-actions
    virtual void entry(){};
    virtual void exit(){};

    // Trigger
    virtual void ss_ls_str1_continuous() {};
    virtual void ss_ls_str1_interrupted() {};
    virtual void lightbarrier_height1_continuous() {};
    virtual void lightbarrier_height1_interrupted() {};
    virtual void height_ok1_active() {};
    virtual void height_ok1_unactive() {};
    virtual void ss_ls_srt1_continuous() {};
    virtual void ss_ls_srt1_interrupted() {};
    virtual void ss_ms1_erkannt() {};
    virtual void ss_ms1_fall() {};
    virtual void switch1_open() {};
    virtual void switch1_unopen() {};
    virtual void ss_ls_sli1_rise() {};
    virtual void ss_ls_sli1_full() {};
    virtual void ss_ls_end1_continuous() {};
    virtual void ss_ls_end1_interrupted() {};
    virtual void ss_t_str1_unpressed() {};
    virtual void ss_t_stp1_unpressed() {};
    virtual void ss_t_stp1_pressed() {};
    virtual void ss_t_rst1_pressed() {};
    virtual void ss_t_rst1_unpressed() {};
    virtual void ss_t_est1_unpressed() {};
    virtual void ss_t_est1_pressed() {};
    virtual void ss_t_str1_longpressed() {};
    virtual void ss_t_str1_shortpressed() {};
    virtual void ss_t_str1_pressed() {};

    // Group 2
    virtual void ss_ls_str2_continuous() {};
    virtual void ss_ls_str2_interrupted() {};
    virtual void lightbarrier_height2_continuous() {};
    virtual void lightbarrier_height2_interrupted() {};
    virtual void height_ok2_active() {};
    virtual void height_ok2_unactive() {};
    virtual void ss_ls_srt2_continuous() {};
    virtual void ss_ls_srt2_interrupted() {};
    virtual void ss_ms2_erkannt() {};
    virtual void ss_ms2_fall() {};
    virtual void switch2_open() {};
    virtual void switch2_unopen() {};
    virtual void ss_ls_sli2_rise() {};
    virtual void ss_ls_sli2_full() {};
    virtual void ss_ls_end2_continuous() {};
    virtual void ss_ls_end2_interrupted() {};
    virtual void ss_t_str2_unpressed() {};
    virtual void ss_t_stp2_unpressed() {};
    virtual void ss_t_stp2_pressed() {};
    virtual void ss_t_rst2_pressed() {};
    virtual void ss_t_rst2_unpressed() {};
    virtual void ss_t_est2_unpressed() {};
    virtual void ss_t_est2_pressed() {};
    virtual void ss_t_str2_longpressed() {};
    virtual void ss_t_str2_shortpressed() {};
    virtual void ss_t_str2_pressed() {};

    // Group 3
    virtual void ws_missing() {};
    virtual void both_slide_full() {};
    virtual void ws_false_placement() {};
    virtual void connection_lost() {};
    virtual void connection_back() {};
    virtual void ws_gone() {};
    virtual void height_high() {};
    virtual void height_flat() {};
    virtual void height_calibration() {};
    virtual void height_hole() {};
    virtual void height_band() {};


    virtual void slide1_free(){};
    virtual void slide2_free(){};
    virtual void unwanted_ws(){};
    virtual void right_order(){};

    virtual void showState() {};
};



#endif //BASESTATE_H
