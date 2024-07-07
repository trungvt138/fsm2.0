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
	data->setFBA1(true);
}

TriggerProcessingState WSIdle::ss_ls_str1_interrupted() {
    std::cout << "WSIdle: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()) {

    		this->data->wsCounterUp();
    		this->data->wsCounterUpFBA1();
    		this->data->addWorkpiece(WorkPiece::StateType::WsState1);
    		leavingState();
    		new(this) Operation_State;
    		enterByDefaultEntryPoint();
    		return TriggerProcessingState::consumed;
    }
    if (this->data->checkFBA2()) {
    	leavingState();
    	new(this) Operation_State;
    	enterByDefaultEntryPoint();
    	return TriggerProcessingState::consumed;
   }
	return TriggerProcessingState::pending;
}

void WSIdle::showState() {
    std::cout << "      WSFsm: WSIdle" << std::endl;
}





