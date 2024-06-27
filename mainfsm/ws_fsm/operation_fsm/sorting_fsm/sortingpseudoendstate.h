//
// Created by Trung Dam on 27.06.24.
//

#ifndef SORTINGPSEUDOENDSTATE_H
#define SORTINGPSEUDOENDSTATE_H
#include <iostream>

#include "sortingbasestate.h"

class SortingPseudoEndState : public SortingBaseState {
public:
    bool isPseudoEndState() override {return true;};

    //void enterViaDeepHistory() override { enterViaPseudoStart();};

    void showState() override {std::cout << "State: Sorting Pseudo End State" << std::endl;}; // Just for illustration!
};
#endif //SORTINGPSEUDOENDSTATE_H
