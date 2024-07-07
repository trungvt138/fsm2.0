/*
 * Sorting_FBA2.cpp
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */



#include <iostream>
#include "ws_sorted_port.h"
#include "Sorting_FBA2.h"

#include <iostream>

#include "sortingpseudoendstate.h"
void Sorting_FBA2::entry() {
	std::cout << "\nSortingFsm: Sorting_FBA2\n" << std::endl;
}

TriggerProcessingState Sorting_FBA2::ss_ls_sli2_full() {
	//TODO: AK_AWF_WCH2_ON
	//		WS_SORTED_FBA2
	data->removeWSFromTracker();
	data->wsCounterDownFBA2();
	leavingState();
	new(this) WS_Sorted_Port;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::ws_sorted_reached;
}

void Sorting_FBA2::showState() {
	std::cout << "          SortingFsm: Sorting_FBA2" << std::endl;
}
