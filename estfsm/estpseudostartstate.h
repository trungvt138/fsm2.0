//
// Created by trung on 01/06/2024.
//

#ifndef ESTSEUDOSTARTSTATE_H
#define ESTSEUDOSTARTSTATE_H
#include <iostream>

#include "estbasestate.h"

class EstPseudoStartState : public EstBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void showState() override {
        std::cout << "State : EStFsm Pseudo Start State" << std::endl;
    }
};

#endif //ESTSEUDOSTARTSTATE_H
