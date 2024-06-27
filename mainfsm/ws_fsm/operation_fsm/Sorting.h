/*
 * Sorting.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_H_
#include "opbasestate.h"

class Sorting : public opbasestate {
public:
    void entry() override;
    void exit() override {};
    void showState() override;
    void handleDefaultExit(const TriggerProcessingState &handled) override;

	TriggerProcessingState ss_ls_srt1_interrupted()override;
	TriggerProcessingState ss_ls_srt2_interrupted()override;
	TriggerProcessingState right_order() override;
	TriggerProcessingState unwanted_ws() override;
	//TriggerProcessingState both_slide_full()override;
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_H_ */
