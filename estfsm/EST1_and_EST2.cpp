/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */
 #include "EST1_and_EST2.h"

#include <iostream>

#include "EStop1_pressed.h"
#include "EStop2_pressed.h"

TriggerProcessingState EST1_and_EST2::ss_t_est1_unpressed() {
    std::cout << "EST1_and_EST2: ss_t_est1_unpressed called" << std::endl;
    leavingState();
    new(this) EStop2_pressed;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState EST1_and_EST2::ss_t_est2_unpressed() {
    std::cout << "EST1_and_EST2: ss_t_est2_unpressed called" << std::endl;
    leavingState();
    new(this) EStop1_pressed;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void EST1_and_EST2::showState() {
    std::cout << "  EstFsm: EST1_and_EST2" << std::endl;
}



