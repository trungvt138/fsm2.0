//
// Created by trung on 31/05/2024.
//

#ifndef IDLE_H
#define IDLE_H
#include "mainbasestate.h"


class Idle : public MainBaseState {
public:
    void entry() override;

    TriggerProcessingState ss_t_str_longpressed() override;
    TriggerProcessingState ss_t_str_shortpressed() override;

    void showState() override;
};

#endif //IDLE_H
