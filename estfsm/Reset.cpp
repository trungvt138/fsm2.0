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
    return
}


void Reset::ss_t_rst1_pressed() {
    std::cout << "Reset: ss_t_rst1_pressed called" << std::endl;
    subfsm->
}

void Reset::ss_t_rst2_pressed() {
    std::cout << "Reset: ss_t_rst2_pressed called" << std::endl;
}


void Reset::showState() {
    std::cout << "State: Reset" << std::endl;
}
