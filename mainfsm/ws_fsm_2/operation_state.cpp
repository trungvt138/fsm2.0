/*
 * Operation_State2.cpp
 *
 *  Created on: 23 Jun 2024
 *      Author: WildanmSyufie
 */

#include "operation_state.h"

#include "WSIdle.h"
#include "wsbasestate.h"
#include "../../mainfsm/error_state.h"

void Operation_State2::entry() {
    //std::cout << "Operation_State2 Entry" << std::endl;
    std::cout << "\nWSFsm2: Operation State" << std::endl;
}

// TODO exit
void Operation_State2::exit() {
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();
}

void Operation_State2::resetDeepHistory() {
    leavingState();
    opstatemachine->exit();
    new(this) WSIdle2;
    enterByDefaultEntryPoint();
}

void Operation_State2::handleDefaultExit(const TriggerProcessingState &processingstate) {
    if (processingstate == TriggerProcessingState::endstatereached) {
        // leavingState();         // not needed, as sub-state machine cannot act anymore.
    	opstatemachine->exit();   // just call own exit.
        new(this) WSIdle2;
        enterByDefaultEntryPoint();
    }
}

void Operation_State2::enterByDefaultEntryPoint() {
    entry();
    opstatemachine->enterViaPseudoStart();
}

// void Operation_State2::enterByDeepHistoryEntryPoint(){
//     entry();
//     opstatemachine->enterViaDeepHistory();
// }

//FBA1

TriggerProcessingState Operation_State2::ss_ls_str1_interrupted() {
    std::cout << "Operation_State2::ss_ls_str1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_str1_continuous() {
    std::cout << "Operation_State2::ss_ls_str1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::lightbarrier_height1_interrupted() {
    std::cout << "Operation_State2::lightbarrier_height1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::lightbarrier_height1_continuous() {
    std::cout << "Operation_State2::lightbarrier_height1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_ok1_active() {
    std::cout << "Operation_State2::height_ok1_active called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok1_active();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_ok1_unactive() {
    std::cout << "Operation_State2::height_ok1_unactive called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok1_unactive();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_srt1_interrupted() {
    std::cout << "Operation_State2::ss_ls_srt1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_srt1_continuous() {
    std::cout << "Operation_State2::ss_ls_srt1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ms1_erkannt() {
    std::cout << "Operation_State2::ss_ms1_erkannt called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms1_erkannt();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ms1_fall() {
    std::cout << "Operation_State2::ss_ms1_fall called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms1_fall();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::switch1_open() {
    std::cout << "Operation_State2::switch1_open called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch1_open();
    handleDefaultExit(processingstate);
    return processingstate;
}


TriggerProcessingState Operation_State2::switch1_unopen() {
    std::cout << "Operation_State2::switch1_unopen called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch1_unopen();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_sli1_full() {
    std::cout << "Operation_State2::ss_ls_sli1_full called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli1_full();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_sli1_rise() {
    std::cout << "Operation_State2::ss_ls_sli1_rise called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli1_rise();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_end1_continuous() {
    std::cout << "Operation_State2::ss_ls_end1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_end1_interrupted() {
    std::cout << "Operation_State2::ss_ls_end1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str1_pressed() {
    std::cout << "Operation_State2::ss_t_str1_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str1_unpressed() {
    std::cout << "Operation_State2::ss_t_str1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_stp1_unpressed() {
    std::cout << "Operation_State2::ss_t_stp1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_stp1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_rst1_pressed() {
    std::cout << "Operation_State2::ss_t_rst1_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_rst1_unpressed() {
    std::cout << "Operation_State2::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst1_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str1_shortpressed() {
    std::cout << "Operation_State2::ss_t_str1_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_shortpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ws_sorted_FBA1() {
    std::cout << "Operation_State2::ws_sorted_FBA1 called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ws_sorted_FBA1();
    handleDefaultExit(processingstate);
    return processingstate;
}

//FBA2

