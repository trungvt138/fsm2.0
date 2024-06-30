//
// Created by Trung Dam on 29.06.24.
//

#ifndef BOTH_FULL_H
#define BOTH_FULL_H
#include "checkslidebasestate.h"


class Both_Full : public CheckSlideBaseState {
public:
    void entry() override;

    void ss_ls_sli1_rise() override;

    void ss_ls_sli2_rise() override;

    void showState() override;
};



#endif //BOTH_FULL_H
