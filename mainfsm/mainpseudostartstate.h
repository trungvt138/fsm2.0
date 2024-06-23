//
// Created by trung on 01/06/2024.
//

#ifndef OPPSEUDOSTARTSTATE_H
#define OPPSEUDOSTARTSTATE_H
#include <iostream>

#include "mainbasestate.h"

class MainPseudoStartState : public MainBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void showState() override {
        std::cout << "State : OP Pseudo Start State" << std::endl;
    }
};

#endif //OPPSEUDOSTARTSTATE_H
