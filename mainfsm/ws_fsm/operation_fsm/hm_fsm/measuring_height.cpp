/*
 * measuring_height.cpp
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#include "measuring_height.h"

#include "hmpseudoendstate.h"
#include "ws_high.h"
#include "ws_flat.h"

void Measuring_Height::entry() {
	std::cout << "\nHeight_Measurement Fsm: Measuring_Height State\n" << std::endl;
    if (this->data->checkFBA1()){
    	action->ak_fbm1_slow_on();
    }
    else {
    	action->ak_fbm2_slow_on();
    }
//    action->entered_Operation_State();
}

TriggerProcessingState Measuring_Height::height_calibration(){
	std::cout << "Measuring_Height: height_calibration called" << std::endl;
//	this->data->UpdateWSData(WS_U);
	leavingState();
	new(this) HMPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

TriggerProcessingState Measuring_Height::height_high(){
	std::cout << "Measuring_Height: height_high called" << std::endl;
	leavingState();
	new(this) WS_High;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Measuring_Height::height_flat(){
	std::cout << "Measuring_Height: height_flat called" << std::endl;
	leavingState();
	new(this) WS_Flat;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

void Measuring_Height::showState() {
    std::cout << "            Height_Measurement Fsm: Measuring_Height State" << std::endl;
}



