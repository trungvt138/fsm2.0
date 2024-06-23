//
// Created by trung on 31/05/2024.
//

#include "estbasestate.h"

#include <iostream>

#include "Connection_Lost.h"
#include "EStop1_pressed.h"
#include "EStop2_pressed.h"
#include "../resetfsm/resetpseudostartstate.h"

void EstBaseState::initSubStateMachines() {
    subfsm = new ResetPseudoStartState();
    subfsm->initSubStateMachines();
}

void EstBaseState::enterViaPortE1() {
    std::cout << "EStoppFSM E1 Trasition taken" << std::endl;
    new(this) EStop1_pressed;
}

void EstBaseState::enterViaPortE2() {
    std::cout << "EStoppFSM E2 Trasition taken" << std::endl;
    new(this) EStop2_pressed;
}

void EstBaseState::enterViaPortCL() {
    std::cout << "EStoppFSM CL Trasition taken" << std::endl;
    new(this) Connection_Lost;
}

