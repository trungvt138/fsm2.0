//
// Created by trung on 31/05/2024.
//

#include "mainfsm.h"

#include <iostream>

#include "estoppfsm.h"

using namespace std;

void MainFsm::entry() {
    action->enteredMainFSM();
}

void MainFsm::exit() {
    cout << "Leaving MainFsm" << endl;
}

void MainFsm::ss_t_str1_longpressed() {
    cout << "MainFsm: ss_t_str1_longpressed called" << endl;
    mainsubmachine->ss_t_str1_longpressed();
}

void MainFsm::ss_t_str1_shortpressed() {
    cout << "MainFsm: ss_t_str1_shortpressed called" << endl;
    mainsubmachine->ss_t_str1_shortpressed();
}

void MainFsm::ss_t_str2_longpressed() {
    cout << "MainFsm: ss_t_str2_longpressed called" << endl;
    mainsubmachine->ss_t_str2_longpressed();
}

void MainFsm::ss_t_str2_shortpressed() {
    cout << "MainFsm: ss_t_str2_shortpressed called" << endl;
    mainsubmachine->ss_t_str2_shortpressed();
}

void MainFsm::ss_t_stp1_pressed() {
    cout << "MainFsm: ss_t_stp_pressed called" << endl;
    mainsubmachine->ss_t_stp1_pressed();
}

void MainFsm::ss_t_stp2_pressed() {
    cout << "MainFsm: ss_t_stp_pressed called" << endl;
    mainsubmachine->ss_t_stp2_pressed();
}

void MainFsm::ws_false_placement() {
    cout << "MainFsm: ws_false_placement called" << endl;
    mainsubmachine->ws_false_placement();
}

void MainFsm::ws_missing() {
    cout << "MainFsm: ws_missing called" << endl;
    mainsubmachine->ws_missing();
}

void MainFsm::both_slide_full() {
    cout << "MainFsm: both_slide_full called" << endl;
    mainsubmachine->both_slide_full();
}

void MainFsm::ss_ls_str1_continuous() {
    cout << "MainFsm: ss_ls_str1_continuous called" << endl;
    mainsubmachine->ss_ls_str1_continuous();
}

void MainFsm::ss_ls_str1_interrupted() {
    cout << "MainFsm: ss_ls_str1_interrupted called" << endl;
    mainsubmachine->ss_ls_str1_interrupted();
}

void MainFsm::lightbarrier_height1_continuous() {
    cout << "MainFsm: lightbarrier_height1_continuous called" << endl;
    mainsubmachine->lightbarrier_height1_continuous();
}

void MainFsm::lightbarrier_height1_interrupted() {
    cout << "MainFsm: lightbarrier_height1_interrupted called" << endl;
    mainsubmachine->lightbarrier_height1_interrupted();
}

void MainFsm::height_ok1_active() {
    cout << "MainFsm: height_ok1_active called" << endl;
    mainsubmachine->height_ok1_active();
}

void MainFsm::height_ok1_unactive() {
    cout << "MainFsm: height_ok1_unactive called" << endl;
    mainsubmachine->height_ok1_unactive();
}

void MainFsm::ss_ls_srt1_continuous() {
    cout << "MainFsm: ss_ls_srt1_continuous called" << endl;
    mainsubmachine->ss_ls_srt1_continuous();
}

void MainFsm::ss_ls_srt1_interrupted() {
    cout << "MainFsm: ss_ls_srt1_interrupted called" << endl;
    mainsubmachine->ss_ls_srt1_interrupted();
}

void MainFsm::ss_ms1_erkannt() {
    cout << "MainFsm: ss_ms1_erkannt called" << endl;
    mainsubmachine->ss_ms1_erkannt();
}

void MainFsm::ss_ms1_fall() {
    cout << "MainFsm: ss_ms1_fall called" << endl;
    mainsubmachine->ss_ms1_fall();
}

void MainFsm::switch1_open() {
    cout << "MainFsm: switch1_open called" << endl;
    mainsubmachine->switch1_open();
}

void MainFsm::switch1_unopen() {
    cout << "MainFsm: switch1_unopen called" << endl;
    mainsubmachine->switch1_unopen();
}

void MainFsm::ss_ls_sli1_rise() {
    cout << "MainFsm: ss_ls_sli1_rise called" << endl;
    mainsubmachine->ss_ls_sli1_rise();
}

void MainFsm::ss_ls_sli1_full() {
    cout << "MainFsm: ss_ls_sli1_full called" << endl;
    mainsubmachine->ss_ls_sli1_full();
}

void MainFsm::ss_ls_end1_continuous() {
    cout << "MainFsm: ss_ls_end1_continuous called" << endl;
    mainsubmachine->ss_ls_end1_continuous();
}

void MainFsm::ss_ls_end1_interrupted() {
    cout << "MainFsm: ss_ls_end1_interrupted called" << endl;
    mainsubmachine->ss_ls_end1_interrupted();
}

void MainFsm::ss_t_rst1_pressed() {
    cout << "MainFsm: ss_t_rst1_pressed called" << endl;
    mainsubmachine->ss_t_rst1_pressed();
}

void MainFsm::ss_t_rst2_pressed() {
    cout << "MainFsm: ss_t_rst2_pressed called" << endl;
    mainsubmachine->ss_t_rst2_pressed();
}

void MainFsm::slide1_free() {
    cout << "MainFsm: slide1_free called" << endl;
    mainsubmachine->slide1_free();
}

void MainFsm::slide2_free() {
    cout << "MainFsm: slide2_free called" << endl;
    mainsubmachine->slide2_free();
}

void MainFsm::ss_t_est1_pressed() {
    cout << "MainFsm: ss_t_est1_pressed called" << endl;
    TriggerProcessingState processing_state = mainsubmachine->ss_t_est1_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE1();
    }
}

void MainFsm::ss_t_est2_pressed() {
    cout << "MainFsm: ss_t_est2_pressed called" << endl;
    TriggerProcessingState processing_state = mainsubmachine->ss_t_est2_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE2();
    }
}

void MainFsm::connection_lost() {
    cout << "MainFsm: connection_lost called" << endl;
    TriggerProcessingState processing_state = mainsubmachine->connection_lost();
    if (processing_state == TriggerProcessingState::pending) {
        mainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortCL();
    }
}


void MainFsm::showState() {
    cout << "State: MainFsm" << endl;
    mainsubmachine->showState();
}

void MainFsm::enterByDefaultEntryPoint() {
    entry();
    mainsubmachine->enterViaPseudoStart();
}
