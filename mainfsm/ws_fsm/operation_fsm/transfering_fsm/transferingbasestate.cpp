/*
 * transferingbasestate.cpp
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#include "transferingbasestate.h"

#include <iostream>

#include "transferingidle.h"

void TransferingBaseState::enterViaPseudoStart() {
    std::cout << "Transfering Fsm Initial Transition taken" << std::endl;
    new(this) TransferingIdle;
    enterByDefaultEntryPoint();
}

void TransferingBaseState::enterViaDeepHistory() {
    enterByDeepHistoryEntryPoint();
}

