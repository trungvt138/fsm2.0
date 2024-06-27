//
// Created by trung on 31/05/2024.
//

#include "mainbasestate.h"
#include "idle.h"
#include "ws_fsm/wspseudostartstate.h"


void MainBaseState::initSubStateMachines(){
    wsstatemachine = new WSPseudoStartState();
    wsstatemachine->initSubStateMachines();
    errorsubmachine = new ErrorBaseState();
    errorsubmachine->initSubStateMachines();
}

void MainBaseState::setData(ContextData *data){
    this->data = data;
    wsstatemachine->setData(data);
}

void MainBaseState::setAction(Actions *action){
    this->action = action;
    wsstatemachine->setAction(action);
}

void MainBaseState::enterViaPseudoStart() {
    std::cout << "MainFsm Initial Trasition taken" << std::endl;
    new(this) Idle;
    enterByDefaultEntryPoint();
}

void MainBaseState::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

