//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXT_H
#define CONTEXT_H
#include "actions.h"
#include "contextdata.h"
#include "rootfsm/basestate.h"


class Context {
private:
    BaseState *state;
    Actions *action;
    ContextData data;
public:
    Context(Actions *shared_action);
    virtual ~Context();

    void ss_t_str_longpressed();
    void ss_t_str_shortpressed();
    void ss_t_stp_pressed();
    void ws_false_placement();
    void ws_gone();
    void both_slide_full();
    void ss_t_est1_pressed();
    void ss_t_est2_pressed();
    void connection_lost();
    void ss_t_est1_unpressed();
    void ss_t_est2_unpressed();
    void connection_back();

    void showState();
};



#endif //CONTEXT_H
