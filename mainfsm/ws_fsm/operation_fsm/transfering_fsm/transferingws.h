//
// Created by Trung Dam on 26.06.24.
//

#ifndef TRANSFERINGWS_H
#define TRANSFERINGWS_H
#include "transferingbasestate.h"
#include <iostream>
using namespace std;

class TransferingWS : public TransferingBaseState {
public:
    void entry() override;
    TriggerProcessingState ss_ls_str2_interrupted() override;

    void showState() override;
};



#endif //TRANSFERINGWS_H
