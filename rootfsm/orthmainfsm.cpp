//
// Created by trung on 30/06/2024.
//

#include "orthmainfsm.h"

//
// Created by trung on 31/05/2024.
//


#include <iostream>

#include "estoppfsm.h"

using namespace std;

void OrthMainFsm::entry() {
    std::cout << "\nState: OrthMainFsm" << std::endl;
}

void OrthMainFsm::exit() {
    cout << "Leaving OrthMainFsm" << endl;
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();
}

void OrthMainFsm::ss_t_str1_longpressed() {
    cout << "OrthMainFsm: ss_t_str1_longpressed called" << endl;
    orthmainsubmachine->ss_t_str1_longpressed();
}

void OrthMainFsm::ss_t_str1_shortpressed() {
    cout << "OrthMainFsm: ss_t_str1_shortpressed called" << endl;
    orthmainsubmachine->ss_t_str1_shortpressed();
}

void OrthMainFsm::ss_t_str2_longpressed() {
    cout << "OrthMainFsm: ss_t_str2_longpressed called" << endl;
    orthmainsubmachine->ss_t_str2_longpressed();
}

void OrthMainFsm::ss_t_str2_shortpressed() {
    cout << "OrthMainFsm: ss_t_str2_shortpressed called" << endl;
    orthmainsubmachine->ss_t_str2_shortpressed();
}

void OrthMainFsm::ss_t_stp1_pressed() {
    cout << "OrthMainFsm: ss_t_stp_pressed called" << endl;
    orthmainsubmachine->ss_t_stp1_pressed();
}

void OrthMainFsm::ss_t_stp2_pressed() {
    cout << "OrthMainFsm: ss_t_stp_pressed called" << endl;
    orthmainsubmachine->ss_t_stp2_pressed();
}

void OrthMainFsm::ws_false_placement() {
    cout << "OrthMainFsm: ws_false_placement called" << endl;
    orthmainsubmachine->ws_false_placement();
}

void OrthMainFsm::ws_missing() {
    cout << "OrthMainFsm: ws_missing called" << endl;
    orthmainsubmachine->ws_missing();
}

void OrthMainFsm::both_slide_full() {
    cout << "OrthMainFsm: both_slide_full called" << endl;
    orthmainsubmachine->both_slide_full();
}

void OrthMainFsm::ss_ls_str1_continuous() {
    cout << "OrthMainFsm: ss_ls_str1_continuous called" << endl;
    orthmainsubmachine->ss_ls_str1_continuous();
}

void OrthMainFsm::ss_ls_str1_interrupted() {
    cout << "OrthMainFsm: ss_ls_str1_interrupted called" << endl;
    orthmainsubmachine->ss_ls_str1_interrupted();
}

void OrthMainFsm::lightbarrier_height1_continuous() {
    cout << "OrthMainFsm: lightbarrier_height1_continuous called" << endl;
    orthmainsubmachine->lightbarrier_height1_continuous();
}

void OrthMainFsm::lightbarrier_height1_interrupted() {
    cout << "OrthMainFsm: lightbarrier_height1_interrupted called" << endl;
    orthmainsubmachine->lightbarrier_height1_interrupted();
}

void OrthMainFsm::height_ok1_active() {
    cout << "OrthMainFsm: height_ok1_active called" << endl;
    orthmainsubmachine->height_ok1_active();
}

void OrthMainFsm::height_ok1_unactive() {
    cout << "OrthMainFsm: height_ok1_unactive called" << endl;
    orthmainsubmachine->height_ok1_unactive();
}

void OrthMainFsm::ss_ls_srt1_continuous() {
    cout << "OrthMainFsm: ss_ls_srt1_continuous called" << endl;
    orthmainsubmachine->ss_ls_srt1_continuous();
}

void OrthMainFsm::ss_ls_srt1_interrupted() {
    cout << "OrthMainFsm: ss_ls_srt1_interrupted called" << endl;
    orthmainsubmachine->ss_ls_srt1_interrupted();
}

void OrthMainFsm::ss_ms1_erkannt() {
    cout << "OrthMainFsm: ss_ms1_erkannt called" << endl;
    orthmainsubmachine->ss_ms1_erkannt();
}

void OrthMainFsm::ss_ms1_fall() {
    cout << "OrthMainFsm: ss_ms1_fall called" << endl;
    orthmainsubmachine->ss_ms1_fall();
}

void OrthMainFsm::switch1_open() {
    cout << "OrthMainFsm: switch1_open called" << endl;
    orthmainsubmachine->switch1_open();
}

void OrthMainFsm::switch1_unopen() {
    cout << "OrthMainFsm: switch1_unopen called" << endl;
    orthmainsubmachine->switch1_unopen();
}

