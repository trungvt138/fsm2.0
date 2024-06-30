//
// Created by Trung Dam on 29.06.24.
//

#include "Slide_Full.h"
#include <iostream>

#include "Both_Full.h"
#include "Slide_Free.h"
#include "../actions.h"
using namespace std;

void Slide_Full::entry() {
    action->ak_l_glb1_on();
    //slide1_full FBA1
    action->ak_l_glb2_on();
    //slide2_full FBA2
}

void Slide_Full::exit() {
    action->ak_l_glb1_off();
    //slide1_full FBA1
    action->ak_l_glb2_off();
    //slide2_full FBA2
}

void Slide_Full::ss_ls_sli1_rise() {
    cout << "Slide_Full: ss_ls_sli1_rise called" << endl;
    leavingState();
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Slide_Full::ss_ls_sli1_full() {
    cout << "Slide_Full: ss_ls_sli1_full called" << endl;
    leavingState();
    new(this) Both_Full;
    enterByDefaultEntryPoint();
}


void Slide_Full::ss_ls_sli2_rise() {
    cout << "Slide_Full: ss_ls_sli2_rise called" << endl;
    leavingState();
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}

void Slide_Full::ss_ls_sli2_full() {
    cout << "Slide_Full: ss_ls_sli2_full called" << endl;
    leavingState();
    new(this) Both_Full;
    enterByDefaultEntryPoint();
}

void Slide_Full::showState() {
    CheckSlideBaseState::showState();
}
