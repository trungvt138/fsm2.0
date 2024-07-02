//
// Created by Trung Dam on 29.06.24.
//

#include "Slide_Free.h"
#include <iostream>

#include "Slide_Check.h"
using namespace std;

void Slide_Free::entry() {
    showState();
}

void Slide_Free::ss_ls_sli1_full() {
    cout << "Slide_Free: ss_ls_sli1_full called" << endl;
    new(this) Slide_Check;
    enterByDefaultEntryPoint();
}

void Slide_Free::ss_ls_sli2_full() {
    cout << "Slide_Free: ss_ls_sli2_full called" << endl;
    new(this) Slide_Check;
    enterByDefaultEntryPoint();
}

void Slide_Free::showState() {
    cout << "    CheckSlideFsm: Slide_Free" << endl;
}
