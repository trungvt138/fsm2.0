//
// Created by trung on 07/06/2024.
//

#ifndef WSSTATE_H
#define WSSTATE_H

#include "mainbasestate.h"

class WS_State : public MainBaseState {
public:
    void entry() override;
    void exit() override;
    TriggerProcessingState ss_t_stp_pressed() override;

    //TODO: These three methods must be renamed!!!
    TriggerProcessingState ws_gone() override;
    TriggerProcessingState ws_false_placement() override;
    TriggerProcessingState both_slide_full() override;

    void showState() override;
};

#endif //WSSTATE_H
