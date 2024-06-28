/*
 * height_measurement.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "height_measurement.h"

#include "metal_detector.h"

void Height_Measurement::entry() {
    //std::cout << "Height_Measurement Entry" << std::endl;
    //action->entered_Calibration_State();
    hmstatemachine->enterViaPseudoStart();
}


void Height_Measurement::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        //leavingState();         // not needed, as sub-state machine cannot act anymore.
    	hmstatemachine->exit();   // just call own exit.
        new(this) Metal_Detector;
        enterByDefaultEntryPoint();
    }
}

TriggerProcessingState Height_Measurement::height_calibration() {
    TriggerProcessingState processingstate = hmstatemachine->height_calibration();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Height_Measurement::height_band() {
    TriggerProcessingState processingstate = hmstatemachine->height_band();
    handleDefaultExit(processingstate);
    return TriggerProcessingState::consumed;
}

TriggerProcessingState Height_Measurement::height_flat() {
    TriggerProcessingState processingstate = hmstatemachine->height_flat();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Height_Measurement::height_high() {
    TriggerProcessingState processingstate = hmstatemachine->height_high();
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Height_Measurement::height_hole() {
    TriggerProcessingState processingstate = hmstatemachine->height_hole();
    handleDefaultExit(processingstate);
    return processingstate;
}

void Height_Measurement::enterByDeepHistoryEntryPoint() {
    entry();
    hmstatemachine->enterViaDeepHistory();;
}


void Height_Measurement::showState() {
    std::cout << "  Operation_State Fsm: Height_Measurement State" << std::endl;
    hmstatemachine->showState();
}



