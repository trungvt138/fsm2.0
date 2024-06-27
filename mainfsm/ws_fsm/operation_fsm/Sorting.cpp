/*
 * Sorting.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "Sorting.h"
#include "../../../mainfsm/error_state.h"
#include "Transfering.h"

void Sorting::entry() {
    std::cout << "Sorting Entry" << std::endl;
    //action->entered_Calibration_State();
    sortingstatemachine->enterViaPseudoStart();
}

void Sorting::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        // leavingState();         // not needed, as sub-state machine cannot act anymore.
    	sortingstatemachine->exit();   // just call own exit.
        new(this) Transfering;
        enterByDefaultEntryPoint();
    }
}

TriggerProcessingState Sorting::ss_ls_str1_interrupted() {
    //TriggerProcessingState processingstate = sortingstatemachine->ss_ls_str1_interrupted();
    TriggerProcessingState processingstate = TriggerProcessingState::pending;
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Sorting::ss_ls_str2_interrupted() {
    //TriggerProcessingState processingstate = sortingstatemachine->ss_ls_str2_interrupted();
    TriggerProcessingState processingstate = TriggerProcessingState::pending;
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Sorting::right_order() {
    //TriggerProcessingState processingstate = sortingstatemachine->right_order();
    TriggerProcessingState processingstate = TriggerProcessingState::pending;
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Sorting::unwanted_ws() {
    //TriggerProcessingState processingstate = sortingstatemachine->unwanted_ws();
    TriggerProcessingState processingstate = TriggerProcessingState::pending;
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Sorting::both_slide_full() {
    std::cout << "WS_State: both_slide_full_received called" << std::endl;
    leavingState();
    new(this) Error_State;
    //TODO:uncomment this to connect to error fsm
    //enterByBothSlideFullPoint();
    return TriggerProcessingState::consumed;
}

void Sorting::showState() {
    std::cout << "  Sorting: Operation State" << std::endl;
}


