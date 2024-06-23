//
// Created by trung on 05/06/2024.
//

#include "../mainfsm/calibration_state.h"

#include <iostream>

#include "idle.h"

void Calibration_State::entry() {
    action->green1_Blink_Fast();
    action->green2_Blink_Fast();
    action->entered_Calibration_State();
}

void Calibration_State::exit() {
    action->green1_Off();
    action->green2_Off();
}


TriggerProcessingState Calibration_State::ss_t_str_shortpressed() {
    std::cout << "Calibration_State: ss_t_str_shortpressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void Calibration_State::showState() {
    std::cout << "  MainFsm: Calibration_State" << std::endl;
}