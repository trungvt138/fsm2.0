/*
 * ws_high_hole.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "ws_high_hole.h"

#include "hmpseudoendstate.h"

void WS_High_Hole::entry() {
    std::cout << "WS_High_Hole Entry" << std::endl;
//    action->entered_Operation_State();
}

TriggerProcessingState WS_High_Hole::height_band(){
	std::cout << "WS_High_Hole: height_band called" << std::endl;
//	this->data->UpdateWSData(WS_HB);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}


void WS_High_Hole::showState() {
    std::cout << "  WS_High_Hole: HS State" << std::endl;
}

