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
    wsstatemachine1->enterViaPseudoStart();
    wsstatemachine2->enterViaPseudoStart();
}

void WS_State::enterByDeepHistoryEntryPoint(){
    entry();
    wsstatemachine1->enterViaDeepHistory();
    wsstatemachine2->enterViaDeepHistory();
}

void WS_State::resetDeepHistory() {
    wsstatemachine1->resetDeepHistory();
    wsstatemachine2->resetDeepHistory();
}

//FBA1

TriggerProcessingState WS_State::ss_ls_str1_interrupted() {
    std::cout << "WS_State::ss_ls_str1_interrupted called" << std::endl;

    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_str1_interrupted();
    if(processingstate1 == TriggerProcessingState::pending) {
        TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_str1_interrupted();
    }

    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ss_ls_str1_continuous() {
    std::cout << "WS_State::ss_ls_str1_continuous called" << std::endl;

    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_str1_continuous();
    if(processingstate1 == TriggerProcessingState::pending) {
        TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_str1_continuous();
    }

    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::lightbarrier_height1_interrupted() {
    std::cout << "WS_State::lightbarrier_height1_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height1_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height1_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::lightbarrier_height1_continuous() {
    std::cout << "WS_State::lightbarrier_height1_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height1_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height1_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok1_active() {
    std::cout << "WS_State::height_ok1_active called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok1_active();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok1_active();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok1_unactive() {
    std::cout << "WS_State::height_ok1_unactive called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok1_unactive();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok1_unactive();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt1_interrupted() {
    std::cout << "WS_State::ss_ls_srt1_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt1_continuous() {
    std::cout << "WS_State::ss_ls_srt1_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_srt1_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_srt1_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms1_erkannt() {
    std::cout << "WS_State::ss_ms1_erkannt called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ms1_erkannt();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ms1_erkannt();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms1_fall() {
    std::cout << "WS_State::ss_ms1_fall called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ms1_fall();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ms1_fall();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::switch1_open() {
    std::cout << "WS_State::switch1_open called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->switch1_open();
    TriggerProcessingState processingstate1 = wsstatemachine1->switch1_open();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}


TriggerProcessingState WS_State::switch1_unopen() {
    std::cout << "WS_State::switch1_unopen called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->switch1_unopen();
    TriggerProcessingState processingstate1 = wsstatemachine1->switch1_unopen();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli1_full() {
    std::cout << "WS_State::ss_ls_sli1_full called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_sli1_full();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_sli1_full();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli1_rise() {
    std::cout << "WS_State::ss_ls_sli1_rise called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_sli1_rise();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_sli1_rise();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end1_continuous() {
    std::cout << "WS_State::ss_ls_end1_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_end1_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_end1_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end1_interrupted() {
    std::cout << "WS_State::ss_ls_end1_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_end1_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_end1_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str1_pressed() {
    std::cout << "WS_State::ss_t_str1_pressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str1_pressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str1_pressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str1_unpressed() {
    std::cout << "WS_State::ss_t_str1_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str1_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str1_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_stp1_unpressed() {
    std::cout << "WS_State::ss_t_stp1_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_stp1_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_stp1_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_rst1_pressed() {
    std::cout << "WS_State::ss_t_rst1_pressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_rst1_pressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_rst1_pressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_rst1_unpressed() {
    std::cout << "WS_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_rst1_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_rst1_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str1_shortpressed() {
    std::cout << "WS_State::ss_t_str1_shortpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str1_shortpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str1_shortpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ws_sorted_FBA1() {
    std::cout << "WS_State::ws_sorted_FBA1 called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ws_sorted_FBA1();
    TriggerProcessingState processingstate1 = wsstatemachine1->ws_sorted_FBA1();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

//FBA2

TriggerProcessingState WS_State::ss_ls_str2_interrupted() {
    std::cout << "WS_State::ss_ls_str2_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_str2_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_str2_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_str2_continuous() {
    std::cout << "WS_State::ss_ls_str2_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_str2_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_str2_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::lightbarrier_height2_interrupted() {
    std::cout << "WS_State::lightbarrier_height2_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height2_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height2_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::lightbarrier_height2_continuous() {
    std::cout << "WS_State::lightbarrier_height2_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height2_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height2_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok2_active() {
    std::cout << "WS_State::height_ok2_active called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok2_active();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok2_active();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok2_unactive() {
    std::cout << "WS_State::height_ok2_unactive called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok2_unactive();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok2_unactive();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt2_interrupted() {
    std::cout << "WS_State::ss_ls_srt2_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_srt2_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_srt2_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt2_continuous() {
    std::cout << "WS_State::ss_ls_srt2_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_srt2_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_srt2_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms2_erkannt() {
    std::cout << "WS_State::ss_ms2_erkannt called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ms2_erkannt();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ms2_erkannt();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms2_fall() {
    std::cout << "WS_State::ss_ms2_fall called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ms2_fall();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ms2_fall();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::switch2_open() {
    std::cout << "WS_State::switch2_open called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->switch2_open();
    TriggerProcessingState processingstate1 = wsstatemachine1->switch2_open();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}


TriggerProcessingState WS_State::switch2_unopen() {
    std::cout << "WS_State::switch2_unopen called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->switch2_unopen();
    TriggerProcessingState processingstate1 = wsstatemachine1->switch2_unopen();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli2_full() {
    std::cout << "WS_State::ss_ls_sli2_full called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_sli2_full();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_sli2_full();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli2_rise() {
    std::cout << "WS_State::ss_ls_sli2_rise called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_sli2_rise();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_sli2_rise();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end2_continuous() {
    std::cout << "WS_State::ss_ls_end2_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_end2_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_end2_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end2_interrupted() {
    std::cout << "WS_State::ss_ls_end2_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_end2_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_end2_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str2_pressed() {
    std::cout << "WS_State::ss_t_str2_pressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str2_pressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str2_pressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str2_unpressed() {
    std::cout << "WS_State::ss_t_str2_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str2_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str2_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_stp2_unpressed() {
    std::cout << "WS_State::ss_t_stp2_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_stp2_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_stp2_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_rst2_pressed() {
    std::cout << "WS_State::ss_t_rst2_pressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_rst2_pressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_rst2_pressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_rst2_unpressed() {
    std::cout << "WS_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_rst2_unpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_rst2_unpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_t_str2_shortpressed() {
    std::cout << "WS_State::ss_t_str2_shortpressed called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ss_t_str2_shortpressed();
    TriggerProcessingState processingstate1 = wsstatemachine1->ss_t_str2_shortpressed();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ws_sorted_FBA2() {
    std::cout << "WS_State::ws_sorted_FBA2 called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->ws_sorted_FBA2();
    TriggerProcessingState processingstate1 = wsstatemachine1->ws_sorted_FBA2();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

//trigger that is consumed
TriggerProcessingState WS_State::ss_t_stp1_pressed() {
    std::cout << "WS_State: ss_t_stp_pressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}



TriggerProcessingState WS_State::unwanted_ws() {
    std::cout << "WS_State: unwanted_ws called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->unwanted_ws();
    TriggerProcessingState processingstate1 = wsstatemachine1->unwanted_ws();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::slide1_free() {
    std::cout << "WS_State: slide1_free called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->slide1_free();
    TriggerProcessingState processingstate1 = wsstatemachine1->slide1_free();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::slide2_free() {
    std::cout << "WS_State: slide2_free called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->slide2_free();
    TriggerProcessingState processingstate1 = wsstatemachine1->slide2_free();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::right_order() {
    std::cout << "WS_State: right_order called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->right_order();
    TriggerProcessingState processingstate1 = wsstatemachine1->right_order();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_calibration() {
    std::cout << "WS_State: height_calibration called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->height_calibration();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_calibration();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_high() {
    std::cout << "WS_State: height_high called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->height_high();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_high();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_flat() {
    std::cout << "WS_State: height_flat called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->height_flat();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_flat();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_hole() {
    std::cout << "WS_State: height_hole called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->height_hole();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_hole();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_band() {
    std::cout << "WS_State: height_band called" << std::endl;
    TriggerProcessingState processingstate2 = wsstatemachine2->height_band();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_band();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::both_slide_full() {
    std::cout << "WS_State: both_slide_full_received called" << std::endl;
    TriggerProcessingState processing_state = wsstatemachine1->both_slide_full();
    TriggerProcessingState processing_state2 = wsstatemachine2->both_slide_full();
    if (processing_state == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending) {
        wsstatemachine2->exit();
        wsstatemachine1->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}
TriggerProcessingState WS_State::ws_missing() {
    std::cout << "WS_State: ws_missing_received called" << std::endl;
    TriggerProcessingState processing_state = wsstatemachine1->ws_missing();
    TriggerProcessingState processing_state2 = wsstatemachine2->ws_missing();
    if (processing_state == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending) {
        wsstatemachine2->exit();
        wsstatemachine1->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_false_placement() {
    std::cout << "WS_State: ws_false_placement_received called" << std::endl;
    TriggerProcessingState processing_state = wsstatemachine1->ws_false_placement();
    TriggerProcessingState processing_state2 = wsstatemachine2->ws_false_placement();
    if (processing_state == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending) {
        wsstatemachine2->exit();
        wsstatemachine1->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}

void WS_State::showState() {
    std::cout << "    MainFsm: WS State" << std::endl;
    cout << " " << endl;
    std::cout << "----First WS State----" << std::endl;
    wsstatemachine1->showState();
    cout << " " << endl;
    std::cout << "----Second WS State----" << std::endl;
    wsstatemachine2->showState();
}
