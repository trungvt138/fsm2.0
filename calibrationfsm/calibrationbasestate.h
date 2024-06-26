/*
 * calibrationmainstate.h
 *
 *  Created on: 22.06.2024
 *      Author: sebas
 */

#ifndef SRC_FSMSIMPLE_CALIBRATIONFSM_CALIBRATIONBASESTATE_H_
#define SRC_FSMSIMPLE_CALIBRATIONFSM_CALIBRATIONBASESTATE_H_


#include "../contextdata.h"
#include "../actions.h"
#include "../subcommon/triggerprocessingstate.h"
#include <iostream>
//#include "..src/Events/eventlist.h"
using namespace std;


class CalibrationBaseState {
protected:
    ContextData *data;
    Actions *action;
public:
    virtual ~CalibrationBaseState() = default;

    virtual void initSubStateMachines(){};

    void setData(ContextData *data);
    void setAction(Actions *action);

    virtual bool isPseudoStartState(){return false;};
    virtual bool isPseudoEndState(){return false;};

    virtual void enterByDefaultEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaPseudoStart();

    virtual void entry(){};
    virtual void exit(){};

    virtual TriggerProcessingState ss_ls_str1_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_str1_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState lightbarrier_height1_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState lightbarrier_height1_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_ok1_active() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_ok1_unactive() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_srt1_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_srt1_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ms1_erkannt() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ms1_fall() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState switch1_open() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState switch1_unopen() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_sli1_rise() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_sli1_full() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_end1_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_end1_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str1_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_stp1_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_stp1_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_rst1_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_rst1_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_est1_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_est1_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str1_longpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str1_shortpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str1_pressed() { return TriggerProcessingState::pending; };

    // Group 2
    virtual TriggerProcessingState ss_ls_str2_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_str2_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState lightbarrier_height2_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState lightbarrier_height2_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_ok2_active() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_ok2_unactive() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_srt2_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_srt2_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ms2_erkannt() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ms2_fall() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState switch2_open() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState switch2_unopen() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_sli2_rise() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_sli2_full() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_end2_continuous() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_ls_end2_interrupted() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str2_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_stp2_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_stp2_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_rst2_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_rst2_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_est2_unpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_est2_pressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str2_longpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str2_shortpressed() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ss_t_str2_pressed() { return TriggerProcessingState::pending; };

    // Group 3
    virtual TriggerProcessingState ws_missing() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState both_slide_full() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ws_false_placement() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState connection_lost() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState connection_back() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState ws_gone() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_high() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_flat() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_calibration() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_hole() { return TriggerProcessingState::pending; };
    virtual TriggerProcessingState height_band() { return TriggerProcessingState::pending; };

    virtual void showState() {};
};

#endif /* SRC_FSMSIMPLE_CALIBRATIONFSM_CALIBRATIONBASESTATE_H_ */
