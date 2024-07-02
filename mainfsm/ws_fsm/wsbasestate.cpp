/*
 * wsbasestate.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "wsbasestate.h"
#include "idleWS.h"
#include <iostream>

#include "operation_fsm/oppseudostartstate.h"

void WSBaseState::enterViaPseudoStart() {
    std::cout << "WSFsm Initial Trasition taken" << std::endl;
    new(this) idleWS;
    enterByDefaultEntryPoint();
}

void WSBaseState::initSubStateMachines(){
    opstatemachine = new OpPseudoStartState();
    opstatemachine->initSubStateMachines();
}


void WSBaseState::setAction(Actions *action){
    this->action = action;
    opstatemachine->setAction(action);
}


void WSBaseState::setData(ContextData *data){
    this->data = data;
    opstatemachine->setData(data);
}

void WSBaseState::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

//TriggerProcessingState WSBaseState::handleDefaultExit(const TriggerProcessingState &handled) {
//    return TriggerProcessingState::pending;
//};

