
//
// Created by Trung Dam on 26.06.24.
//



//class HMPseudoStartState : public HMBaseState {
//
//};
//#endif //HMPSEUDOSTARTSTATE_H
//
///*
// * hmpseudostartstate.h
// *
// *  Created on: 26.06.2024
// *      Author: infwur761
// */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_HMPSEUDOSTARTSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_HMPSEUDOSTARTSTATE_H_

#include "hmbasestate.h"

class HMPseudoStartState : public HMBaseState {
public:
    bool isPseudoStartState() override {return true;};

    void enterViaDeepHistory() override {enterViaPseudoStart();};

    void showState() override {std::cout << "State: HM Start State" << std::endl;}; // Just for illustration!
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_HMPSEUDOSTARTSTATE_H_ */

