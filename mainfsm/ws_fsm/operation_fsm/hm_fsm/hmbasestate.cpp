/*
 * hmbasestate.cpp
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#include "hmbasestate.h"
#include "waiting_height.h"

void HMBaseState::enterViaPseudoStart() {
    std::cout << "HM FSM Initial Trasition taken" << std::endl;
    new(this) Waiting_Height;
    enterByDefaultEntryPoint();
}


void HMBaseState::setData(ContextData *data){
    this->data = data;
}

void HMBaseState::setAction(Actions *action){
	this->action = action;
}

void HMBaseState::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}


// TriggerProcessingState HMBaseState::handleDefaultExit(const TriggerProcessingState &handled) {
//     return TriggerProcessingState::pending;
// };

