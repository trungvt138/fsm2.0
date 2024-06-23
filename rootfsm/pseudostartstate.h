//
// Created by trung on 31/05/2024.
//

#ifndef PSEUDOSTARTSTATE_H
#define PSEUDOSTARTSTATE_H
#include "basestate.h"


class PseudoStartState : public BaseState {
public:
    bool isPseudoStartState() override;

    void showState() override;
};



#endif //PSEUDOSTARTSTATE_H
