//
// Created by trung on 24/06/2024.
//

#ifndef WAIT_FOR_RESET2_H
#define WAIT_FOR_RESET2_H
#include "resetbasestate.h"


class Wait_For_Reset2 : public ResetBaseState {
public:
    TriggerProcessingState ss_t_rst2_pressed() override;
    void showState() override;
};



#endif //WAIT_FOR_RESET2_H
