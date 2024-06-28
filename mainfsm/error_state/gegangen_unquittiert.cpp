/*
* gegangen_unquittiert.cpp
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */
#include <iostream>
#include "gegangen_unquittiert.h"
#include "errorpseudoendstate.h"

void Gegangen_Unquittiert::entry() {
	//TODO: AK_L_ROT_BLINK_SLOW
}

TriggerProcessingState Gegangen_Unquittiert::ss_t_rst1_pressed() {
	std::cout << "Gegangen_Unquittiert::ss_t_rst1_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;


}

TriggerProcessingState Gegangen_Unquittiert::ss_t_rst2_pressed() {
	std::cout << "Gegangen_Unquittiert::ss_t_rst1_pressed called" << std::endl;
	leavingState();
	new(this) ErrorPseudoEndState;
	enterByDefaultEntryPoint();
	return TriggerProcessingState::endstatereached;

}

void Gegangen_Unquittiert::showState() {
	std::cout << "ErrorSubMachine: Gegangen_Unquittiert" << std::endl;
}