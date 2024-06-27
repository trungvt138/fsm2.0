//
// Created by Trung Dam on 26.06.24.
//

#ifndef WAITING_REMOVE_H
#define WAITING_REMOVE_H
#include "transferingbasestate.h"
#include <iostream>
using namespace std;

class Waiting_Remove : public TransferingBaseState {
public:
    void entry() override;

    void exit() override;

    TriggerProcessingState ss_ls_end2_continuous() override;

    void showState() override;
};



#endif //WAITING_REMOVE_H
