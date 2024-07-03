//
// Created by trung on 24/06/2024.
//

#ifndef WAIT_FOR_RESET1_H
#define WAIT_FOR_RESET1_H
#include "resetbasestate.h"


class Wait_For_Reset1 : public ResetBaseState {
public:
    void entry() override;
    TriggerProcessingState ss_t_rst1_pressed() override;
    void showState() override;
};



#endif //WAIT_FOR_RESET1_H
