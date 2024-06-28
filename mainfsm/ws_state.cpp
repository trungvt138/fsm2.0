//
// Created by wild on 22/06/2024.
//

#include "../mainfsm/ws_state.h"

#include <iostream>

#include "idle.h"
#include "../mainfsm/error_state.h"

void WS_State::entry() {
    //std::cout << "WSSate_State Entry" << std::endl;
    action->entered_WS_State();
    action->ak_l_grn1_on();
    action->ak_l_grn2_on();

    //action->entered_WS_State();
}


void WS_State::exit() {
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();
}

void WS_State::enterByDefaultEntryPoint() {
    entry();
    wsstatemachine->enterViaPseudoStart();
}

void WS_State::enterByDeepHistoryEntryPoint(){
    entry();
    wsstatemachine->enterViaDeepHistory();
}


//estop

TriggerProcessingState WS_State::ss_t_est1_pressed() {
    std::cout << "WS_State::ss_t_est2_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_est2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_est2_pressed() {
    std::cout << "WS_State::ss_t_est1_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_est1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_est1_unpressed() {
    std::cout << "WS_State::ss_t_est2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_est2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_est2_unpressed() {
    std::cout << "WS_State::ss_t_est1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_est1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

//FBA1

TriggerProcessingState WS_State::ss_ls_str1_interrupted() {
    std::cout << "WS_State::ss_ls_str1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_str1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_str1_continuous() {
    std::cout << "WS_State::ss_ls_str1_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_str1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::lightbarrier_height1_interrupted() {
    std::cout << "WS_State::lightbarrier_height1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->lightbarrier_height1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::lightbarrier_height1_continuous() {
    std::cout << "WS_State::lightbarrier_height1_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->lightbarrier_height1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::height_ok1_active() {
    std::cout << "WS_State::height_ok1_active called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->height_ok1_active();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::height_ok1_unactive() {
    std::cout << "WS_State::height_ok1_unactive called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->height_ok1_unactive();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_srt1_interrupted() {
    std::cout << "WS_State::ss_ls_srt1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_srt1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_srt1_continuous() {
    std::cout << "WS_State::ss_ls_srt1_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_srt1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ms1_erkannt() {
    std::cout << "WS_State::ss_ms1_erkannt called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ms1_erkannt();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ms1_fall() {
    std::cout << "WS_State::ss_ms1_fall called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ms1_fall();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::switch1_open() {
    std::cout << "WS_State::switch1_open called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->switch1_open();
    handleDefaultExit(processingstate);
    return processingstate;
}


TriggerProcessingState WS_State::switch1_unopen() {
    std::cout << "WS_State::switch1_unopen called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->switch1_unopen();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_sli1_full() {
    std::cout << "WS_State::ss_ls_sli1_full called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_sli1_full();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_sli1_rise() {
    std::cout << "WS_State::ss_ls_sli1_rise called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_sli1_rise();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_end1_continuous() {
    std::cout << "WS_State::ss_ls_end1_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_end1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_end1_interrupted() {
    std::cout << "WS_State::ss_ls_end1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_end1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str1_pressed() {
    std::cout << "WS_State::ss_t_str1_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str1_unpressed() {
    std::cout << "WS_State::ss_t_str1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_stp1_unpressed() {
    std::cout << "WS_State::ss_t_stp1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_stp1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_rst1_pressed() {
    std::cout << "WS_State::ss_t_rst1_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_rst1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_rst1_unpressed() {
    std::cout << "WS_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_rst1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str1_shortpressed() {
    std::cout << "WS_State::ss_t_str1_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str1_shortpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ws_sorted_FBA1() {
    std::cout << "WS_State::ws_sorted_FBA1 called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ws_sorted_FBA1();
    handleDefaultExit(processingstate);
    return processingstate;
}

//FBA2

TriggerProcessingState WS_State::ss_ls_str2_interrupted() {
    std::cout << "WS_State::ss_ls_str2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_str2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_str2_continuous() {
    std::cout << "WS_State::ss_ls_str2_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_str2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::lightbarrier_height2_interrupted() {
    std::cout << "WS_State::lightbarrier_height2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->lightbarrier_height2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::lightbarrier_height2_continuous() {
    std::cout << "WS_State::lightbarrier_height2_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->lightbarrier_height2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::height_ok2_active() {
    std::cout << "WS_State::height_ok2_active called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->height_ok2_active();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::height_ok2_unactive() {
    std::cout << "WS_State::height_ok2_unactive called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->height_ok2_unactive();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_srt2_interrupted() {
    std::cout << "WS_State::ss_ls_srt2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_srt2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_srt2_continuous() {
    std::cout << "WS_State::ss_ls_srt2_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_srt2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ms2_erkannt() {
    std::cout << "WS_State::ss_ms2_erkannt called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ms2_erkannt();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ms2_fall() {
    std::cout << "WS_State::ss_ms2_fall called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ms2_fall();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::switch2_open() {
    std::cout << "WS_State::switch2_open called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->switch2_open();
    handleDefaultExit(processingstate);
    return processingstate;
}


TriggerProcessingState WS_State::switch2_unopen() {
    std::cout << "WS_State::switch2_unopen called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->switch2_unopen();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_sli2_full() {
    std::cout << "WS_State::ss_ls_sli2_full called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_sli2_full();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_sli2_rise() {
    std::cout << "WS_State::ss_ls_sli2_rise called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_sli2_rise();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_end2_continuous() {
    std::cout << "WS_State::ss_ls_end2_continuous called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_end2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_ls_end2_interrupted() {
    std::cout << "WS_State::ss_ls_end2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_ls_end2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str2_pressed() {
    std::cout << "WS_State::ss_t_str2_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str2_unpressed() {
    std::cout << "WS_State::ss_t_str2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_stp2_unpressed() {
    std::cout << "WS_State::ss_t_stp2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_stp2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_rst2_pressed() {
    std::cout << "WS_State::ss_t_rst2_pressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_rst2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_rst2_unpressed() {
    std::cout << "WS_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_rst2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ss_t_str2_shortpressed() {
    std::cout << "WS_State::ss_t_str2_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ss_t_str2_shortpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState WS_State::ws_sorted_FBA2() {
    std::cout << "WS_State::ws_sorted_FBA2 called" << std::endl;

    TriggerProcessingState processingstate = wsstatemachine->ws_sorted_FBA2();
    handleDefaultExit(processingstate);
    return processingstate;
}

//trigger that is consumed
TriggerProcessingState WS_State::ss_t_stp1_pressed() {
    std::cout << "WS_State: ss_t_stp_pressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_missing() {
    std::cout << "WS_State: ws_missing_received called" << std::endl;
    leavingState();
    new(this) Error_State;
    //enterByWsGonePoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_false_placement() {
    std::cout << "WS_State: ws_false_placement_received called" << std::endl;
    leavingState();
    new(this) Error_State;
    //enterByFalsePlacementPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::unwanted_ws() {
    std::cout << "WS_State: unwanted_ws called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->unwanted_ws();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::slide1_free() {
    std::cout << "WS_State: slide1_free called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->slide1_free();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::slide2_free() {
    std::cout << "WS_State: slide2_free called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->slide2_free();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::right_order() {
    std::cout << "WS_State: right_order called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->right_order();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::height_calibration() {
    std::cout << "WS_State: height_calibration called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->height_calibration();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::height_high() {
    std::cout << "WS_State: height_high called" << std::endl;
    TriggerProcessingState processingstate = wsstatemachine->height_high();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::both_slide_full() {
    std::cout << "WS_State: both_slide_full_received called" << std::endl;
    TriggerProcessingState processing_state = wsstatemachine->both_slide_full();
    if (processing_state == TriggerProcessingState::pending) {
        wsstatemachine->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}

void WS_State::showState() {
    std::cout << "  MainFsm: WS State" << std::endl;
    wsstatemachine->showState();
}
