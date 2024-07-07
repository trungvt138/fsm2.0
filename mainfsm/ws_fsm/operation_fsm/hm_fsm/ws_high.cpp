/*
 * ws_high.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "ws_high.h"

#include "hmpseudoendstate.h"
#include "ws_hole.h"

void WS_High::entry() {
	std::cout << "\nHeight_Measurement Fsm: WS_High State\n" << std::endl;

//    action->entered_Operation_State();
}


TriggerProcessingState WS_High::height_hole(){
	std::cout << "Waiting_Height: height_hole called" << std::endl;
	leavingState();
	new(this) WS_Hole;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_High::height_band(){
	std::cout << "Waiting_Height: height_band called" << std::endl;
	this->wp->setIsTall(true);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void WS_High::showState() {
    std::cout << "            Height_Measurement Fsm: WS_High State" << std::endl;
}

