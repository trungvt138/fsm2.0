/*
* Slide2_Emptied.cpp
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */
#include <iostream>
#include "Slide2_Emptied.h"
#include "bothslidefullpseudoendstate.h"

TriggerProcessingState Slide2_Emptied::slide1_free() {
	std::cout << "Slide2_Emptied::slide1_free called" << std::endl;
	leavingState();
	new(this) BothSlideFullPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void Slide2_Emptied::showState() {
	std::cout << "BothSlideFsm: Slide2_Emptied" << std::endl;
}