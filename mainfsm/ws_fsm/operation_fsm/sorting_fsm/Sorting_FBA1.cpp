/*
 * Sorting_FBA1.cpp
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */

#include "Sorting_FBA1.h"

#include <iostream>

#include "sortingpseudoendstate.h"
#include "ws_sorted_port.h"
void Sorting_FBA1::entry() {
	std::cout << "\nSortingFsm: Sorting_FBA1\n" << std::endl;
}

TriggerProcessingState Sorting_FBA1::ss_ls_srt1_interrupted() {
	std::cout << "Sorting_FBA1: ss_ls_srt1_interrupted" << std::endl;
	action->ak_awf_wch1_on();
	//time(3000);
	action->ak_awf_wch1_off();
	data->removeWSFromTracker();
	//		WS_SORTED_FBA1
	leavingState();
	new(this) WS_Sorted_Port;
	return TriggerProcessingState::ws_sorted_reached;
}

void Sorting_FBA1::showState() {
	std::cout << "          SortingFsm: Sorting_FBA1" << std::endl;
}
