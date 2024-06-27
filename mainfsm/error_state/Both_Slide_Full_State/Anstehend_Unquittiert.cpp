/*
 * Anstehend_Unquittiert.cpp
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */

#include <iostream>
#include "Anstehend_Unquittiert.h"
#include "Slide1_Emptied.h"
#include "Slide2_Emptied.h"
using namespace std;

TriggerProcessingState Anstehend_Unquittiert::slide1_free() {
	cout << "Anstehend_Unquittiert::slide1_free called" << endl;
	leavingState();
	new(this) Slide1_Emptied;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}
TriggerProcessingState Anstehend_Unquittiert::slide2_free() {
	cout << "Anstehend_Unquittiert::slide2_free called" << endl;
	leavingState();
	new(this) Slide2_Emptied;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}
void Anstehend_Unquittiert::showState() {
	cout << "BothSlideFsm: Anstehend_Unquittiert" << endl;
}
