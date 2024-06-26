//
// Created by Trung Dam on 25.06.24.
//

#include "wsidle.h"

#include <iostream>

TriggerProcessingState WSIdle::ss_ls_str1_interrupted() {
    std::cout << "WSIdle: ss_ls_str1_interrupted called" << std::endl;
    leavingState();
    new(this) WSOperationState;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}
