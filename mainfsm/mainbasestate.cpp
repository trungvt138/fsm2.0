//
// Created by trung on 31/05/2024.
//

#include "mainbasestate.h"
#include "idle.h"
#include "ws_fsm/wspseudostartstate.h"
#include "ws_fsm_2/wspseudostartstate.h"
#include "ws_fsm_3/wspseudostartstate.h"


void MainBaseState::enterViaPseudoStart() {
    std::cout << "  MainFsm Initial Trasition taken" << std::endl;
    new(this) Idle;
    enterByDefaultEntryPoint();
}

void MainBaseState::initSubStateMachines() {
	errorsubmachine = new ErrorBaseState();
	errorsubmachine->initSubStateMachines();

    wsstatemachine1 = new WSPseudoStartState();
    wsstatemachine1->initSubStateMachines();

	wsstatemachine2 = new WSPseudoStartState2();
	wsstatemachine2->initSubStateMachines();

	wsstatemachine3 = new WSPseudoStartState3();
	wsstatemachine3->initSubStateMachines();

    calibrationsubmachine = new CalibrationBaseState();
    calibrationsubmachine->initSubStateMachines();
}

void MainBaseState::setAction(Actions *action) {
	this->action = action;
	errorsubmachine->setAction(action);
    wsstatemachine1->setAction(action);
	wsstatemachine2->setAction(action);
	wsstatemachine3->setAction(action);
    calibrationsubmachine->setAction(action);
}

void MainBaseState::setData(ContextData *data) {
	this->data = data;
	errorsubmachine->setData(data);
	wsstatemachine1->setData(data);
	wsstatemachine2->setData(data);
	wsstatemachine3->setData(data);
    calibrationsubmachine->setData(data);
}

void MainBaseState::enterViaDeepHistory() {
	enterByDeepHistoryEntryPoint();
}