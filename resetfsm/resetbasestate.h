//
// Created by Trung Dam on 22.06.24.
//

#ifndef RESETBASESTATE_H
#define RESETBASESTATE_H

#include "../subcommon/triggerprocessingstate.h"
#include "../actions.h"
#include "../context.h"

class ResetBaseState {
protected:
    ContextData *data;
    Actions *action;

public:
    virtual ~ResetBaseState()() = default;

    virtual void initSubStateMachines(){};

    void setData(ContextData *data){this->data = data;};
    void setAction(Actions *action){this->action = action;};

    virtual bool isPseudoStartState(){return false;};
    virtual bool isPseudoEndState(){return false;};

    virtual void enterByDefaultEntryPoint(){entry();};
    virtual void enterViaPseudoStart();

    virtual void leavingState(){exit();};

    virtual void entry(){};
    virtual void exit(){};

    virtual TriggerProcessingState ss_t_est1_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_est2_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState connection_lost() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_est1_unpressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_est2_unpressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState connection_back() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_rst1_pressed() {return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_t_rst2_pressed() {return TriggerProcessingState::pending;};

    virtual void showState() {};
};



#endif //RESETBASESTATE_H
