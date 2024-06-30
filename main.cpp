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
    fsmA.ss_t_str1_shortpressed();

    //Enter Operation
    fsmA.ss_ls_str1_interrupted();

    fsmA.ss_ls_str1_continuous();
    fsmA.height_calibration();
    fsmA.height_calibration();
    fsmA.ss_ls_srt1_interrupted();

}