void OrthMainFsm::ss_ls_sli1_rise() {
    cout << "OrthMainFsm: ss_ls_sli1_rise called" << endl;
    orthmainsubmachine->ss_ls_sli1_rise();
}

void OrthMainFsm::ss_ls_sli1_full() {
    cout << "OrthMainFsm: ss_ls_sli1_full called" << endl;
    orthmainsubmachine->ss_ls_sli1_full();
}

void OrthMainFsm::ss_ls_end1_continuous() {
    cout << "OrthMainFsm: ss_ls_end1_continuous called" << endl;
    orthmainsubmachine->ss_ls_end1_continuous();
}

void OrthMainFsm::ss_ls_end1_interrupted() {
    cout << "OrthMainFsm: ss_ls_end1_interrupted called" << endl;
    orthmainsubmachine->ss_ls_end1_interrupted();
}

void OrthMainFsm::ss_t_rst1_pressed() {
    cout << "OrthMainFsm: ss_t_rst1_pressed called" << endl;
    orthmainsubmachine->ss_t_rst1_pressed();
}

void OrthMainFsm::ss_t_rst2_pressed() {
    cout << "OrthMainFsm: ss_t_rst2_pressed called" << endl;
    orthmainsubmachine->ss_t_rst2_pressed();
}

void OrthMainFsm::slide1_free() {
    cout << "OrthMainFsm: slide1_free called" << endl;
    orthmainsubmachine->slide1_free();
}

void OrthMainFsm::slide2_free() {
    cout << "OrthMainFsm: slide2_free called" << endl;
    orthmainsubmachine->slide2_free();
}

void OrthMainFsm::unwanted_ws() {
    cout << "OrthMainFsm: unwanted_ws called" << endl;
    orthmainsubmachine->unwanted_ws();
}

void OrthMainFsm::right_order() {
    cout << "OrthMainFsm: right_order called" << endl;
    orthmainsubmachine->right_order();
}

void OrthMainFsm::height_calibration() {
    cout << "OrthMainFsm: height_calibration called" << endl;
    orthmainsubmachine->height_calibration();
}


void OrthMainFsm::ws_gone() {
    cout << "OrthMainFsm: ws_gone called" << endl;
    orthmainsubmachine->ws_gone();
}

void OrthMainFsm::height_high() {
    cout << "OrthMainFsm: height_high called" << endl;
    orthmainsubmachine->height_high();
}

void OrthMainFsm::height_flat() {
    cout << "OrthMainFsm: height_flat called" << endl;
    orthmainsubmachine->height_flat();
}

void OrthMainFsm::height_hole() {
    cout << "OrthMainFsm: height_hole called" << endl;
    orthmainsubmachine->height_hole();
}

void OrthMainFsm::height_band() {
    cout << "OrthMainFsm: height_band called" << endl;
    orthmainsubmachine->height_band();
}

void OrthMainFsm::ss_t_str1_unpressed() {
    cout << "OrthMainFsm: ss_t_str1_unpressed called" << endl;
    orthmainsubmachine->ss_t_str1_unpressed();
}

void OrthMainFsm::ss_t_stp1_unpressed() {
    cout << "OrthMainFsm: ss_t_stp1_unpressed called" << endl;
    orthmainsubmachine->ss_t_stp1_unpressed();
}

void OrthMainFsm::ss_t_rst1_unpressed() {
    cout << "OrthMainFsm: ss_t_rst1_unpressed called" << endl;
    orthmainsubmachine->ss_t_rst1_unpressed();
}

void OrthMainFsm::ss_t_str1_pressed() {
    cout << "OrthMainFsm: ss_t_str1_pressed called" << endl;
    orthmainsubmachine->ss_t_str1_pressed();
}

void OrthMainFsm::ss_ls_str2_continuous() {
    cout << "OrthMainFsm: ss_ls_str2_continuous called" << endl;
    orthmainsubmachine->ss_ls_str2_continuous();
}

void OrthMainFsm::ss_ls_str2_interrupted() {
    cout << "OrthMainFsm: ss_ls_str2_interrupted called" << endl;
    orthmainsubmachine->ss_ls_str2_interrupted();
}

void OrthMainFsm::lightbarrier_height2_continuous() {
    cout << "OrthMainFsm: lightbarrier_height2_continuous called" << endl;
    orthmainsubmachine->lightbarrier_height2_continuous();
}

void OrthMainFsm::lightbarrier_height2_interrupted() {
    cout << "OrthMainFsm: lightbarrier_height2_interrupted called" << endl;
    orthmainsubmachine->lightbarrier_height2_interrupted();
}

void OrthMainFsm::height_ok2_active() {
    cout << "OrthMainFsm: height_ok2_active called" << endl;
    orthmainsubmachine->height_ok2_active();
}

