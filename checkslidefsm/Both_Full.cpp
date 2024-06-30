//
// Created by Trung Dam on 29.06.24.
//

#include "Both_Full.h"
#include <iostream>

#include "Slide_Free.h"
using namespace std;

void Both_Full::entry() {
    showState();
}

void Both_Full::ss_ls_sli1_rise() {
    cout << "Both_Full: ss_ls_sli1_rise called";
    //Send Slide_Free Signal
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Both_Full::ss_ls_sli2_rise() {
    cout << "Both_Full: ss_ls_sli2_rise called";
    //Send Slide_Free Signal
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Both_Full::showState() {
    cout << "CheckSlideFsm: Both_Full" << endl;
}
