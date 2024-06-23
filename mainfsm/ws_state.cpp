//
// Created by trung on 07/06/2024.
//

#include "../mainfsm/ws_state.h"

#include <iostream>

#include "idle.h"
#include "../mainfsm/error_state.h"

void WS_State::entry() {
    action->entered_WS_State();
    action->green1_On();
    action->green2_On();
}

void WS_State::exit() {
    action->green1_Off();
    action->green2_Off();
}


TriggerProcessingState WS_State::ss_t_stp_pressed() {
    std::cout << "WS_State: ss_t_stp_pressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_gone() {
    std::cout << "WS_State: ws_gone called" << std::endl;
    leavingState();
    new(this) Error_State;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_false_placement() {
    std::cout << "WS_State: ws_false_placement called" << std::endl;
    leavingState();
    new(this) Error_State;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::both_slide_full() {
    std::cout << "WS_State: both_slide_full called" << std::endl;
    leavingState();
    new(this) Error_State;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void WS_State::showState() {
    std::cout << "  MainFsm: WS State" << std::endl;
}

