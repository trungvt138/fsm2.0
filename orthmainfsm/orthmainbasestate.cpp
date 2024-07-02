//
// Created by trung on 30/06/2024.
//

#include "orthmainbasestate.h"

#include "../checkslidefsm/checkslidepseudostartstate.h"
#include "../mainfsm/mainpseudostartstate.h"


void OrthMainBaseState::enterViaPseudoStart() {
    entry();
    mainsubmachine->enterViaPseudoStart();
    checkslidesubmachine->enterViaPseudoStart();
}

void OrthMainBaseState::initSubStateMachines() {
    mainsubmachine = new MainPseudoStartState();
    mainsubmachine->initSubStateMachines();
    checkslidesubmachine = new CheckSlidePseudoStartState();
    checkslidesubmachine->initSubStateMachines();
}

void OrthMainBaseState::setAction(Actions *action) {
    this->action = action;
    mainsubmachine->setAction(action);
    checkslidesubmachine->setAction(action);
}

void OrthMainBaseState::setData(ContextData *data) {
    this->data = data;
    mainsubmachine->setData(data);
    checkslidesubmachine->setData(data);
}

void OrthMainBaseState::ss_t_str1_longpressed() {
    cout << "OrthMainBaseState: ss_t_str1_longpressed called" << endl;
    mainsubmachine->ss_t_str1_longpressed();
}

void OrthMainBaseState::ss_t_str1_shortpressed() {
    cout << "OrthMainBaseState: ss_t_str1_shortpressed called" << endl;
    mainsubmachine->ss_t_str1_shortpressed();
}

void OrthMainBaseState::ss_t_str2_longpressed() {
    cout << "OrthMainBaseState: ss_t_str2_longpressed called" << endl;
    mainsubmachine->ss_t_str2_longpressed();
}

void OrthMainBaseState::ss_t_str2_shortpressed() {
    cout << "OrthMainBaseState: ss_t_str2_shortpressed called" << endl;
    mainsubmachine->ss_t_str2_shortpressed();
}

void OrthMainBaseState::ss_t_stp1_pressed() {
    cout << "OrthMainBaseState: ss_t_stp_pressed called" << endl;
    mainsubmachine->ss_t_stp1_pressed();
}

void OrthMainBaseState::ss_t_stp2_pressed() {
    cout << "OrthMainBaseState: ss_t_stp_pressed called" << endl;
    mainsubmachine->ss_t_stp2_pressed();
}

void OrthMainBaseState::ws_false_placement() {
    cout << "OrthMainBaseState: ws_false_placement called" << endl;
    mainsubmachine->ws_false_placement();
}

void OrthMainBaseState::ws_missing() {
    cout << "OrthMainBaseState: ws_missing called" << endl;
    mainsubmachine->ws_missing();
}

void OrthMainBaseState::both_slide_full() {
    cout << "OrthMainBaseState: both_slide_full called" << endl;
    mainsubmachine->both_slide_full();
}

void OrthMainBaseState::ss_ls_str1_continuous() {
    cout << "OrthMainBaseState: ss_ls_str1_continuous called" << endl;
    mainsubmachine->ss_ls_str1_continuous();
}

void OrthMainBaseState::ss_ls_str1_interrupted() {
    cout << "OrthMainBaseState: ss_ls_str1_interrupted called" << endl;
    mainsubmachine->ss_ls_str1_interrupted();
}

void OrthMainBaseState::lightbarrier_height1_continuous() {
    cout << "OrthMainBaseState: lightbarrier_height1_continuous called" << endl;
    mainsubmachine->lightbarrier_height1_continuous();
}

void OrthMainBaseState::lightbarrier_height1_interrupted() {
    cout << "OrthMainBaseState: lightbarrier_height1_interrupted called" << endl;
    mainsubmachine->lightbarrier_height1_interrupted();
}

void OrthMainBaseState::height_ok1_active() {
    cout << "OrthMainBaseState: height_ok1_active called" << endl;
    mainsubmachine->height_ok1_active();
}

void OrthMainBaseState::height_ok1_unactive() {
    cout << "OrthMainBaseState: height_ok1_unactive called" << endl;
    mainsubmachine->height_ok1_unactive();
}

void OrthMainBaseState::ss_ls_srt1_continuous() {
    cout << "OrthMainBaseState: ss_ls_srt1_continuous called" << endl;
    mainsubmachine->ss_ls_srt1_continuous();
}

void OrthMainBaseState::ss_ls_srt1_interrupted() {
    cout << "OrthMainBaseState: ss_ls_srt1_interrupted called" << endl;
    mainsubmachine->ss_ls_srt1_interrupted();
}

