/*
 * errorbasestate.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORBASESTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORBASESTATE_H_

#include "../../contextdata.h"
#include "../../actions.h"
#include "../../subcommon/triggerprocessingstate.h"

#include "Both_Slide_Full_State/bothslidefullbasestate.h"

class ErrorBaseState {
protected:
	ContextData *data;
	Actions *action;
	BothSlideFullBaseState *bothSlideSubState;
public:
	virtual ~ErrorBaseState() {
		delete bothSlideSubState;
	}

	virtual void initSubStateMachines() {
		bothSlideSubState = new BothSlideFullBaseState;
		bothSlideSubState->initSubStateMachines();
	};

	void setData(ContextData *data){
		this->data = data;
		bothSlideSubState->setData(data);
	};
	void setAction(Actions *action){
		this->action = action;
		bothSlideSubState->setAction(action);
	};

	virtual void handleDefaultExit(const TriggerProcessingState &handled) {};

	virtual bool isPseudoStartState(){return false;};
	virtual bool isPseudoEndState(){return false;};

	virtual void enterByDefaultEntryPoint(){entry();};
	virtual void leavingState(){exit();};

	void enterViaPort_both_slide_full();
	void enterViaPort_false_placement();
	void enterViaPort_WSgone();

	virtual void entry(){};
	virtual void exit(){};

	virtual TriggerProcessingState ss_t_rst1_pressed() {return TriggerProcessingState::pending;};
	virtual TriggerProcessingState ss_t_rst2_pressed() {return TriggerProcessingState::pending;};
	virtual TriggerProcessingState slide1_free() {return TriggerProcessingState::pending;};
	virtual TriggerProcessingState slide2_free() {return TriggerProcessingState::pending;};

	virtual void showState() {};

};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORBASESTATE_H_ */