void OrthMainFsm::height_ok2_unactive() {
    cout << "OrthMainFsm: height_ok2_unactive called" << endl;
    orthmainsubmachine->height_ok2_unactive();
}

void OrthMainFsm::ss_ls_srt2_continuous() {
    cout << "OrthMainFsm: ss_ls_srt2_continuous called" << endl;
    orthmainsubmachine->ss_ls_srt2_continuous();
}

void OrthMainFsm::ss_ls_srt2_interrupted() {
    cout << "OrthMainFsm: ss_ls_srt2_interrupted called" << endl;
    orthmainsubmachine->ss_ls_srt2_interrupted();
}

void OrthMainFsm::ss_ms2_erkannt() {
    cout << "OrthMainFsm: ss_ms2_erkannt called" << endl;
    orthmainsubmachine->ss_ms2_erkannt();
}

void OrthMainFsm::ss_ms2_fall() {
    cout << "OrthMainFsm: ss_ms2_fall called" << endl;
    orthmainsubmachine->ss_ms2_fall();
}

void OrthMainFsm::switch2_open() {
    cout << "OrthMainFsm: switch2_open called" << endl;
    orthmainsubmachine->switch2_open();
}

void OrthMainFsm::switch2_unopen() {
    cout << "OrthMainFsm: switch2_unopen called" << endl;
    orthmainsubmachine->switch2_unopen();
}

void OrthMainFsm::ss_ls_sli2_rise() {
    cout << "OrthMainFsm: ss_ls_sli2_rise called" << endl;
    orthmainsubmachine->ss_ls_sli2_rise();
}

void OrthMainFsm::ss_ls_sli2_full() {
    cout << "OrthMainFsm: ss_ls_sli2_full called" << endl;
    orthmainsubmachine->ss_ls_sli2_full();
}

void OrthMainFsm::ss_ls_end2_continuous() {
    cout << "OrthMainFsm: ss_ls_end2_continuous called" << endl;
    orthmainsubmachine->ss_ls_end2_continuous();
}

void OrthMainFsm::ss_ls_end2_interrupted() {
    cout << "OrthMainFsm: ss_ls_end2_interrupted called" << endl;
    orthmainsubmachine->ss_ls_end2_interrupted();
}

void OrthMainFsm::ss_t_str2_unpressed() {
    cout << "OrthMainFsm: ss_t_str2_unpressed called" << endl;
    orthmainsubmachine->ss_t_str2_unpressed();
}

void OrthMainFsm::ss_t_stp2_unpressed() {
    cout << "OrthMainFsm: ss_t_stp2_unpressed called" << endl;
    orthmainsubmachine->ss_t_stp2_unpressed();
}

void OrthMainFsm::ss_t_rst2_unpressed() {
    cout << "OrthMainFsm: ss_t_rst2_unpressed called" << endl;
    orthmainsubmachine->ss_t_rst2_unpressed();
}

void OrthMainFsm::ss_t_est2_unpressed() {
    cout << "OrthMainFsm: ss_t_est2_unpressed called" << endl;
    orthmainsubmachine->ss_t_est2_unpressed();
}

void OrthMainFsm::ss_t_str2_pressed() {
    cout << "OrthMainFsm: ss_t_str2_pressed called" << endl;
    orthmainsubmachine->ss_t_str2_pressed();
}

void OrthMainFsm::ss_t_est1_pressed() {
    cout << "OrthMainFsm: ss_t_est1_pressed called" << endl;
    TriggerProcessingState processing_state = orthmainsubmachine->ss_t_est1_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        orthmainsubmachine->resetDeepHistory();
        orthmainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE1();
    }
}

void OrthMainFsm::ss_t_est2_pressed() {
    cout << "OrthMainFsm: ss_t_est2_pressed called" << endl;
    TriggerProcessingState processing_state = orthmainsubmachine->ss_t_est2_pressed();
    if (processing_state == TriggerProcessingState::pending) {
        orthmainsubmachine->resetDeepHistory();
        orthmainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortE2();
    }
}

void OrthMainFsm::connection_lost() {
    cout << "OrthMainFsm: connection_lost called" << endl;
    TriggerProcessingState processing_state = orthmainsubmachine->connection_lost();
    if (processing_state == TriggerProcessingState::pending) {
        orthmainsubmachine->resetDeepHistory();
        orthmainsubmachine->exit();
        leavingState();
        new(this) EStoppFSM;
        enterViaPortCL();
    }
}

void OrthMainFsm::showState() {
    cout << "State: OrthMainFsm" << endl;
    orthmainsubmachine->showState();
}

void OrthMainFsm::enterByDefaultEntryPoint() {
    entry();
    orthmainsubmachine->enterViaPseudoStart();
}
