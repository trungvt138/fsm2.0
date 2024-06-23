//
// Created by trung on 31/05/2024.
//

#ifndef OPBASESTATE_H
#define OPBASESTATE_H

#include "../contextdata.h"
#include "../actions.h"
#include "../subcommon/triggerprocessingstate.h"

class MainBaseState {
protected:
    ContextData *data;
    Actions *action;
public:
    virtual ~MainBaseState() = default;

    virtual void initSubStateMachines(){};

    void setData(ContextData *data){this->data = data;};
    void setAction(Actions *action){this->action = action;};

    virtual bool isPseudoStartState(){return false;};
    virtual bool isPseudoEndState(){return false;};

    virtual void enterByDefaultEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaPseudoStart();

    virtual void entry(){};
    virtual void exit(){};

    virtual TriggerProcessingState ss_t_str_longpressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_str_shortpressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_stp_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ws_false_placement() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ws_gone() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState both_slide_full() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_est1_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_est2_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState connection_lost() {return TriggerProcessingState::pending;};

    virtual void showState() {};
};



#endif //OPBASESTATE_H
