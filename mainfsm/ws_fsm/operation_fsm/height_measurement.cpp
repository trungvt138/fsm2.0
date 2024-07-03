/*
 * height_measurement.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "height_measurement.h"

#include "metal_detector.h"

void Height_Measurement::entry() {
    std::cout << "\nOperationFsm: Height_Measurement State\n" << std::endl;
    action->ak_fbm1_slow_on();
    action->ak_fbm2_slow_on();
    hmstatemachine->enterViaPseudoStart();
}

void Height_Measurement::exit() {
    showState();
    action->ak_fbm1_slow_off();
    action->ak_fbm1_slow_off();
}

void Height_Measurement::handleDefaultExit(const TriggerProcessingState &processingstate) {
    // Alternative: Check sub state machine is in endstate, maybe saver.
    if (processingstate == TriggerProcessingState::endstatereached) {
        leavingState();         // not needed, as sub-state machine cannot act anymore.
    	hmstatemachine->exit();   // just call own exit.
        new(this) Metal_Detector;
        enterByDefaultEntryPoint();
    }
}

TriggerProcessingState Height_Measurement::height_ok1_unactive() {
	std::cout << "Height_Measurement: height_ok1_unactive called" << std::endl;
	leavingState();
	hmstatemachine->exit();   // just call own exit.
	new(this) Metal_Detector;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
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
    this->wp->setIsFlat(true);
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Height_Measurement::height_high() {
    TriggerProcessingState processingstate = hmstatemachine->height_high();
    this->wp->setIsTall(true);
    handleDefaultExit(processingstate);
    return processingstate;
}

TriggerProcessingState Height_Measurement::height_hole() {
    TriggerProcessingState processingstate = hmstatemachine->height_hole();
    this->wp->setHasHole(true);
    //TODO: identify normal hole with concentric hole
    handleDefaultExit(processingstate);
    return processingstate;
}

void Height_Measurement::enterByDeepHistoryEntryPoint() {
    entry();
    hmstatemachine->enterViaDeepHistory();;
}


void Height_Measurement::showState() {
    std::cout << "\n  OperationFsm: Height_Measurement State\n" << std::endl;
    hmstatemachine->showState();
}



