/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef SRC_FSM_SIMPLE_ESTFSM_ESTOP1_PRESSED_H_
#define SRC_FSM_SIMPLE_ESTFSM_ESTOP1_PRESSED_H_


#include "estbasestate.h"


class EST1_and_CL : public EstBaseState {
public:
    TriggerProcessingState ss_t_est1_unpressed() override;
    void showState() override;
};

#endif //SRC_FSM_SIMPLE_ESTFSM_ESTOP1_PRESSED_H_


