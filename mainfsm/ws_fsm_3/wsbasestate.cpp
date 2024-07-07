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

void WSBaseState3::enterViaPseudoStart() {
    std::cout << "WSFsm2 Initial Trasition taken" << std::endl;
    new(this) WSIdle3;
    enterByDefaultEntryPoint();
}

void WSBaseState3::initSubStateMachines(){
    opstatemachine = new OpPseudoStartState();
    opstatemachine->initSubStateMachines();
}


void WSBaseState3::setAction(Actions *action){
    this->action = action;
    opstatemachine->setAction(action);
}


void WSBaseState3::setData(ContextData *data){
    this->data = data;
    opstatemachine->setData(data);
}

void WSBaseState3::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

//TriggerProcessingState WSBaseState::handleDefaultExit(const TriggerProcessingState &handled) {
//    return TriggerProcessingState::pending;
//};

