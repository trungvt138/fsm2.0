/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */
#include "EStop1_pressed.h"

#include <iostream>

#include "EST1_and_CL.h"
#include "EST1_and_EST2.h"
#include "Reset.h"

TriggerProcessingState EStop1_pressed::ss_t_est1_unpressed() {
    std::cout << "EStop1_pressed: ss_t_est1_unpressed called" << std::endl;
    leavingState();
    new(this) Reset;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState EStop1_pressed::ss_t_est2_pressed() {
    std::cout << "EStop1_pressed: ss_t_est2_pressed called" << std::endl;
    leavingState();
    new(this) EST1_and_EST2;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState EStop1_pressed::connection_lost() {
    std::cout << "EStop1_pressed: connection_lost called" << std::endl;
    leavingState();

    //if (FBA1)
    new(this) EST1_and_CL;

    //if (!FBA1)
    // new(this) Connection_Lost;

    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void EStop1_pressed::showState() {
    std::cout << "EstFsm: EStop1_pressed" << std::endl;
}



