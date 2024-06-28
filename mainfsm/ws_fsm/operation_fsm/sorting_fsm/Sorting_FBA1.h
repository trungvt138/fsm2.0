/*
 * Sorting_FBA1.h
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTING_FBA1_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTING_FBA1_H_
#include "sortingbasestate.h"


class Sorting_FBA1 : public SortingBaseState {
public:

	TriggerProcessingState ss_ls_srt1_interrupted() override;
    void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_SORTING_FSM_SORTING_FBA1_H_ */
