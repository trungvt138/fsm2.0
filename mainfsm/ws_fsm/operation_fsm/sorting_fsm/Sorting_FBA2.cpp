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

TriggerProcessingState Sorting_FBA2::ss_ls_srt2_interrupted() {
	//TODO: AK_AWF_WCH2_ON
	//		WS_SORTED_FBA2
	leavingState();
	new(this) WS_Sorted_Port;
	return TriggerProcessingState::ws_sorted_reached;
}

void Sorting_FBA2::showState() {
	std::cout << "SortingFsm: Sorting_FBA1" << std::endl;
}
