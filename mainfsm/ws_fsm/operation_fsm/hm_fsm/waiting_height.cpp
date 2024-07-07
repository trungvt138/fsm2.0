/*
 * waiting_height.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "waiting_height.h"
#include "measuring_height.h"

void Waiting_Height::entry() {
    std::cout << "Waiting_Height Entry" << std::endl;
//    action->entered_Operation_State();
	std::cout << "\nHeight_Measurement Fsm: Waiting_Height State\n" << std::endl;
}

TriggerProcessingState Waiting_Height::height_calibration(){
	std::cout << "Waiting_Height: height_calibration called" << std::endl;
	leavingState();
	new(this) Measuring_Height;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}


void Waiting_Height::showState() {
    std::cout << "          Height_Measurement Fsm: Waiting_Height State" << std::endl;
}


