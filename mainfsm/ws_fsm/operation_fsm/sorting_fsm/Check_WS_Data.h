/*
 * Check_WS_Data.h
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_CHECK_WS_DATA_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_CHECK_WS_DATA_H_

#include "sortingbasestate.h"

class Check_WS_Data : public SortingBaseState {
public:

	void entry() override;
	TriggerProcessingState unwanted_ws() override;
	TriggerProcessingState right_order() override;
	void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_CHECK_WS_DATA_H_ */
