/*
 * Anstehend_Unquittiert.h
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_ANSTEHEND_UNQUITTIERT_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_ANSTEHEND_UNQUITTIERT_H_

#include "bothslidefullbasestate.h"

class Anstehend_Unquittiert : public BothSlideFullBaseState {
public:
	void entry() override;
	TriggerProcessingState slide1_free() override;
	TriggerProcessingState slide2_free() override;
	void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_ANSTEHEND_UNQUITTIERT_H_ */
