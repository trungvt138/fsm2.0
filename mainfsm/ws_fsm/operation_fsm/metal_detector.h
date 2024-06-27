/*
 * metal_detector.h
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_METAL_DETECTOR_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_METAL_DETECTOR_H_

#include "opbasestate.h"

class Metal_Detector : opbasestate {
public:
    void entry() override;
    void exit() override {};

    TriggerProcessingState ss_ls_srt1_interrupted() override;
    TriggerProcessingState ss_ls_srt2_interrupted() override;
    TriggerProcessingState ss_ms1_erkannt() override;
    TriggerProcessingState ss_ms2_erkannt() override;


    void leavingState() override {exit();};

    void showState() override;

};



#endif /* SRC_FSMSIMPLE_MAINFSM_OPERATION_FSM_METAL_DETECTOR_H_ */
