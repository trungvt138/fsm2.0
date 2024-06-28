/*
* anstehend_unquittiert_2.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */


#include "anstehend_unquittiert_2.h"
#include "errorpseudoendstate.h"

#include <iostream>

void Anstehend_Unquittiert_2::entry() {
	//TODO: Reset order (if right order)
	action->ak_l_rot1_blink_fast();
	action->ak_l_rot2_blink_fast();
}

TriggerProcessingState Anstehend_Unquittiert_2::ss_t_rst1_pressed() {
	std::cout << "Anstehend_Unquittiert_1::ss_t_rst1_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;


}

TriggerProcessingState Anstehend_Unquittiert_2::ss_t_rst2_pressed() {
	std::cout << "Anstehend_Unquittiert_1::ss_t_rst2_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;

}

void Anstehend_Unquittiert_2::showState() {
	std::cout << "ErrorSubMachine: Anstehend_Unquittiert_2" << std::endl;
}