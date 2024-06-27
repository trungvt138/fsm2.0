/*
 * anstehend_quittiert.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_QUITTIERT_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_QUITTIERT_H_

#include "errorbasestate.h"
#include "../../subcommon/triggerprocessingstate.h"

class Anstehend_Quittiert: public ErrorBaseState {
public:
	void entry() override;
	void showState() override;
	TriggerProcessingState slide1_free() override;
	TriggerProcessingState slide2_free() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_QUITTIERT_H_ */
