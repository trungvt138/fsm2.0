/*
 * Slide1_Emptied.cpp
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */

#include <iostream>
#include "Slide1_Emptied.h"
#include "bothslidefullpseudoendstate.h"

TriggerProcessingState Slide1_Emptied::slide2_free() {
	std::cout << "Slide1_Emptied::slide2_free called" << std::endl;
	leavingState();
	new(this) BothSlideFullPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;
}

void Slide1_Emptied::showState() {
	std::cout << "BothSlideFsm: Slide1_Emptied" << std::endl;
}


