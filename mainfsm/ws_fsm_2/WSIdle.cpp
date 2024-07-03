/*
 * WSIdle2.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "WSIdle.h"

#include "operation_state.h"

void WSIdle2::entry() {
//    action->entered_WSIdle();
    //std::cout << "entered WSIdle" << std::endl;
	std::cout << "\nWSFsm2: WSIdle2\n" << std::endl;
	data->setFBA1(true);
}

TriggerProcessingState WSIdle2::ss_ls_str1_interrupted() {
    std::cout << "WSIdle2: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()){



    		this->data->wsCounterUp();
    		this->data->wsCounterUpFBA1();
    		this->data->setID(2);

    		leavingState();
    		new(this) Operation_State2;
    		enterByDefaultEntryPoint();
    		return TriggerProcessingState::consumed;

    }
    else {
    	leavingState();
    	new(this) Operation_State2;
    	enterByDefaultEntryPoint();
    	return TriggerProcessingState::consumed;
   }
}

void WSIdle2::showState() {
    std::cout << "\nWSFsm2: WSIdle2" << std::endl;
}





