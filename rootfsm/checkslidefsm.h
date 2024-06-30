//
// Created by Trung Dam on 29.06.24.
//

#ifndef CHECKSLIDEFSM_H
#define CHECKSLIDEFSM_H
#include "basestate.h"


class CheckSlideFSM : public BaseState {
public:
    void entry() override;
    void ss_ls_sli1_rise() override;
    void ss_ls_sli1_full() override;
    void ss_ls_sli2_rise() override;
    void ss_ls_sli2_full() override;
    void after1s() override;
    void showState() override;
};



#endif //CHECKSLIDEFSM_H
