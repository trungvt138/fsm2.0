//
// Created by Trung Dam on 29.06.24.
//

#ifndef CHECKSLIDEPSEUDOSTARTSTATE_H
#define CHECKSLIDEPSEUDOSTARTSTATE_H
#include "checkslidebasestate.h"
#include <iostream>
using namespace std;


class Actions;

class CheckSlidePseudoStartState : CheckSlideBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void showState() override {cout << "CheckSlideFsm: Pseudo Start State" << endl;};
};



#endif //CHECKSLIDEPSEUDOSTARTSTATE_H
