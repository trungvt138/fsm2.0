//
// Created by trung on 31/05/2024.
//

#include <iostream>

#include "actions.h"
#include "context.h"

int main(int argc, char** argv) {
    auto *action = new Actions();

    //Enter Idle
    Context fsmA(action);

    //Enter Calibration State
    fsmA.ss_t_str1_longpressed();
    fsmA.showState();

    //Enter Idle
    fsmA.ss_t_str1_shortpressed();
    fsmA.showState();

    //Enter WS_State -> WS_Idle
    fsmA.ss_t_str1_shortpressed();
    fsmA.showState();

    //Enter Operation_State -> Transport
    fsmA.ss_ls_str1_interrupted();
    fsmA.showState();

    //Enter Height Measurement
    fsmA.ss_ls_str1_continuous();
    fsmA.showState();

    //Enter Error Via Both Slide Full
    fsmA.both_slide_full();
    fsmA.showState();

    //Enter Slide 1 Emptied
    fsmA.slide1_free();
    fsmA.showState();

    //Enter Anstehend Quittiert
    fsmA.slide2_free();
    fsmA.showState();

    //Enter WS State
    fsmA.ss_t_rst1_pressed();
    fsmA.showState();
}
