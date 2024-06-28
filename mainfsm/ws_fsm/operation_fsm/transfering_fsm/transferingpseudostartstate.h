//
// Created by Trung Dam on 26.06.24.
//

#ifndef TRANSFERINGPSEUDOSTARTSTATE_H
#define TRANSFERINGPSEUDOSTARTSTATE_H
#include "transferingbasestate.h"
#include <iostream>

class TransferingPseudoStartState : public TransferingBaseState {
public:
    bool isPseudoStartState() override {return true;};

    //void enterViaDeepHistory() override { enterViaPseudoStart();};

    void showState() override {std::cout << "State: Transfering Pseudo Start State" << std::endl;}; // Just for illustration!

};
#endif //TRANSFERINGPSEUDOSTARTSTATE_H
