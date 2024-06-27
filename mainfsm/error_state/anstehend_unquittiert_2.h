/*
 * anstehend_unquittiert_2.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_UNQUITTIERT_2_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_UNQUITTIERT_2_H_


#include "../../subcommon/triggerprocessingstate.h"
#include "errorbasestate.h"

class Anstehend_Unquittiert_2 : public ErrorBaseState {
public:
	void entry() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;

	void showState() override;
};



#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ANSTEHEND_UNQUITTIERT_2_H_ */
