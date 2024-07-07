//
// Created by trung on 24/06/2024.
//

#include "resetidle.h"

#include <iostream>

#include "Wait_For_Reset1.h"
#include "Wait_For_Reset2.h"
#include "resetpseudoendstate.h"

void ResetIdle::entry() {
    std::cout << "\n    State: Reset Idle" << std::endl;
}



TriggerProcessingState ResetIdle::ss_t_rst1_pressed() {
    std::cout << "ResetIdle: ss_t_rst1_pressed called" << std::endl;

    leavingState();
    // Transition action
    new(this) Wait_For_Reset2;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;

}

TriggerProcessingState ResetIdle::ss_t_rst2_pressed() {
    std::cout << "ResetIdle: ss_t_rst2_pressed called" << std::endl;

    leavingState();
    // Transition action
    new(this) Wait_For_Reset1;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void ResetIdle::showState() {
    std::cout << "\n    State: Reset Idle" << std::endl;
}
