/*
 * height_measurement.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HEIGHT_MEASUREMENT_H_
#define SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HEIGHT_MEASUREMENT_H_
#include "opbasestate.h"

class Height_Measurement : public OpBaseState {
public:
    void entry() override;
    void exit() override;
    void showState() override;
    void handleDefaultExit(const TriggerProcessingState &handled) override;
	void enterByDeepHistoryEntryPoint() override;

	TriggerProcessingState height_ok1_unactive()override;
	TriggerProcessingState height_calibration()override;
	TriggerProcessingState height_band() override;
	TriggerProcessingState height_flat()override;
	TriggerProcessingState height_high()override;
	TriggerProcessingState height_hole()override;
};



#endif /* SRC_FSMSIMPLE_MAINFSM_WS_FSM_OPERATION_FSM_HEIGHT_MEASUREMENT_H_ */
