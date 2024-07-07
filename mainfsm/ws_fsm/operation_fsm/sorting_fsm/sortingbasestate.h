/*
 * sortingbasestate.h
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTINGBASESTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTINGBASESTATE_H_

#include "../../../../actions.h"
#include "../../../../contextdata.h"
#include "../../../../WorkPiece.h"
#include "../../../../subcommon/triggerprocessingstate.h"

class SortingBaseState {
protected:
	ContextData *data;
	Actions *action;
	WorkPiece *wp;

public:
	virtual ~SortingBaseState() = default;
	void setData(ContextData *data) {this->data = data;};
	void setAction(Actions *action) {this->action = action;};
	void setWp(WorkPiece *wp) {this->wp = wp;};

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

	virtual TriggerProcessingState ss_ls_sli1_full() { return TriggerProcessingState::pending; }
	virtual TriggerProcessingState ss_ls_sli2_full() { return TriggerProcessingState::pending; }
    virtual TriggerProcessingState unwanted_ws() { return TriggerProcessingState::pending; }
    virtual TriggerProcessingState right_order() { return TriggerProcessingState::pending; }
	virtual TriggerProcessingState error_gone() { return TriggerProcessingState::pending; }

	virtual void showState() {};
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTINGBASESTATE_H_ */
