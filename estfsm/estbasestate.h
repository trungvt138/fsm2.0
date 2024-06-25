/*
 * estbasestate.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef ESTBASESTATE_H
#define ESTBASESTATE_H


#include "../contextdata.h"
#include "../actions.h"
#include "../resetfsm/resetbasestate.h"
#include "../subcommon/triggerprocessingstate.h"

class EstBaseState {
protected:
    ContextData *data;
    Actions *action;
    ResetBaseState *subfsm;
public:
    virtual ~EstBaseState() = default;

    virtual void initSubStateMachines();

    void setData(ContextData *data);
    void setAction(Actions *action);

    virtual bool isPseudoStartState(){return false;};
    virtual bool isPseudoEndState(){return false;};

    virtual void enterByDefaultEntryPoint(){entry();};
    virtual TriggerProcessingState handleDefaultExit(const TriggerProcessingState &handled);

    virtual void leavingState(){exit();};

    virtual void enterViaPortE1();
    virtual void enterViaPortE2();
    virtual void enterViaPortCL();

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



#endif /* ESTBASESTATE_H */
