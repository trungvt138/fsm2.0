//
// Created by trung on 05/06/2024.
//

#include "../mainfsm/calibration_state.h"

#include <iostream>

#include "idle.h"

void Calibration_State::entry() {
    action->ak_l_grn1_blink_fast();
    action->ak_l_grn2_blink_fast();
    action->entered_Calibration_State();
    calibrationsubmachine->enterViaPseudoStart();
}

void Calibration_State::exit() {
    action->ak_l_grn1_off();
    action->ak_l_grn2_off();
}


TriggerProcessingState Calibration_State::ss_t_str1_shortpressed() {
    std::cout << "Calibration_State: ss_t_str1_shortpressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Calibration_State::ss_t_str2_shortpressed() {
    std::cout << "Calibration_State: ss_t_str2_shortpressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;

}

void Calibration_State::showState() {
    std::cout << "  MainFsm: Calibration_State" << std::endl;

}



TriggerProcessingState Calibration_State::ss_t_rst1_pressed() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_t_rst1_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_t_rst2_pressed() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_t_rst2_pressed();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::height_calibration() {
    TriggerProcessingState processingstate = calibrationsubmachine->height_calibration();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::height_band() {
    TriggerProcessingState processingstate = calibrationsubmachine->height_band();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::height_flat() {
    TriggerProcessingState processingstate = calibrationsubmachine->height_flat();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::height_high() {
    TriggerProcessingState processingstate = calibrationsubmachine->height_high();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::height_hole() {
    TriggerProcessingState processingstate = calibrationsubmachine->height_hole();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ws_gone() {
    TriggerProcessingState processingstate = calibrationsubmachine->ws_gone();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_str1_continuous() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_str1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_str1_interrupted() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_str1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_srt1_continuous() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_srt1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_srt1_interrupted() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_srt1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_end1_continuous() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_end1_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Calibration_State::ss_ls_end1_interrupted() {
    TriggerProcessingState processingstate = calibrationsubmachine->ss_ls_end1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}



void Calibration_State::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        // leavingState();         // not needed, as sub-state machine cannot act anymore.
        calibrationsubmachine->exit();   // just call own exit.
        new(this) Idle;
        enterByDefaultEntryPoint();
    }
}
