//
// Created by trung on 01/06/2024.
//

#ifndef OPERATION_H
#define OPERATION_H
#include "basestate.h"


class EStoppFSM : public BaseState {
public:
    void entry() override;
    void exit() override;

    void handleDefaultExit(const TriggerProcessingState &handled) override;

    void ss_t_est1_pressed() override;
    void ss_t_est2_pressed() override;
    void connection_lost() override;
    void connection_back() override;
    void ss_t_est1_unpressed() override;
    void ss_t_est2_unpressed() override;
    void ss_t_rst1_pressed() override;
    void ss_t_rst2_pressed() override;

    void enterViaPortE1() override;
    void enterViaPortE2() override;
    void enterViaPortCL() override;

    void showState() override;
};

#endif //OPERATION_H
