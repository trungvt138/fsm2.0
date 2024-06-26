/*
 * wspseudostartstate.h
 *
 *  Created on: 25.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_WSPSEUDOSTARTSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_WSPSEUDOSTARTSTATE_H_
#include <iostream>

#include "wsbasestate.h"

class WSPseudoStartState : public WSBaseState {

public:
	bool isPseudoStartState() override {return true;};

    void enterViaDeepHistory() override {enterViaPseudoStart();};

    void showState() override {std::cout << "WSFsm: WS Pseudo Start State" << std::endl;};
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_WSPSEUDOSTARTSTATE_H_ */
