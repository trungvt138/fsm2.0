/*
 * WSIdle2.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "WSIdle.h"

#include "../ws_fsm/operation_state.h"

void WSIdle2::entry() {
//    action->entered_WSIdle();
    //std::cout << "entered WSIdle" << std::endl;
	data->negateFBA1();
}

TriggerProcessingState WSIdle2::ss_ls_str1_interrupted() {
    std::cout << "WSIdle2: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()){

    		action->ak_fbm1_right_on();

    		this->data->wsCounterUp();
    		this->data->wsCounterUpFBA1();
    		this->data->setID(2);

    		leavingState();
    		new(this) Operation_State;
    		enterByDefaultEntryPoint();
    		return TriggerProcessingState::consumed;

    }
    else {
    	leavingState();
    	new(this) Operation_State;
    	enterByDefaultEntryPoint();
    	return TriggerProcessingState::consumed;
   }
}

void WSIdle2::showState() {
    std::cout << "      WSFsm: WSIdle2" << std::endl;
}





