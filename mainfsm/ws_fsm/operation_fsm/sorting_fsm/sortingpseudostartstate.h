//
// Created by Trung Dam on 26.06.24.
//

#ifndef SORTINGPSEUDOSTARTSTATE_H
#define SORTINGPSEUDOSTARTSTATE_H
#include "sortingbasestate.h"

class SortingPseudoStartState : public SortingBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void enterViaDeepHistory() override { enterViaPseudoStart();};

    void showState() override {std::cout << "State: Sorting Pseudo Start State" << std::endl;}; // Just for illustration!
};
#endif //SORTINGPSEUDOSTARTSTATE_H
