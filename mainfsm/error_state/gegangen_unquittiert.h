/*
 * gegangen_unquittiert.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_GEGANGEN_UNQUITTIERT_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_GEGANGEN_UNQUITTIERT_H_

#include "errorbasestate.h"

class Gegangen_Unquittiert : public ErrorBaseState {
public:
	void entry() override;
	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
	void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_GEGANGEN_UNQUITTIERT_H_ */
