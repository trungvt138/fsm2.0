/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#include "EStop2_pressed.h"

#include <iostream>

#include "EST1_and_EST2.h"
#include "EST2_and_CL.h"
#include "Reset.h"

TriggerProcessingState EStop2_pressed::ss_t_est2_unpressed() {
    std::cout << "EStop2_pressed: ss_t_est2_unpressed called" << std::endl;
    leavingState();
    new(this) Reset;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState EStop2_pressed::ss_t_est1_pressed() {
    std::cout << "EStop2_pressed: ss_t_est1_pressed called" << std::endl;
    leavingState();
    new(this) EST1_and_EST2;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState EStop2_pressed::connection_lost() {
    std::cout << "EStop2_pressed: connection_lost called" << std::endl;
    leavingState();

    //if (FBA1)
    new(this) EST2_and_CL;

    //if (!FBA1)
    // new(this) Connection_Lost;

    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void EStop2_pressed::showState() {
    std::cout << "  EstFsm: EStop2_pressed" << std::endl;
}

