/*
 * WSIdle.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "WSIdle.h"

#include "operation_state.h"

void WSIdle::entry() {
//  showState();
	std::cout << "\nWSFsm: WSIdle\n" << std::endl;

}

TriggerProcessingState WSIdle::ss_ls_str1_interrupted() {
    std::cout << "WSIdle: ss_ls_str1_interrupted called" << std::endl;
	data->setFBA1();
	this->data->wsCounterUp();
	this->data->wsCounterUpFBA1();
	this->data->addWorkpiece(WorkPiece::StateType::WsState1);
	leavingState();
	new(this) Operation_State;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState WSIdle::ss_ls_str2_interrupted() {
	std::cout << "WSIdle: ss_ls_str2_interrupted called" << std::endl;
	data->setFBA2();
	data->wsCounterUpFBA2();
	data->wsCounterDownFBA1();
	leavingState();
	new(this) Operation_State;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

void WSIdle::showState() {
    std::cout << "      WSFsm: WSIdle" << std::endl;
}





