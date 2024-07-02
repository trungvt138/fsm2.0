/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#include "Connection_Lost.h"

#include <iostream>

#include "EST1_and_CL.h"
#include "EST2_and_CL.h"
#include "Reset.h"

TriggerProcessingState Connection_Lost::ss_t_est1_pressed() {
    std::cout << "Connection_Lost: ss_t_est1_pressed called" << std::endl;
    leavingState();
    new(this) EST1_and_CL;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Connection_Lost::ss_t_est2_pressed() {
    std::cout << "Connection_Lost: ss_t_est2_pressed called" << std::endl;
    leavingState();
    new(this) EST2_and_CL;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Connection_Lost::connection_back() {
    std::cout << "Connection_Lost: connection_back called" << std::endl;
    leavingState();
    new(this) Reset;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void Connection_Lost::showState() {
    std::cout << "  EstFsm: Connection_Lost" << std::endl;
}




