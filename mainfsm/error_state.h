//
// Created by trung on 07/06/2024.
//

#ifndef OPSORT_H
#define OPSORT_H
#include "mainbasestate.h"


class Error_State : public MainBaseState {
public:
    void entry() override;
    void exit() override;
    void showState() override;
};

#endif //OPSORT_H
