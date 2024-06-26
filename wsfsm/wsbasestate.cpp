//
// Created by Trung Dam on 25.06.24.
//

#include "wsbasestate.h"

#include <iostream>

#include "wsidle.h"

void WSBaseState::enterViaPseudoStart() {
    std::cout << "WSFsm Initial Trasition taken" << std::endl;
    new(this) WSIdle;
    enterByDefaultEntryPoint();
}

void WSBaseState::initSubStateMachines() {

}
