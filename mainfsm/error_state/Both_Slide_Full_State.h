/*
 * Both_Slide_Full_State.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_H_

#include "errorbasestate.h"

class Both_Slide_Full_State : public ErrorBaseState {
public:

    void handleDefaultExit(const TriggerProcessingState &handled) override;

    void enterByDefaultEntryPoint() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
	TriggerProcessingState slide1_free() override;
	TriggerProcessingState slide2_free() override;

    void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_H_ */
