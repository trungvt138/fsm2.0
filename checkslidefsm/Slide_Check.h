//
// Created by Trung Dam on 29.06.24.
//

#ifndef SLIDE_CHECK_H
#define SLIDE_CHECK_H
#include "checkslidebasestate.h"


class Slide_Check : CheckSlideBaseState {
public:
    void entry() override;

    void ss_ls_sli1_rise() override;

    void ss_ls_sli2_rise() override;

    void after1s() override;

    void showState() override;
};



#endif //SLIDE_CHECK_H
