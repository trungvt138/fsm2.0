//
// Created by Trung Dam on 29.06.24.
//

#ifndef SLIDE_FREE_H
#define SLIDE_FREE_H
#include "checkslidebasestate.h"


class Slide_Free : public CheckSlideBaseState {
public:
    void entry() override;

    void ss_ls_sli1_full() override;

    void ss_ls_sli2_full() override;

    void showState() override;
};



#endif //SLIDE_FREE_H
