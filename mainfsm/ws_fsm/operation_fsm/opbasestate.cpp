/*
 * opbasestate.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "opbasestate.h"

#include "transport.h"
#include "hm_fsm/hmpseudostartstate.h"
#include "sorting_fsm/sortingpseudostartstate.h"
#include "transfering_fsm/transferingpseudostartstate.h"

void OpBaseState::enterViaPseudoStart() {
    std::cout << "OperationFSM Initial Trasition taken" << std::endl;
    new(this) Transport;
    enterByDefaultEntryPoint();
}

void OpBaseState::initSubStateMachines(){
    hmstatemachine = new HMPseudoStartState();
    hmstatemachine->initSubStateMachines();

    sortingstatemachine = new SortingPseudoStartState();
    sortingstatemachine->initSubStateMachines();

    transferingstatemachine = new TransferingPseudoStartState();
    transferingstatemachine->initSubStateMachines();
}


void OpBaseState::setAction(Actions *action){
    this->action = action;
    hmstatemachine->setAction(action);
    sortingstatemachine->setAction(action);
    transferingstatemachine->setAction(action);
}


void OpBaseState::setData(ContextData *data){
    this->data = data;
    hmstatemachine->setData(data);
    sortingstatemachine->setData(data);
    transferingstatemachine->setData(data);
}

void OpBaseState::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}


// TriggerProcessingState OpBaseState::handleDefaultExit(const TriggerProcessingState &handled) {
//     return TriggerProcessingState::pending;
// };

