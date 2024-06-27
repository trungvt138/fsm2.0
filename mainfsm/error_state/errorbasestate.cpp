/*
 * errorbasestate.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#include "errorbasestate.h"
#include <iostream>

#include "anstehend_unquittiert_1.h"
#include "Both_Slide_Full_State.h"
#include "anstehend_unquittiert_2.h"

void ErrorBaseState::enterViaPort_both_slide_full() {
	std::cout << "ErrorBaseState both_slide_full port-trasition taken" << std::endl;
	new(this) Both_Slide_Full_State;
	enterByDefaultEntryPoint();
}

void ErrorBaseState::enterViaPort_false_placement() {
	std::cout << "ErrorBaseState false_placement port-trasition taken" << std::endl;
	new(this) Anstehend_Unquittiert_1;
	enterByDefaultEntryPoint();
}

void ErrorBaseState::enterViaPort_WSgone() {
	std::cout << "ErrorBaseState ws_gone port-trasition taken" << std::endl;
	new(this) Anstehend_Unquittiert_2;
	enterByDefaultEntryPoint();
}
