/*
* anstehend_unquittiert_1.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#include "anstehend_unquittiert_1.h"
#include "errorpseudoendstate.h"

#include <iostream>

void Anstehend_Unquittiert_1::entry() {
	//TODO: AK_L_ROT_BLINK_FAST
}

TriggerProcessingState Anstehend_Unquittiert_1::ss_t_rst1_pressed() {
	std::cout << "Anstehend_Unquittiert_1::ss_t_rst1_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;


}

TriggerProcessingState Anstehend_Unquittiert_1::ss_t_rst2_pressed() {
	std::cout << "Anstehend_Unquittiert_1::ss_t_rst2_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;

}

void Anstehend_Unquittiert_1::showState() {
	std::cout << "ErrorSubMachine: Anstehend_Unquittiert_1" << std::endl;
}

