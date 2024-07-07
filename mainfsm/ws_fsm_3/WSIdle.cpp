/*
 * WSIdle2.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "WSIdle.h"

#include "operation_state.h"

void WSIdle3::entry() {
//    action->entered_WSIdle();
    //std::cout << "entered WSIdle" << std::endl;
	std::cout << "\nWSFsm3: WSIdle3\n" << std::endl;
	data->setFBA1(true);
}

TriggerProcessingState WSIdle3::ss_ls_str1_interrupted() {
    std::cout << "WSIdle3: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()){


			this->data->addWorkpiece(WorkPiece::StateType::WsState3);
    		this->data->wsCounterUp();
    		this->data->wsCounterUpFBA1();
    		

    		leavingState();
    		new(this) Operation_State3;
    		enterByDefaultEntryPoint();
    		return TriggerProcessingState::consumed;

    }
    else {
    	leavingState();
    	new(this) Operation_State3;
    	enterByDefaultEntryPoint();
    	return TriggerProcessingState::consumed;
   }
}

void WSIdle3::showState() {
    std::cout << "      WSFsm3: WSIdle3\n" << std::endl;
}





