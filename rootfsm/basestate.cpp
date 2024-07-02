//
// Created by trung on 31/05/2024.
//


#include "../mainfsm/mainpseudostartstate.h"
#include "mainfsm.h"

#include "../estfsm/estpseudostartstate.h"

#include "basestate.h"

#include "orthmainfsm.h"
#include "../checkslidefsm/checkslidepseudostartstate.h"
#include "../mainfsm/idle.h"
#include "../orthmainfsm/orthmainbasestate.h"
#include "../orthmainfsm/orthmainpseudostartstate.h"


void BaseState::initSubStateMachines() {
    orthmainsubmachine = new OrthMainBaseState();
    orthmainsubmachine->initSubStateMachines();

    estoppsubmachine = new EstBaseState();
    estoppsubmachine->initSubStateMachines();
}

void BaseState::setData(ContextData *data){
    this->data = data;
    estoppsubmachine->setData(data);
    orthmainsubmachine->setData(data);
}

void BaseState::setAction(Actions *action){
    this->action = action;
    estoppsubmachine->setAction(action);
    orthmainsubmachine->setAction(action);
}

void BaseState::enterViaPseudoStart(){
    // go from pseudo-start state to first state
    std::cout << "Initial transition taken" << std::endl;
    data->clearErrorCounter();    // init-transition action
    new(this) OrthMainFsm;
    enterByDefaultEntryPoint();   // Entry of initial state
}
