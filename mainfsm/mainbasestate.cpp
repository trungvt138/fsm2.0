//
// Created by trung on 31/05/2024.
//

#include "mainbasestate.h"

#include <iostream>

#include "idle.h"


void MainBaseState::enterViaPseudoStart() {
    std::cout << "MainFsm Initial Trasition taken" << std::endl;
    new(this) Idle;
    enterByDefaultEntryPoint();
}



