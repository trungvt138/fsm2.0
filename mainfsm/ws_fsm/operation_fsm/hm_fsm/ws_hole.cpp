/*
 * ws_hole.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "ws_hole.h"
#include "ws_high_hole.h"

void WS_Hole::entry() {
    std::cout << "WS_Hole Entry" << std::endl;
//    action->entered_Operation_State();
}

TriggerProcessingState WS_Hole::height_high(){
	std::cout << "WS_Hole: height_hole called" << std::endl;
	leavingState();
	new(this) WS_High_Hole;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}


void WS_Hole::showState() {
    std::cout << "            Height_Measurement Fsm: WS_Hole State" << std::endl;
}

