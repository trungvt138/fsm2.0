/*
 * bothslidefullbasestate.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLBASESTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLBASESTATE_H_

#include "../../../subcommon/triggerprocessingstate.h"
#include "../../../actions.h"
#include "../../../contextdata.h"

class BothSlideFullBaseState {
protected:
	ContextData *data;
	Actions *action;
public:
	virtual ~BothSlideFullBaseState() = default;

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

	virtual TriggerProcessingState slide1_free() {return TriggerProcessingState::pending;};
	virtual TriggerProcessingState slide2_free() {return TriggerProcessingState::pending;};

	virtual void showState() {};
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLBASESTATE_H_ */
