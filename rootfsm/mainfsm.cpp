//
// Created by trung on 31/05/2024.
//

#include "mainfsm.h"
#include "../estfsm/Connection_Lost.h"
#include "../estfsm/EStop1_pressed.h"
#include "../estfsm/EStop2_pressed.h"

#include <iostream>

#include "estoppfsm.h"

void MainFsm::entry() {
    action->enteredMainFSM();
}

void MainFsm::exit() {
    std::cout << "Leaving MainFsm" << std::endl;
}

void MainFsm::ss_t_str_longpressed() {
    std::cout << "MainFsm: ss_t_str_longpressed called" << std::endl;
    mainsubmachine->ss_t_str_longpressed();
}

void MainFsm::ss_t_str_shortpressed() {
    std::cout << "MainFsm: ss_t_str_shortpressed called" << std::endl;
    mainsubmachine->ss_t_str_shortpressed();
}

void MainFsm::ss_t_stp_pressed() {
    std::cout << "MainFsm: ss_t_stp_pressed called" << std::endl;
    mainsubmachine->ss_t_stp_pressed();
}

void MainFsm::ws_false_placement() {
    std::cout << "MainFsm: ws_false_placement called" << std::endl;
    mainsubmachine->ws_false_placement();
}

void MainFsm::ws_gone() {
    std::cout << "MainFsm: ws_gone called" << std::endl;
    mainsubmachine->ws_gone();
}

void MainFsm::both_slide_full() {
    std::cout << "MainFsm: both_slide_full called" << std::endl;
    mainsubmachine->both_slide_full();
}

void MainFsm::ss_t_est1_pressed() {
    std::cout << "MainFsm: ss_t_est1_pressed called" << std::endl;
    TriggerProcessingState processing_state = mainsubmachine->ss_t_est1_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE1();
    }
}

void MainFsm::ss_t_est2_pressed() {
    std::cout << "MainFsm: ss_t_est2_pressed called" << std::endl;
    TriggerProcessingState processing_state = mainsubmachine->ss_t_est2_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE2();
    }
}

void MainFsm::connection_lost() {
    std::cout << "MainFsm: connection_lost called" << std::endl;
    TriggerProcessingState processing_state = mainsubmachine->connection_lost();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortCL();
    }
}


void MainFsm::showState() {
    std::cout << "State: MainFsm" << std::endl;
    mainsubmachine->showState();
}

void MainFsm::enterByDefaultEntryPoint() {
    entry();
    mainsubmachine->enterViaPseudoStart();
}
