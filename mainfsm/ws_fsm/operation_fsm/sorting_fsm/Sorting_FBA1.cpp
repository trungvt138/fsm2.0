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

TriggerProcessingState Sorting_FBA1::ss_ls_sli1_full() {
	std::cout << "Sorting_FBA1: ss_ls_sli1_full called" << std::endl;

	data->removeWSFromTracker();
	data->wsCounterDownFBA1();
	leavingState();
	new(this) WS_Sorted_Port;
	return TriggerProcessingState::ws_sorted_reached;
}

void Sorting_FBA1::showState() {
	std::cout << "          SortingFsm: Sorting_FBA1" << std::endl;
}
