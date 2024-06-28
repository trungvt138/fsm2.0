/*
 * Sorting.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "Sorting.h"
#include "../../../mainfsm/error_state.h"
#include "Transfering.h"
#include "oppseudoendstate.h"

void Sorting::entry() {
    //std::cout << "Sorting Entry" << std::endl;
    //action->entered_Calibration_State();
    sortingstatemachine->enterViaPseudoStart();
}

//No default exit given. Checking whether ports are reached
void Sorting::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::ws_sorted_reached) {
        //leavingState();         // not needed, as sub-state machine cannot act anymore.
    	sortingstatemachine->exit();   // just call own exit.
        new(this) OpPseudoEndState;
        enterByDefaultEntryPoint();
    }
    else if (processingstate == TriggerProcessingState::ws_transfered_reached) {
        leavingState();
        sortingstatemachine->exit();   // just call own exit.
        new(this) Transfering;
        enterByDefaultEntryPoint();
    }
}

TriggerProcessingState Sorting::ss_ls_srt1_interrupted() {
    std::cout << "Sorting: ss_ls_srt1_interrupted caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->ss_ls_srt1_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Sorting::ss_ls_srt2_interrupted() {
    std::cout << "Sorting: ss_ls_srt2_interrupted caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->ss_ls_srt2_interrupted();
    handleDefaultExit(processingstate);
    return processingstate;
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Sorting::right_order() {
    std::cout << "Sorting: right_order caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->right_order();
    if (processingstate == TriggerProcessingState::ws_transfered_reached) {
        leavingState();
        new(this) Transfering;
        enterByDefaultEntryPoint();
    }
    //TriggerProcessingState processingstate = TriggerProcessingState::pending;
    handleDefaultExit(processingstate);
//    return processingstate;
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Sorting::unwanted_ws() {
    std::cout << "Sorting: unwanted_ws caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->unwanted_ws();
    handleDefaultExit(processingstate);
//    return processingstate;
    return TriggerProcessingState::consumed;
}

// TriggerProcessingState Sorting::both_slide_full() {
//     std::cout << "Sorting: both_slide_full called" << std::endl;
//     leavingState();
//     new(this) Error_State;
//     //TODO:uncomment this to connect to error fsm
//     //enterByBothSlideFullPoint();
//     return TriggerProcessingState::consumed;
// }

void Sorting::showState() {
    std::cout << "  Operation_State Fsm: Sorting State" << std::endl;
    sortingstatemachine->showState();
}


