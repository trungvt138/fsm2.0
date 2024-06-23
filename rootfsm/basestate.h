//
// Created by trung on 31/05/2024.
//

#ifndef BASESTATE_H
#define BASESTATE_H
#include "../actions.h"
#include "../contextdata.h"
#include "../mainfsm/mainbasestate.h"
#include "../estfsm/estbasestate.h"


class BaseState {
protected:
    ContextData *data;
    Actions *action;
    EstBaseState *estoppsubmachine;
    MainBaseState *mainsubmachine;
public:
    virtual ~BaseState() {
        delete estoppsubmachine;
        delete mainsubmachine;
    };

    virtual void initSubStateMachines();

    void setData(ContextData *data);
    void setAction(Actions *action);

    virtual bool isPseudoStartState() {return false;};
    virtual bool isPseudoEndState() {return false;};

    virtual void enterByDefaultEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaPseudoStart();
    virtual void enterViaPortE1(){};
    virtual void enterViaPortE2(){};
    virtual void enterViaPortCL(){};

    // entry/exit-actions
    virtual void entry(){};
    virtual void exit(){};

    // Trigger
    virtual void ss_t_str_longpressed() {};
    virtual void ss_t_str_shortpressed() {};
    virtual void ss_t_stp_pressed() {};
    virtual void ws_false_placement() {};
    virtual void ws_gone() {};
    virtual void both_slide_full() {}
    virtual void ss_t_est1_pressed() {};
    virtual void ss_t_est2_pressed() {};
    virtual void connection_lost() {};
    virtual void connection_back() {};
    virtual void ss_t_est1_unpressed() {};
    virtual void ss_t_est2_unpressed() {};

    virtual void showState() {};
};



#endif //BASESTATE_H
