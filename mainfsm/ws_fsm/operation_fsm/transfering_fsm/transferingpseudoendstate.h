//
// Created by Trung Dam on 26.06.24.
//

#ifndef TRANSFERINGPSEUDOENDSTATE_H
#define TRANSFERINGPSEUDOENDSTATE_H
#include <iostream>

#include "transferingbasestate.h"

class TransferingPseudoEndState : public TransferingBaseState {
public:
    bool isPseudoEndState() override {return true;};

    //void enterViaDeepHistory() override { enterViaPseudoStart();};

    void showState() override {std::cout << "State: Transfering Pseudo End State" << std::endl;}; // Just for illustration!

};

#endif //TRANSFERINGPSEUDOENDSTATE_H
