/*
 * oppseudostartstate.h
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_OPPSEUDOSTARTSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_OPPSEUDOSTARTSTATE_H_
#include "opbasestate.h"

class OpPseudoStartState : public OpBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void enterViaDeepHistory() override {enterViaPseudoStart();};

    void showState() override {std::cout << "\nState: OP Start State\n" << std::endl;}; // Just for illustration!
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_OPPSEUDOSTARTSTATE_H_ */
