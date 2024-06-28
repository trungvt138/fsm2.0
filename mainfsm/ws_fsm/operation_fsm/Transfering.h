/*
 * transport.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_

#include "opbasestate.h"


class Transfering : public opbasestate {
public:

    void entry() override;
    void exit() override {};

    TriggerProcessingState ss_ls_end1_interrupted() override;
    TriggerProcessingState ss_ls_end2_interrupted() override;

    TriggerProcessingState ss_ls_str2_interrupted() override;


    TriggerProcessingState ws_sorted(); //override;
    TriggerProcessingState ss_ls_end2_continuous() override;

    void handleDefaultExit(const TriggerProcessingState &handled) override;
    void enterByDeepHistoryEntryPoint() override;

    void leavingState() override {exit();};

    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_TRANSPORT_H_ */
