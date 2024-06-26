//
// Created by Trung Dam on 25.06.24.
//

#ifndef WSIDLE_H
#define WSIDLE_H
#include "wsbasestate.h"


class WSIdle : WSBaseState {
public:
    TriggerProcessingState ss_ls_str1_interrupted() override;
    void showState() override;
};



#endif //WSIDLE_H
