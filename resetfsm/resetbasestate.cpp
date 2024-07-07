//
// Created by Trung Dam on 22.06.24.
//

#include "resetbasestate.h"

#include <iostream>

#include "resetidle.h"

void ResetBaseState::enterViaPseudoStart() {
    std::cout << "\nReset Fsm Initial Transition taken" << std::endl;
    new(this) ResetIdle;
    enterByDefaultEntryPoint();
}
