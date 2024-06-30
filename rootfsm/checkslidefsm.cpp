//
// Created by Trung Dam on 29.06.24.
//

#include "checkslidefsm.h"
#include <iostream>
using namespace std;

void CheckSlideFSM::entry() {
    BaseState::entry();
}

void CheckSlideFSM::ss_ls_sli1_rise() {
    BaseState::ss_ls_sli1_rise();
}

void CheckSlideFSM::ss_ls_sli1_full() {
    BaseState::ss_ls_sli1_full();
}

void CheckSlideFSM::ss_ls_sli2_rise() {
    BaseState::ss_ls_sli2_rise();
}

void CheckSlideFSM::ss_ls_sli2_full() {
    BaseState::ss_ls_sli2_full();
}

void CheckSlideFSM::after1s() {
    BaseState::after1s();
}

void CheckSlideFSM::showState() {
    cout << "State: CheckSlideFSM" << endl;
}
