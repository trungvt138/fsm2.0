//
// Created by trung on 31/05/2024.
//

#include "../mainfsm/idle.h"

#include <iostream>

#include "ws_state.h"
#include "../mainfsm/calibration_state.h"

void Idle::entry() {

	action->ak_fbm1_right_off();

    std::cout << "\n MainFsm: Idle\n" << std::endl;
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();

}


TriggerProcessingState Idle::ss_t_str1_longpressed() {
    std::cout << "Idle: ss_t_str1_longpressed called" << std::endl;
    leavingState();

    new(this) Calibration_State;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Idle::ss_t_str1_shortpressed() {
    std::cout << "Idle: ss_t_str1_shortpressed called" << std::endl;
    leavingState();

    new(this) WS_State;
    enterByDeepHistoryEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Idle::ss_t_str2_longpressed() {
    std::cout << "Idle: ss_t_str2_longpressed called" << std::endl;
    leavingState();

    new(this) Calibration_State;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Idle::ss_t_str2_shortpressed() {
    std::cout << "Idle: ss_t_str2_shortpressed called" << std::endl;
    leavingState();

    new(this) WS_State;
    enterByDeepHistoryEntryPoint();
    return TriggerProcessingState::consumed;
}

void Idle::showState() {
    std::cout << "  MainFsm: Idle" << std::endl;
}

void Idle::resetDeepHistory() {
    new(this) WS_State;
    wsstatemachine1->resetDeepHistory();
    wsstatemachine2->resetDeepHistory();
    wsstatemachine3->resetDeepHistory();
}
