//
// Created by trung on 05/06/2024.
//

#include "../mainfsm/calibration_state.h"

#include <iostream>

#include "idle.h"

void Calibration_State::entry() {
    action->ak_l_grn1_blink_fast();
    action->ak_l_grn2_blink_fast();
    action->entered_Calibration_State();
}

void Calibration_State::exit() {
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();
}


TriggerProcessingState Calibration_State::ss_t_str1_shortpressed() {
    std::cout << "Calibration_State: ss_t_str1_shortpressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Calibration_State::ss_t_str2_shortpressed() {
    std::cout << "Calibration_State: ss_t_str2_shortpressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void Calibration_State::showState() {
    std::cout << "  MainFsm: Calibration_State" << std::endl;
}