/*
 * measuring_height.h
 *
 *  Created on: 26.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_MEASURING_HEIGHT_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_MEASURING_HEIGHT_H_

#include "hmbasestate.h"

class Measuring_Height : public HMBaseState {
public:

    void entry() override;
    void exit() override{};
    TriggerProcessingState height_high() override;
    TriggerProcessingState height_flat() override;
    TriggerProcessingState height_calibration() override;

    void leavingState() override {exit();};
    void showState() override;

};

#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HM_FSM_MEASURING_HEIGHT_H_ */
