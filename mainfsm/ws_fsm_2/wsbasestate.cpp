/*
 * wsbasestate.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "wsbasestate.h"
#include "WSIdle.h"
#include <iostream>

#include "../ws_fsm/operation_fsm/oppseudostartstate.h"

void WSBaseState2::enterViaPseudoStart() {
    std::cout << "WSFsm2 Initial Trasition taken" << std::endl;
    new(this) WSIdle2;
    enterByDefaultEntryPoint();
}

void WSBaseState2::initSubStateMachines(){
    opstatemachine = new OpPseudoStartState();
    opstatemachine->initSubStateMachines();
}


void WSBaseState2::setAction(Actions *action){
    this->action = action;
    opstatemachine->setAction(action);
}


void WSBaseState2::setData(ContextData *data){
    this->data = data;
    opstatemachine->setData(data);
}

void WSBaseState2::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

//TriggerProcessingState WSBaseState::handleDefaultExit(const TriggerProcessingState &handled) {
//    return TriggerProcessingState::pending;
//};

