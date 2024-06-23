//
// Created by trung on 01/06/2024.
//

#include "estoppfsm.h"

#include <iostream>

void EStoppFSM::enterViaPortE1() {
    entry();
    estoppsubmachine->enterViaPortE1();
}

void EStoppFSM::enterViaPortE2() {
    entry();
    estoppsubmachine->enterViaPortE2();
}

void EStoppFSM::enterViaPortCL() {
    entry();
    estoppsubmachine->enterViaPortCL();
}

void EStoppFSM::entry() {
    action->motor1_Off();
    action->motor2_Off();
    action->red1_On();
    action->red2_On();
}

void EStoppFSM::exit() {
    action->red1_Off();
    action->red2_Off();
}


void EStoppFSM::ss_t_est1_pressed() {
    std::cout << "EStoppFsm: ss_t_est1_pressed called" << std::endl;
    estoppsubmachine->ss_t_est1_pressed();
}

void EStoppFSM::ss_t_est2_pressed() {
    std::cout << "EStoppFsm: ss_t_est2_pressed called" << std::endl;
    estoppsubmachine->ss_t_est2_pressed();
}

void EStoppFSM::ss_t_est1_unpressed() {
    std::cout << "EStoppFsm: ss_t_est1_unpressed called" << std::endl;
    estoppsubmachine->ss_t_est1_unpressed();
}

void EStoppFSM::ss_t_est2_unpressed() {
    std::cout << "EStoppFsm: ss_t_est2_unpressed called" << std::endl;
    estoppsubmachine->ss_t_est2_unpressed();
}

void EStoppFSM::connection_lost() {
    std::cout << "EStoppFsm: connection_lost called" << std::endl;
    estoppsubmachine->connection_lost();
}

void EStoppFSM::connection_back() {
    std::cout << "EStoppFsm: connection_back called" << std::endl;
    estoppsubmachine->connection_back();
}

void EStoppFSM::showState() {
    std::cout << "State: EStoppFsm" << std::endl;
    estoppsubmachine->showState();
}


