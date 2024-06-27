/*
 * Sorting_FBA1.cpp
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */

#include "Sorting_FBA1.h"

#include <iostream>

#include "sortingpseudoendstate.h"

TriggerProcessingState Sorting_FBA1::ss_ls_srt1_interrupted() {
	std::cout << "Sorting_FBA1: ss_ls_srt1_interrupted" << std::endl;
	//TODO: AK_AWF_WCH1_ON
	//		WS_SORTED_FBA1
	leavingState();
	new(this) SortingPseudoEndState;
	return TriggerProcessingState::endstatereached;
}

void Sorting_FBA1::showState() {
	std::cout << "SortingFsm: Sorting_FBA1" << std::endl;
}
