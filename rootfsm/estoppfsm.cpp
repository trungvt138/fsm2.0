//
// Created by trung on 01/06/2024.
//

#include "estoppfsm.h"

#include <iostream>

#include "mainfsm.h"

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
    action->ak_fbm1_right_off();
    action->ak_fbm2_right_off();
    action->ak_l_rot1_on();
    action->ak_l_rot2_on();
}

void EStoppFSM::exit() {
    action->ak_l_rot1_off();
    action->ak_l_rot2_off();
}

void EStoppFSM::handleDefaultExit(const TriggerProcessingState &processing_state) {
    if (processing_state == TriggerProcessingState::endstatereached) {
        estoppsubmachine->exit();
        leavingState();
        new(this) MainFsm;
        enterByDefaultEntryPoint();
    }
}

void EStoppFSM::ss_t_est1_pressed() {
    std::cout << "EStoppFsm: ss_t_est1_pressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_est1_pressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::ss_t_est2_pressed() {
    std::cout << "EStoppFsm: ss_t_est2_pressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_est2_pressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::ss_t_est1_unpressed() {
    std::cout << "EStoppFsm: ss_t_est1_unpressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_est1_unpressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::ss_t_est2_unpressed() {
    std::cout << "EStoppFsm: ss_t_est2_unpressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_est2_unpressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::connection_lost() {
    std::cout << "EStoppFsm: connection_lost called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->connection_lost();
    handleDefaultExit(processing_state);
}

void EStoppFSM::connection_back() {
    std::cout << "EStoppFsm: connection_back called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->connection_back();
    handleDefaultExit(processing_state);
}

void EStoppFSM::ss_t_rst1_pressed() {
    std::cout << "EStoppFsm: ss_t_rst1_pressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_rst1_pressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::ss_t_rst2_pressed() {
    std::cout << "EStoppFsm: ss_t_rst2_pressed called" << std::endl;
    TriggerProcessingState processing_state = estoppsubmachine->ss_t_rst2_pressed();
    handleDefaultExit(processing_state);
}

void EStoppFSM::showState() {
    std::cout << "State: EStoppFsm" << std::endl;
    estoppsubmachine->showState();
}


