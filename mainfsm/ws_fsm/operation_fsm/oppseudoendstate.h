/*
 * oppseudoendstate.h
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_OPPSEUDOENDSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_OPPSEUDOENDSTATE_H_

#include "opbasestate.h"


class OpPseudoEndState : public opbasestate {
public:
    bool isPseudoEndState() override {return true;};

    void enterViaDeepHistory() override { enterViaPseudoStart();};

    void showState() override {std::cout << "State: OP End State" << std::endl;}; // Just for illustration!
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_OPPSEUDOENDSTATE_H_ */
