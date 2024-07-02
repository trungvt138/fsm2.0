/*
 * WSIdle.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "WSIdle.h"

#include "operation_state.h"

void WSIdle::entry() {
//    action->entered_WSIdle();
    //std::cout << "entered WSIdle" << std::endl;
	data->negateFBA1();
}

TriggerProcessingState WSIdle::ss_ls_str1_interrupted() {
    std::cout << "WSIdle: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()) {

    		action->ak_fbm1_right_on();

    		this->data->wsCounterUp();
    		this->data->wsCounterUpFBA1();
    		this->data->setID(1);

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
}

void WSIdle::showState() {
    std::cout << "      WSFsm: WSIdle" << std::endl;
}





