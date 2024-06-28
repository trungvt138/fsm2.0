/*
* wait_free_slide1.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_WAIT_FREE_SLIDE1_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_WAIT_FREE_SLIDE1_H_

#include "errorbasestate.h"
#include "../../subcommon/triggerprocessingstate.h"

class Wait_Free_Slide1 : public ErrorBaseState {
public:
	TriggerProcessingState slide1_free() override;
	TriggerProcessingState slide2_free() override;
	void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_WAIT_FREE_SLIDE1_H_ */
