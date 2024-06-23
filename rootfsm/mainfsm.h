//
// Created by trung on 31/05/2024.
//

#ifndef MAIN_FSM_H
#define  MAIN_FSM_H
#include "basestate.h"


class MainFsm : public BaseState {
public:
    void enterByDefaultEntryPoint() override;

    void entry() override;
    void exit() override;

    void ss_t_str_longpressed() override;
    void ss_t_str_shortpressed() override;
    void ss_t_stp_pressed() override;
    void ws_false_placement() override;
    void ws_gone() override;
    void both_slide_full() override;
    void ss_t_est1_pressed() override;
    void ss_t_est2_pressed() override;
    void connection_lost() override;

    void showState() override;
};



#endif // MAIN_FSM_H
