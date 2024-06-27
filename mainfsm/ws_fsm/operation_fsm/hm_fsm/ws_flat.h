/*
 * ws_flat.h
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_FLAT_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_FLAT_H_

#include "hmbasestate.h"

class WS_Flat : public HMBaseState {
public:
    void entry() override;
    void exit() override{};

    TriggerProcessingState height_band() override;

    void leavingState() override {exit();};
    void showState() override;
};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_FLAT_H_ */
