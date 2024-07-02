/*
 * EStop1_pressed.cpp
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */
#include <iostream>
#include "EST2_and_CL.h"
#include "Connection_Lost.h"


TriggerProcessingState EST2_and_CL::ss_t_est2_unpressed() {
    std::cout << "EST1_and_CL: ss_t_est12_unpressed called" << std::endl;
    leavingState();
    new(this) Connection_Lost;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void EST2_and_CL::showState() {
    std::cout << "  EstFsm: EST2_and_CL" << std::endl;
}



