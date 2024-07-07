//
// Created by Trung Dam on 24.06.24.
//

#ifndef RESETPSEUDOENDSTATE_H
#define RESETPSEUDOENDSTATE_H
#include <ostream>

#include "resetbasestate.h"


class ResetPseudoEndState : public ResetBaseState {
public:
    bool isPseudoEndState() override {return true;};

    void showState() override {
        std::cout << "\nState : Reset Pseudo End State" << std::endl;
    }
};



#endif //RESETPSEUDOENDSTATE_H
