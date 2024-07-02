/*
 * WSIdle.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_IDLEWS2_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_IDLEWS2_H_

#include "wsbasestate.h"

class WSIdle2 : public WSBaseState2  {
public:
	void entry() override;

	TriggerProcessingState ss_ls_str1_interrupted() override;

    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_IDLEWS2_H_ */
