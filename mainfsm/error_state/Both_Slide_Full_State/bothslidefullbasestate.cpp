/*
 * bothslidefullbasestate.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */
#include <iostream>
#include "bothslidefullbasestate.h"
#include "Anstehend_Unquittiert.h"

void BothSlideFullBaseState::enterViaPseudoStart() {
	std::cout << "BothSlideFullBaseState Initial Transition taken" << std::endl;
	leavingState();
	new(this) Anstehend_Unquittiert;
	enterByDefaultEntryPoint();
}

void showState() {};

