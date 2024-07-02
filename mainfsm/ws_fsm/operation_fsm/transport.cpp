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

void Transport::entry() {
    std::cout << "Transport Entry" << std::endl;
//    action->entered_Operation_State();
    this->data->checkFBA1Counter();
}

TriggerProcessingState Transport::ss_ls_str1_continuous(){
	std::cout << "Transport: ss_ls_str1_continuous called" << std::endl;
	if (data->checkFBA1()) {
		leavingState();
		new(this) Height_Measurement;
		enterByDefaultEntryPoint();
		return TriggerProcessingState::consumed;
	}
	return TriggerProcessingState::pending;
}


TriggerProcessingState Transport::ss_ls_str2_continuous(){
	std::cout << "Transport: ss_ls_str2_continuous called" << std::endl;
	if (data->checkFBA2()) {
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

TriggerProcessingState Transport::ws_sorted_FBA1(){
	std::cout << "Transport: ws_sorted_FBA1 called" << std::endl;
	leavingState();
	new(this) OpPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void Transport::showState() {
	std::cout << "        OperationFsm: Transport" << std::endl;;
}

