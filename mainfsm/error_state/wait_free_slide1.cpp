/*
* wait_free_slide1.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */
#include <iostream>
#include "wait_free_slide1.h"
#include "errorpseudoendstate.h"

TriggerProcessingState Wait_Free_Slide1::slide1_free() {
	std::cout << "Wait_Free_Slide1::slide1_free called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

TriggerProcessingState Wait_Free_Slide1::slide2_free() {
	std::cout << "Wait_Free_Slide1::slide2_free called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void Wait_Free_Slide1::showState() {
	std::cout << "ErrorSubMachine: Wait_Free_Slide1" << std::endl;
}