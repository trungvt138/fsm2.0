//
// Created by trung on 01/06/2024.
//

#include "EST1_and_CL.h"

#include <iostream>

#include "Connection_Lost.h"


TriggerProcessingState EST1_and_CL::ss_t_est1_unpressed() {
    std::cout << "EST1_and_CL: ss_t_est1_unpressed called" << std::endl;
    leavingState();
    new(this) Connection_Lost;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void EST1_and_CL::showState() {
    std::cout << "EstFsm: EST1_and_CL" << std::endl;
}


