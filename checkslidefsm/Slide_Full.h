//
// Created by Trung Dam on 29.06.24.
//

#ifndef SLIDE_FULL_H
#define SLIDE_FULL_H
#include "checkslidebasestate.h"


class Slide_Full : public CheckSlideBaseState {
public:
    void entry() override;

    void exit() override;

    void ss_ls_sli1_rise() override;

    void ss_ls_sli1_full() override;

    void ss_ls_sli2_rise() override;

    void ss_ls_sli2_full() override;

    void showState() override;
};



#endif //SLIDE_FULL_H
