//
// Created by trung on 31/05/2024.
//

#include "mainbasestate.h"
#include "idle.h"
#include "ws_fsm/wspseudostartstate.h"




void MainBaseState::enterViaPseudoStart() {
    std::cout << "MainFsm Initial Trasition taken" << std::endl;
    new(this) Idle;
    enterByDefaultEntryPoint();
}

void MainBaseState::initSubStateMachines() {
	errorsubmachine = new ErrorBaseState();
	errorsubmachine->initSubStateMachines();

    wsstatemachine = new WSPseudoStartState();
    wsstatemachine->initSubStateMachines();

    calibrationsubmachine = new CalibrationBaseState();
    calibrationsubmachine->initSubStateMachines();
}

void MainBaseState::setAction(Actions *action) {
	this->action = action;
	errorsubmachine->setAction(action);
    wsstatemachine->setAction(action);
    calibrationsubmachine->setAction(action);
}

void MainBaseState::setData(ContextData *data) {
	this->data = data;
	errorsubmachine->setData(data);
	wsstatemachine->setData(data);
    calibrationsubmachine->setData(data);
}

void MainBaseState::enterViaDeepHistory() {
	enterByDeepHistoryEntryPoint();
}