void OrthMainBaseState::ss_ms1_erkannt() {
    cout << "OrthMainBaseState: ss_ms1_erkannt called" << endl;
    mainsubmachine->ss_ms1_erkannt();
}

void OrthMainBaseState::ss_ms1_fall() {
    cout << "OrthMainBaseState: ss_ms1_fall called" << endl;
    mainsubmachine->ss_ms1_fall();
}

void OrthMainBaseState::switch1_open() {
    cout << "OrthMainBaseState: switch1_open called" << endl;
    mainsubmachine->switch1_open();
}

void OrthMainBaseState::switch1_unopen() {
    cout << "OrthMainBaseState: switch1_unopen called" << endl;
    mainsubmachine->switch1_unopen();
}

void OrthMainBaseState::ss_ls_sli1_rise() {
    cout << "OrthMainBaseState: ss_ls_sli1_rise called" << endl;
    mainsubmachine->ss_ls_sli1_rise();
    checkslidesubmachine->ss_ls_sli1_rise();
}

void OrthMainBaseState::ss_ls_sli1_full() {
    cout << "OrthMainBaseState: ss_ls_sli1_full called" << endl;
    mainsubmachine->ss_ls_sli1_full();
    checkslidesubmachine->ss_ls_sli1_full();
}

void OrthMainBaseState::ss_ls_end1_continuous() {
    cout << "OrthMainBaseState: ss_ls_end1_continuous called" << endl;
    mainsubmachine->ss_ls_end1_continuous();
}

void OrthMainBaseState::ss_ls_end1_interrupted() {
    cout << "OrthMainBaseState: ss_ls_end1_interrupted called" << endl;
    mainsubmachine->ss_ls_end1_interrupted();
}

void OrthMainBaseState::ss_t_rst1_pressed() {
    cout << "OrthMainBaseState: ss_t_rst1_pressed called" << endl;
    mainsubmachine->ss_t_rst1_pressed();
}

void OrthMainBaseState::ss_t_rst2_pressed() {
    cout << "OrthMainBaseState: ss_t_rst2_pressed called" << endl;
    mainsubmachine->ss_t_rst2_pressed();
}

void OrthMainBaseState::slide1_free() {
    cout << "OrthMainBaseState: slide1_free called" << endl;
    mainsubmachine->slide1_free();
}

void OrthMainBaseState::slide2_free() {
    cout << "OrthMainBaseState: slide2_free called" << endl;
    mainsubmachine->slide2_free();
}

void OrthMainBaseState::unwanted_ws() {
    cout << "OrthMainBaseState: unwanted_ws called" << endl;
    mainsubmachine->unwanted_ws();
}

void OrthMainBaseState::right_order() {
    cout << "OrthMainBaseState: right_order called" << endl;
    mainsubmachine->right_order();
}

void OrthMainBaseState::height_calibration() {
    cout << "OrthMainBaseState: height_calibration called" << endl;
    mainsubmachine->height_calibration();
}


void OrthMainBaseState::ws_gone() {
    cout << "OrthMainBaseState: ws_gone called" << endl;
    mainsubmachine->ws_gone();
}

void OrthMainBaseState::height_high() {
    cout << "OrthMainBaseState: height_high called" << endl;
    mainsubmachine->height_high();
}

void OrthMainBaseState::height_flat() {
    cout << "OrthMainBaseState: height_flat called" << endl;
    mainsubmachine->height_flat();
}

void OrthMainBaseState::height_hole() {
    cout << "OrthMainBaseState: height_hole called" << endl;
    mainsubmachine->height_hole();
}

void OrthMainBaseState::height_band() {
    cout << "OrthMainBaseState: height_band called" << endl;
    mainsubmachine->height_band();
}

void OrthMainBaseState::ss_t_str1_unpressed() {
    cout << "OrthMainBaseState: ss_t_str1_unpressed called" << endl;
    mainsubmachine->ss_t_str1_unpressed();
}

void OrthMainBaseState::ss_t_stp1_unpressed() {
    cout << "OrthMainBaseState: ss_t_stp1_unpressed called" << endl;
    mainsubmachine->ss_t_stp1_unpressed();
}

void OrthMainBaseState::ss_t_rst1_unpressed() {
    cout << "OrthMainBaseState: ss_t_rst1_unpressed called" << endl;
    mainsubmachine->ss_t_rst1_unpressed();
}

void OrthMainBaseState::ss_t_str1_pressed() {
    cout << "OrthMainBaseState: ss_t_str1_pressed called" << endl;
    mainsubmachine->ss_t_str1_pressed();
}

void OrthMainBaseState::ss_ls_str2_continuous() {
    cout << "OrthMainBaseState: ss_ls_str2_continuous called" << endl;
    mainsubmachine->ss_ls_str2_continuous();
}

