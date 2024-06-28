/*
* Both_Slide_Full_State.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */
#include <iostream>
#include "../../subcommon/triggerprocessingstate.h"
#include "Both_Slide_Full_State.h"
#include "gegangen_unquittiert.h"
#include "anstehend_quittiert.h"
#include <iostream>
using namespace std;

void Both_Slide_Full_State::enterByDefaultEntryPoint() {
	cout << "Both_Slide_Full_State::enterByDefaultEntryPoint called" << endl;
	entry();
	bothSlideSubState->enterViaPseudoStart();
}

TriggerProcessingState Both_Slide_Full_State::ss_t_rst1_pressed() {
	cout << "Both_Slide_Full_State::ss_t_rst1_pressed called" << endl;
	leavingState();
	new(this) Anstehend_Quittiert;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Both_Slide_Full_State::ss_t_rst2_pressed() {
	cout << "Both_Slide_Full_State::ss_t_rst2_pressed called" << endl;
	leavingState();
	new(this) Anstehend_Quittiert;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Both_Slide_Full_State::slide1_free() {
	cout << "Both_Slide_Full_State::slide1_free called" << endl;
	TriggerProcessingState processingstate = bothSlideSubState->slide1_free();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Both_Slide_Full_State::slide2_free() {
	cout << "Both_Slide_Full_State::slide2_free called" << endl;
	TriggerProcessingState processingstate = bothSlideSubState->slide2_free();
	handleDefaultExit(processingstate);
	return TriggerProcessingState::consumed;
}

void Both_Slide_Full_State::handleDefaultExit(const TriggerProcessingState &processingstate) {
	if (processingstate == TriggerProcessingState::endstatereached) {
		bothSlideSubState->exit();
		leavingState();
		new(this) Gegangen_Unquittiert;
		enterByDefaultEntryPoint();
	}
}

void Both_Slide_Full_State::showState() {
	cout << "ErrorSubMachine: Both_Slide_Full_State" << endl;
	bothSlideSubState->showState();
}
