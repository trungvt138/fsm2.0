//
// Created by Trung Dam on 29.06.24.
//

#include "Slide_Check.h"
#include <iostream>

#include "Slide_Free.h"
#include "Slide_Full.h"
using namespace std;

void Slide_Check::entry() {
    showState();
}

void Slide_Check::ss_ls_sli1_rise() {
    cout << "Slide_Check: ss_ls_sli1_rise called" << endl;
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Slide_Check::ss_ls_sli2_rise() {
    cout << "Slide_Check: ss_ls_sli2_rise called" << endl;
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Slide_Check::after1s() {
    cout << "Slide_Check: after1s called" << endl;
    new(this) Slide_Full;
    enterByDefaultEntryPoint();
}

void Slide_Check::showState() {
    cout << "CheckSlideFsm: Slide_Check" << endl;
}
