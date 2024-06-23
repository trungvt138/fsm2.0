/*
 * estpseudoendstate.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef EST_PSEUDOENDSTATE_H
#define EST_PSEUDOENDSTATE_H
#include <iostream>

#include "estbasestate.h"

class EstPseudoEndState : public EstBaseState {
public:
    bool isPseudoEndState() override {return true;};

    void showState() override {
        std::cout << "State : EStFsm Pseudo End State" << std::endl;
      }
};



#endif /* EST_PSEUDOENDSTATE_H */
