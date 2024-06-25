//
// Created by trung on 31/05/2024.
//

#include <iostream>

#include "actions.h"
#include "context.h"

int main(int argc, char** argv) {
    auto *action = new Actions();
    Context fsmA(action);
    // fsmA.showState();
    // fsmA.ss_t_str_longpressed();
    // fsmA.showState();
    // fsmA.ss_t_str_shortpressed();
    // fsmA.showState();
    // fsmA.ss_t_str_shortpressed();
    // fsmA.showState();
    // fsmA.ss_t_stp_pressed();
    // fsmA.ss_t_str_shortpressed();
    // fsmA.showState();
    // fsmA.ws_gone();
    // fsmA.showState();
    fsmA.showState();
    fsmA.ss_t_est2_pressed();
    fsmA.showState();
    fsmA.ss_t_est1_pressed();
    fsmA.showState();
    fsmA.ss_t_est1_unpressed();
    fsmA.showState();
    fsmA.ss_t_est2_unpressed();
    fsmA.showState();
    fsmA.ss_t_rst1_pressed();
    fsmA.showState();
    fsmA.ss_t_rst2_pressed();
    fsmA.showState();
}

