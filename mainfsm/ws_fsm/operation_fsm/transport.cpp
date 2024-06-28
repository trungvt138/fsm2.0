/*
 * transport.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "transport.h"
#include "height_measurement.h"

#include "height_measurement.h"
#include "oppseudoendstate.h"

void transport::entry() {
    std::cout << "transport Entry" << std::endl;
//    action->entered_Operation_State();
    this->data->checkFBA1Counter();
}

TriggerProcessingState transport::ss_ls_str1_continuous(){
	std::cout << "transport: ss_ls_str1_continuous called" << std::endl;
	leavingState();
	new(this) Height_Measurement;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}


TriggerProcessingState transport::ss_ls_str2_continuous(){
	std::cout << "transport: ss_ls_str1_continuous called" << std::endl;
	if (data->checkFBA1Counter() == 0){
		this->action->ak_fbm1_right_off();
		leavingState();
		new(this) Height_Measurement;
		enterByDefaultEntryPoint();
		return TriggerProcessingState::consumed;
	}
	else {
		leavingState();
		new(this) Height_Measurement;
		enterByDefaultEntryPoint();
		return TriggerProcessingState::consumed;
	}

}

TriggerProcessingState transport::ws_sorted_FBA1(){
	std::cout << "transport: ws_sorted_FBA1 called" << std::endl;
	leavingState();
	new(this) OpPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void transport::showState() {
	std::cout << "OperationFsm: Transport";
}

