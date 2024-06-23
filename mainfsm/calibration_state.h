//
// Created by trung on 05/06/2024.
//

#ifndef CALIBRATIONSTATE_H
#define CALIBRATIONSTATE_H
#include "mainbasestate.h"


class Calibration_State : public MainBaseState {
public:
    void entry() override;
    void exit() override;
    TriggerProcessingState ss_t_str_shortpressed() override;
    void showState() override;
};



#endif //CALIBRATIONSTATE_H
