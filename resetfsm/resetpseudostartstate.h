//
// Created by Trung Dam on 22.06.24.
//

#ifndef RESETPSEUDOSTARTSTATE_H
#define RESETPSEUDOSTARTSTATE_H
#include <iostream>

#include "resetbasestate.h"


class ResetPseudoStartState : public ResetBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void showState() override {
        std::cout << "State : Reset Pseudo Start State" << std::endl;
    }
};



#endif //RESETPSEUDOSTARTSTATE_H
