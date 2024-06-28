/*
 * ws_hole.h
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_HOLE_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_HOLE_H_

#include "hmbasestate.h"

class WS_Hole : public HMBaseState {
public:
    void entry() override;
    void exit() override {};

    TriggerProcessingState height_high() override;

    void leavingState() override {exit();};
    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_WS_HOLE_H_ */