TriggerProcessingState Operation_State2::ss_ls_str2_interrupted() {
    std::cout << "Operation_State2::ss_ls_str2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_str2_continuous() {
    std::cout << "Operation_State2::ss_ls_str2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::lightbarrier_height2_interrupted() {
    std::cout << "Operation_State2::lightbarrier_height2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::lightbarrier_height2_continuous() {
    std::cout << "Operation_State2::lightbarrier_height2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_ok2_active() {
    std::cout << "Operation_State2::height_ok2_active called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok2_active();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_ok2_unactive() {
    std::cout << "Operation_State2::height_ok2_unactive called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok2_unactive();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_srt2_interrupted() {
    std::cout << "Operation_State2::ss_ls_srt2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_srt2_continuous() {
    std::cout << "Operation_State2::ss_ls_srt2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ms2_erkannt() {
    std::cout << "Operation_State2::ss_ms2_erkannt called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms2_erkannt();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ms2_fall() {
    std::cout << "Operation_State2::ss_ms2_fall called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms2_fall();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::switch2_open() {
    std::cout << "Operation_State2::switch2_open called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch2_open();
    handleDefaultExit(processingstate);
    return processingstate;
}


TriggerProcessingState Operation_State2::switch2_unopen() {
    std::cout << "Operation_State2::switch2_unopen called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch2_unopen();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_sli2_full() {
    std::cout << "Operation_State2::ss_ls_sli2_full called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli2_full();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_sli2_rise() {
    std::cout << "Operation_State2::ss_ls_sli2_rise called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli2_rise();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_end2_continuous() {
    std::cout << "Operation_State2::ss_ls_end2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_ls_end2_interrupted() {
    std::cout << "Operation_State2::ss_ls_end2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str2_pressed() {
    std::cout << "Operation_State2::ss_t_str2_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str2_unpressed() {
    std::cout << "Operation_State2::ss_t_str2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_stp2_unpressed() {
    std::cout << "Operation_State2::ss_t_stp2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_stp2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_rst2_pressed() {
    std::cout << "Operation_State2::ss_t_rst2_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_rst2_unpressed() {
    std::cout << "Operation_State2::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst2_unpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ss_t_str2_shortpressed() {
    std::cout << "Operation_State2::ss_t_str2_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_shortpressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::ws_sorted_FBA2() {
    std::cout << "Operation_State2::ws_sorted_FBA2 called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ws_sorted_FBA2();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::slide1_free() {
    std::cout << "Operation_State2::slide1_free called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->slide1_free();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::slide2_free() {
    std::cout << "Operation_State2::slide2_free called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->slide2_free();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::right_order() {
    std::cout << "Operation_State2::right_order called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->right_order();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::unwanted_ws() {
    std::cout << "Operation_State2::unwanted_ws called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->unwanted_ws();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_calibration() {
    std::cout << "Operation_State2::height_calibration called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_calibration();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_high() {
    std::cout << "Operation_State2::height_high called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_high();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_flat() {
    std::cout << "Operation_State2::height_flat called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_flat();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_hole() {
    std::cout << "Operation_State2::height_hole called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_hole();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Operation_State2::height_band() {
    std::cout << "Operation_State2::height_band called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_band();
    handleDefaultExit(processingstate);
    return processingstate;
}

//for other fsm

// TriggerProcessingState Operation_State2::ws_missing() {
//     std::cout << "WS_State: ws_missing_received called" << std::endl;
//     leavingState();
//     new(this) Error_State;
//     enterByDefaultEntryPoint();
//     return TriggerProcessingState::consumed;
// }
//
// TriggerProcessingState Operation_State2::ws_false_placement() {
//     std::cout << "WS_State: ws_false_placement_received called" << std::endl;
//     leavingState();
//     new(this) Error_State;
//     enterByDefaultEntryPoint();
//     return TriggerProcessingState::consumed;
// }


void Operation_State2::showState() {
    std::cout << "      WSFsm2: Operation State" << std::endl;
    opstatemachine->showState();
}

void Operation_State2::enterByDeepHistoryEntryPoint() {
    entry();
    opstatemachine->enterViaDeepHistory();
}
