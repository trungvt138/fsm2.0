/*
 * Transport.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_

#include "opbasestate.h"


class Transport : public OpBaseState {
public:

    void entry() override;
    void exit() override {};

    TriggerProcessingState height_ok1_active() override;
    TriggerProcessingState height_ok2_active() override;
    TriggerProcessingState ws_sorted_FBA1() override;

    void leavingState() override {exit();};

    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_ */
