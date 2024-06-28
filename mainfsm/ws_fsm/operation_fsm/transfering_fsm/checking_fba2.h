//
// Created by Trung Dam on 26.06.24.
//

#ifndef CHECKING_FBA2_H
#define CHECKING_FBA2_H
#include "transferingbasestate.h"
#include <iostream>
using namespace std;

class Checking_FBA2 : TransferingBaseState {
public:
    void entry() override;

    void exit() override;

    TriggerProcessingState ws_sorted() override;

    void showState() override;
};



#endif //CHECKING_FBA2_H
