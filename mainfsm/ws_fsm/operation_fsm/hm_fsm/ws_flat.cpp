/*
 * ws_flat.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "ws_flat.h"

#include "hmpseudoendstate.h"

void WS_Flat::entry() {
    std::cout << "Waiting_Height Entry" << std::endl;
//    action->entered_Operation_State();
}

TriggerProcessingState WS_Flat::height_band(){
	std::cout << "WS_Flat: height_band called" << std::endl;
//	this->data->UpdateWSData(WS_NRM);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}


void WS_Flat::showState() {
    std::cout << "            Height_Measurement Fsm: WS_Flat State" << std::endl;
}


