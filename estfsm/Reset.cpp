/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#include "Reset.h"

#include <iostream>

#include "Connection_Lost.h"
#include "EStop1_pressed.h"
#include "EStop2_pressed.h"
#include "estpseudoendstate.h"

void Reset::enterByDefaultEntryPoint() {
    entry();
    subfsm->enterViaPseudoStart();
}


TriggerProcessingState Reset::ss_t_est1_pressed() {
    std::cout << "Reset: ss_t_est1_pressed called" << std::endl;
    leavingState();
    new(this) EStop1_pressed;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Reset::ss_t_est2_pressed() {
    std::cout << "Reset: ss_t_est2_pressed called" << std::endl;
    leavingState();
    new(this) EStop2_pressed;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Reset::connection_lost() {
    std::cout << "Reset: connection_lost called" << std::endl;
    leavingState();
    new(this) Connection_Lost;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Reset::handleDefaultExit() {
    TriggerProcessingState processing_state = TriggerProcessingState::pending;
    if (subfsm->isPseudoEndState()) {
        leavingState();
        new(this) EstPseudoEndState;
        enterByDefaultEntryPoint();
        processing_state = TriggerProcessingState::consumed;
    }
    return processing_state;
}

TriggerProcessingState Reset::ss_t_rst1_pressed() {
    std::cout << "Reset: ss_t_rst1_pressed called" << std::endl;
    TriggerProcessingState processing_state = subfsm->ss_t_rst1_pressed();
    return processing_state;
}

TriggerProcessingState Reset::ss_t_rst2_pressed() {
    std::cout << "Reset: ss_t_rst2_pressed called" << std::endl;
    TriggerProcessingState processing_state = subfsm->ss_t_rst2_pressed();
    return processing_state;
}


void Reset::showState() {
    std::cout << "EstFsm: Reset" << std::endl;
    subfsm->showState();
}
