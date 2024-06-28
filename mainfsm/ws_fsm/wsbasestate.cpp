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

void wsbasestate::enterViaPseudoStart() {
    std::cout << "WSFsm Initial Trasition taken" << std::endl;
    new(this) idleWS;
    enterByDefaultEntryPoint();
}

void wsbasestate::initSubStateMachines(){
    opstatemachine = new OpPseudoStartState();
    opstatemachine->initSubStateMachines();
}


void wsbasestate::setAction(Actions *action){
    this->action = action;
    opstatemachine->setAction(action);
}


void wsbasestate::setData(ContextData *data){
    this->data = data;
    opstatemachine->setData(data);
}

void wsbasestate::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

//TriggerProcessingState wsbasestate::handleDefaultExit(const TriggerProcessingState &handled) {
//    return TriggerProcessingState::pending;
//};

