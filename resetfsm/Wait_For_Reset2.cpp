//
// Created by trung on 24/06/2024.
//

#include "Wait_For_Reset2.h"

#include <iostream>

#include "resetpseudoendstate.h"
void Wait_For_Reset2::entry() {
    std::cout << "\n    State: Wait_For_Reset2 State" << std::endl;
}

TriggerProcessingState Wait_For_Reset2::ss_t_rst2_pressed() {
    std::cout << "Wait_For_Reset2: ss_t_rst2_pressed called" << std::endl;

    leavingState();
    // Transition action
    new(this) ResetPseudoEndState;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::endstatereached;
}

void Wait_For_Reset2::showState() {
    std::cout << "\n    State: Wait_For_Reset2 State" << std::endl;
}