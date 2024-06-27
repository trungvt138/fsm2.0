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
#include "../../../../subcommon/triggerprocessingstate.h"

class SortingBaseState {
protected:
	ContextData *data;
	Actions *action;
public:
	void setData(ContextData *data){};
	void setAction(Actions *action){};

	virtual void initSubStateMachines(){};

	virtual bool isPseudoStartState(){return false;};

	virtual void enterByDefaultEntryPoint(){entry();};

	virtual void leavingState(){exit();};

	virtual void enterViaPseudoStart(){};
	virtual void entry(){};
	virtual void exit(){};


	virtual void handleDefaultExit(const TriggerProcessingState &handled) {};
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTINGBASESTATE_H_ */
