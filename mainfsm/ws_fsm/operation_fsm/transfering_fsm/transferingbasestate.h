/*
 * transferingbasestate.h
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_TRANSFERING_FSM_TRANSFERINGBASESTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_TRANSFERING_FSM_TRANSFERINGBASESTATE_H_
#include "../../../../actions.h"
#include "../../../../contextdata.h"
#include "../../../../subcommon/triggerprocessingstate.h"

class TransferingBaseState {
protected:
    ContextData *data;
    Actions *action;
public:
    void setData(ContextData *data) {this->data = data;};
    void setAction(Actions *action) {this->action = action;};

    virtual void initSubStateMachines() {};

    virtual bool isPseudoStartState(){return false;};
    virtual bool isPseudoEndState(){return false;};

    virtual void enterByDefaultEntryPoint(){entry();};
    virtual void enterByDeepHistoryEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaDeepHistory();
    virtual void enterViaPseudoStart();
    virtual void entry(){};
    virtual void exit(){};

    virtual void handleDefaultExit(const TriggerProcessingState &handled) {};

    virtual TriggerProcessingState ss_ls_end1_interrupted(){return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_ls_end2_interrupted(){return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ss_ls_str2_interrupted(){return TriggerProcessingState::pending;};
    virtual TriggerProcessingState ws_sorted(){return TriggerProcessingState::pending;}; //override;
    virtual TriggerProcessingState ss_ls_end2_continuous(){return TriggerProcessingState::pending;};
    virtual void showState(){};
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_TRANSFERING_FSM_TRANSFERINGBASESTATE_H_ */
