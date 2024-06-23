//
// Created by trung on 07/06/2024.
//

#include "../mainfsm/error_state.h"

#include <iostream>


void Error_State::entry() {
    action->entered_Error_State();
    action->red1_On();
    action->red2_On();
    action->motor1_Off();
    action->motor2_Off();
}

void Error_State::exit() {
    action->red1_On();
    action->red2_On();
}

void Error_State::showState() {
    std::cout << "  MainFsm: Error_State" << std::endl;
}