void OrthMainBaseState::ss_ls_str2_interrupted() {
    cout << "OrthMainBaseState: ss_ls_str2_interrupted called" << endl;
    mainsubmachine->ss_ls_str2_interrupted();
}

void OrthMainBaseState::lightbarrier_height2_continuous() {
    cout << "OrthMainBaseState: lightbarrier_height2_continuous called" << endl;
    mainsubmachine->lightbarrier_height2_continuous();
}

void OrthMainBaseState::lightbarrier_height2_interrupted() {
    cout << "OrthMainBaseState: lightbarrier_height2_interrupted called" << endl;
    mainsubmachine->lightbarrier_height2_interrupted();
}

void OrthMainBaseState::height_ok2_active() {
    cout << "OrthMainBaseState: height_ok2_active called" << endl;
    mainsubmachine->height_ok2_active();
}

void OrthMainBaseState::height_ok2_unactive() {
    cout << "OrthMainBaseState: height_ok2_unactive called" << endl;
    mainsubmachine->height_ok2_unactive();
}

void OrthMainBaseState::ss_ls_srt2_continuous() {
    cout << "OrthMainBaseState: ss_ls_srt2_continuous called" << endl;
    mainsubmachine->ss_ls_srt2_continuous();
}

void OrthMainBaseState::ss_ls_srt2_interrupted() {
    cout << "OrthMainBaseState: ss_ls_srt2_interrupted called" << endl;
    mainsubmachine->ss_ls_srt2_interrupted();
}

void OrthMainBaseState::ss_ms2_erkannt() {
    cout << "OrthMainBaseState: ss_ms2_erkannt called" << endl;
    mainsubmachine->ss_ms2_erkannt();
}

void OrthMainBaseState::ss_ms2_fall() {
    cout << "OrthMainBaseState: ss_ms2_fall called" << endl;
    mainsubmachine->ss_ms2_fall();
}

void OrthMainBaseState::switch2_open() {
    cout << "OrthMainBaseState: switch2_open called" << endl;
    mainsubmachine->switch2_open();
}

void OrthMainBaseState::switch2_unopen() {
    cout << "OrthMainBaseState: switch2_unopen called" << endl;
    mainsubmachine->switch2_unopen();
}

void OrthMainBaseState::ss_ls_sli2_rise() {
    cout << "OrthMainBaseState: ss_ls_sli2_rise called" << endl;
    mainsubmachine->ss_ls_sli2_rise();
    checkslidesubmachine->ss_ls_sli2_rise();
}

void OrthMainBaseState::ss_ls_sli2_full() {
    cout << "OrthMainBaseState: ss_ls_sli2_full called" << endl;
    mainsubmachine->ss_ls_sli2_full();
    checkslidesubmachine->ss_ls_sli2_full();
}

void OrthMainBaseState::ss_ls_end2_continuous() {
    cout << "OrthMainBaseState: ss_ls_end2_continuous called" << endl;
    mainsubmachine->ss_ls_end2_continuous();
}

void OrthMainBaseState::ss_ls_end2_interrupted() {
    cout << "OrthMainBaseState: ss_ls_end2_interrupted called" << endl;
    mainsubmachine->ss_ls_end2_interrupted();
}

void OrthMainBaseState::ss_t_str2_unpressed() {
    cout << "OrthMainBaseState: ss_t_str2_unpressed called" << endl;
    mainsubmachine->ss_t_str2_unpressed();
}

void OrthMainBaseState::ss_t_stp2_unpressed() {
    cout << "OrthMainBaseState: ss_t_stp2_unpressed called" << endl;
    mainsubmachine->ss_t_stp2_unpressed();
}

void OrthMainBaseState::ss_t_rst2_unpressed() {
    cout << "OrthMainBaseState: ss_t_rst2_unpressed called" << endl;
    mainsubmachine->ss_t_rst2_unpressed();
}

void OrthMainBaseState::ss_t_est2_unpressed() {
    cout << "OrthMainBaseState: ss_t_est2_unpressed called" << endl;
    mainsubmachine->ss_t_est2_unpressed();
}

void OrthMainBaseState::ss_t_str2_pressed() {
    cout << "OrthMainBaseState: ss_t_str2_pressed called" << endl;
    mainsubmachine->ss_t_str2_pressed();
}

void OrthMainBaseState::ws_sorted_FBA1() {
    cout << "OrthMainBaseState: ws_sorted_FBA1 called" << endl;
    mainsubmachine->ws_sorted_FBA1();
}

void OrthMainBaseState::ws_sorted_FBA2() {
    cout << "OrthMainBaseState: ws_sorted_FBA2 called" << endl;
    mainsubmachine->ws_sorted_FBA2();
}
