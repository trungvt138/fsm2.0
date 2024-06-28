//
// Created by Trung Dam on 26.06.24.
//

#ifndef TRANSFERINGIDLE_H
#define TRANSFERINGIDLE_H
#include "transferingbasestate.h"
#include <iostream>
using namespace std;

class TransferingIdle : public TransferingBaseState {
public:
    TriggerProcessingState ss_ls_end1_interrupted() override;

    TriggerProcessingState ss_ls_end2_interrupted() override;

    void showState() override;
};



#endif //TRANSFERINGIDLE_H
