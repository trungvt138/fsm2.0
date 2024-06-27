/*
 * Transfering.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "Transfering.h"

#include "oppseudoendstate.h"


void Transfering::entry() {
   // std::cout << "Transfering Entry" << std::endl;
    //action->entered_Calibration_State();
    transferingstatemachine->enterViaPseudoStart();
}


void Transfering::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        leavingState();         // not needed, as sub-state machine cannot act anymore.
    	hmstatemachine->exit();   // just call own exit.
        new(this) OpPseudoEndState;
        enterByDefaultEntryPoint();
    }
}

TriggerProcessingState Transfering::ss_ls_end1_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Transfering::ss_ls_end2_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Transfering::ss_ls_str2_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_str2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Transfering::ws_sorted() {
    TriggerProcessingState processingstate = transferingstatemachine->ws_sorted();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Transfering::ss_ls_end2_continuous() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end2_continuous();
    handleDefaultExit(processingstate);
    return processingstate;
}

void Transfering::enterByDeepHistoryEntryPoint() {
    entry();
    transferingstatemachine->enterViaDeepHistory();
}


void Transfering::showState() {
    std::cout << "  Operation_State Fsm: Transfering State" << std::endl;
    transferingstatemachine->showState();
}



