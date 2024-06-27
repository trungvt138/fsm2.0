/*
 * transport.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_

#include "opbasestate.h"


class transport : opbasestate {
public:

    void entry() override;
    void exit() override {};

    TriggerProcessingState ss_ls_str1_continuous() override;
    TriggerProcessingState ss_ls_str2_continuous() override;
    TriggerProcessingState ws_sorted_FBA1() override;

    void leavingState() override {exit();};

    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_ */
