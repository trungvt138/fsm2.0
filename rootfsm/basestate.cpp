//
// Created by trung on 31/05/2024.
//


#include "../mainfsm/mainpseudostartstate.h"
#include "mainfsm.h"

#include "../estfsm/estpseudostartstate.h"

#include "basestate.h"

#include "../mainfsm/idle.h"


void BaseState::initSubStateMachines() {
    mainsubmachine = new MainPseudoStartState();
    mainsubmachine->initSubStateMachines();

    estoppsubmachine = new EstBaseState();
    estoppsubmachine->initSubStateMachines();
}

void BaseState::setData(ContextData *data){
    this->data = data;
    // estoppsubmachine->setData(data);
    mainsubmachine->setData(data);
}

void BaseState::setAction(Actions *action){
    this->action = action;
    // estoppsubmachine->setAction(action);
    mainsubmachine->setAction(action);
}

void BaseState::enterViaPseudoStart(){
    // go from pseudo-start state to first state
    std::cout << "Initial transition taken" << std::endl;
    data->clearErrorCounter();    // init-transition action
    new(this) MainFsm;
    enterByDefaultEntryPoint();   // Entry of initial state
}
