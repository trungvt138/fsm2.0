//
// Created by trung on 24/06/2024.
//

#include "Wait_For_Reset1.h"

#include <iostream>

#include "resetpseudoendstate.h"

TriggerProcessingState Wait_For_Reset1::ss_t_rst1_pressed() {
    std::cout << "Wait_For_Reset1: ss_t_rst1_pressed called" << std::endl;

    leavingState();
    // Transition action
    new(this) ResetPseudoEndState;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::endstatereached;
}

void Wait_For_Reset1::showState() {
    std::cout << "State: Wait_For_Reset1 State" << std::endl;
}
