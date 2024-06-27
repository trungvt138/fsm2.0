//
// Created by trung on 07/06/2024.
//

#include "../mainfsm/error_state.h"

#include <iostream>

#include "ws_state.h"


void Error_State::entry() {
    action->entered_Error_State();
    action->ak_l_rot1_on();
    action->ak_l_rot2_on();
    action->ak_fbm1_right_off();
    action->ak_fbm2_right_off();
}

void Error_State::exit() {
    action->ak_l_rot1_on();
    action->ak_l_rot2_on();
}

//Overridden, because there is no default entry. So entry() should not be called: {entry();} -> {}
void Error_State::enterByDefaultEntryPoint() {}

void Error_State::enterByWsGonePoint() {
	entry();
	errorsubmachine->enterViaPort_WSgone();
}
void Error_State::enterByBothSlideFullPoint() {
	entry();
	errorsubmachine->enterViaPort_both_slide_full();
}
void Error_State::enterByFalsePlacementPoint() {
	entry();
	errorsubmachine->enterViaPort_false_placement();
}


void Error_State::handleDefaultExit(const TriggerProcessingState &processingstate) {
	 if (processingstate == TriggerProcessingState::endstatereached) {
		leavingState();
		errorsubmachine->exit();
		//TODO: Change to HistoryPoint of WS_State
		new(this) WS_State;
		enterByDeepHistoryEntryPoint();
	}
}

TriggerProcessingState Error_State::ss_t_rst1_pressed() {
	std::cout << "ErrorFSM: ss_t_rst1_pressed called" << std::endl;
	TriggerProcessingState processingstate = errorsubmachine->ss_t_rst1_pressed();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Error_State::ss_t_rst2_pressed() {
	std::cout << "ErrorFSM: ss_t_rst2_pressed called" << std::endl;
	TriggerProcessingState processingstate = errorsubmachine->ss_t_rst2_pressed();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Error_State::slide1_free() {
	std::cout << "ErrorFSM: slide1_free called" << std::endl;
	TriggerProcessingState processingstate = errorsubmachine->slide1_free();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Error_State::slide2_free() {
	std::cout << "ErrorFSM: slide2_free called" << std::endl;
	TriggerProcessingState processingstate = errorsubmachine->slide2_free();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

void Error_State::showState() {
    std::cout << "  MainFsm: Error_State" << std::endl;
	errorsubmachine->showState();
}


