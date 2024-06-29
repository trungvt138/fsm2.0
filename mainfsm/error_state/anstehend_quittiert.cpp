/*
* anstehend_quittiert.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#include <iostream>
#include "anstehend_quittiert.h"
#include "wait_free_slide1.h"
#include "wait_free_slide2.h"

void Anstehend_Quittiert::entry() {
	std::cout << "Anstehend_Quittiert::entry called" << std::endl;

	//TODO: needs to be fixed
	//if FSM1
	action->ak_l_rot1_on();

	//if FSM2
	action->ak_l_rot2_on();

}

TriggerProcessingState Anstehend_Quittiert::slide1_free() {
	std::cout << "Anstehend_Quittiert::slide1_free called" << std::endl;
	leavingState();
	new(this) Wait_Free_Slide1;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Anstehend_Quittiert::slide2_free() {
	std::cout << "Anstehend_Quittiert::slide2_free called" << std::endl;
	leavingState();
	new(this) Wait_Free_Slide2;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::consumed;
}

void Anstehend_Quittiert::showState() {
	std::cout << "ErrorSubMachine: Anstehend_Quittiert" << std::endl;
}