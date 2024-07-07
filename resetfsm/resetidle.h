//
// Created by trung on 24/06/2024.
//

#ifndef RESETIDLE_H
#define RESETIDLE_H
#include "resetbasestate.h"


class ResetIdle : public ResetBaseState {
public:
    void entry() override;
    TriggerProcessingState ss_t_rst1_pressed() override;
    TriggerProcessingState ss_t_rst2_pressed() override;

    void showState() override;
};



#endif //RESETIDLE_H
