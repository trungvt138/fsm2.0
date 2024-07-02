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

TriggerProcessingState Sorting_FBA1::ss_ls_srt1_interrupted() {
	std::cout << "Sorting_FBA1: ss_ls_srt1_interrupted" << std::endl;
	//TODO: AK_AWF_WCH1_ON
	//		WS_SORTED_FBA1
	leavingState();
	new(this) WS_Sorted_Port;
	return TriggerProcessingState::ws_sorted_reached;
}

void Sorting_FBA1::showState() {
	std::cout << "          SortingFsm: Sorting_FBA1" << std::endl;
}
