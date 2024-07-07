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
    std::cout << "\nOperationFsm: Sorting State\n" << std::endl;
    sortingstatemachine->enterViaPseudoStart();
    if (!this->data->checkOrder()) {
    	unwanted_ws();
    } else {
    	right_order();
    }
}

//No default exit given. Checking whether ports are reached
TriggerProcessingState Sorting::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::ws_sorted_reached) {
        //leavingState();         // not needed, as sub-state machine cannot act anymore.
    	sortingstatemachine->exit();   // just call own exit.
        new(this) OpPseudoEndState;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::endstatereached;
    }
    else if (processingstate == TriggerProcessingState::ws_transfered_reached) {
        leavingState();
        sortingstatemachine->exit();
        if (data->checkFBA1()) {
            action->ak_awf_wch1_on();
            //std::this_thread::sleep_for(std::chrono::milliseconds(800));
            action->ak_awf_wch1_off();
        }
        else if (data->checkFBA2()) {
            action->ak_awf_wch2_on();
            //std::this_thread::sleep_for(std::chrono::milliseconds(800));
            action->ak_awf_wch2_off();
        }// just call own exit.
        new(this) Transfering;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }
    else if (processingstate == TriggerProcessingState::both_slide_full) {
        leavingState();
        sortingstatemachine->exit();
        return TriggerProcessingState::both_slide_full;
    }
    return TriggerProcessingState::pending;
}

TriggerProcessingState Sorting::error_gone() {
    std::cout << "Sorting: error_gone caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->error_gone();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Sorting::ss_ls_sli1_full() {
    std::cout << "Sorting: ss_ls_srt1_interrupted caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->ss_ls_sli1_full();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Sorting::ss_ls_sli2_full() {
    std::cout << "Sorting: ss_ls_srt2_interrupted caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->ss_ls_sli2_full();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Sorting::right_order() {
    std::cout << "Sorting: right_order caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->right_order();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Sorting::unwanted_ws() {
    std::cout << "Sorting: unwanted_ws caled" << std::endl;;
    TriggerProcessingState processingstate = sortingstatemachine->unwanted_ws();
    return handleDefaultExit(processingstate);
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
    std::cout << "        OperationFsm: Sorting State" << std::endl;
    sortingstatemachine->showState();
}


