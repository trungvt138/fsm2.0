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


TriggerProcessingState Transfering::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        //leavingState();         // not needed, as sub-state machine cannot act anymore.
        transferingstatemachine->exit();   // just call own exit.
        new(this) OpPseudoEndState;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }
    return TriggerProcessingState::pending;
}

TriggerProcessingState Transfering::ss_ls_end1_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end1_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Transfering::ss_ls_end2_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Transfering::ss_ls_str2_interrupted() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_str2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Transfering::ws_sorted() {
    TriggerProcessingState processingstate = transferingstatemachine->ws_sorted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Transfering::ss_ls_end2_continuous() {
    TriggerProcessingState processingstate = transferingstatemachine->ss_ls_end2_continuous();
    return handleDefaultExit(processingstate);

}

void Transfering::enterByDeepHistoryEntryPoint() {
    entry();
    transferingstatemachine->enterViaDeepHistory();
}


void Transfering::showState() {
    std::cout << "\n  OperationFsm: Transfering State\n" << std::endl;
    transferingstatemachine->showState();
}



