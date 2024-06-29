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
    std::cout << "Waiting_Height Entry" << std::endl;
//    action->entered_Operation_State();
}

TriggerProcessingState WS_High::height_calibration(){
	std::cout << "Waiting_Height: height_calibration called" << std::endl;
//	this->data->UpdateWSData(WS_BNR);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
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
//	this->data->UpdateWSData(WS_HOB);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void WS_High::showState() {
    std::cout << "  Height_Measurement Fsm: WS_High State" << std::endl;
}

