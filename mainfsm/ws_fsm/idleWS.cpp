/*
 * idleWS.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "idleWS.h"

#include "operation_state.h"

void idleWS::entry() {
//    action->entered_WSIdle();
    //std::cout << "entered WSIdle" << std::endl;
}

TriggerProcessingState idleWS::ss_ls_str1_interrupted() {
    std::cout << "idleWS: ss_ls_str1_interrupted called" << std::endl;
    if (this->data->checkFBA1()){
    	action->ak_fbm1_right_on();
    	this->data->wsCounterUp();
    	this->data->wsCounterUpFBA1();
    	//TODO: ws_count
    	this->data->setID(1);
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

void idleWS::showState() {
    std::cout << "  WSFSM: WSIdle" << std::endl;
}





