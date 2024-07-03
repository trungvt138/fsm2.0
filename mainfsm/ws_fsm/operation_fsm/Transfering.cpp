/*
 * Transfering.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "Transfering.h"

#include "oppseudoendstate.h"


void Transfering::entry() {
    //action->entered_Calibration_State();
    std::cout << "\nOperationFsm: Transfering State\n" << std::endl;
    transferingstatemachine->enterViaPseudoStart();
}


void Transfering::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        //leavingState();         // not needed, as sub-state machine cannot act anymore.
        transferingstatemachine->exit();   // just call own exit.
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
    std::cout << "\n  OperationFsm: Transfering State\n" << std::endl;
    transferingstatemachine->showState();
}



