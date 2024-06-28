//
// Created by trung on 05/06/2024.
//

#ifndef CALIBRATIONSTATE_H
#define CALIBRATIONSTATE_H
#include "mainbasestate.h"


class Calibration_State : public MainBaseState {
public:
    void entry() override;
    void exit() override;

    TriggerProcessingState ss_t_str1_shortpressed() override;
    TriggerProcessingState ss_t_str2_shortpressed() override;


    void showState() override;
    void handleDefaultExit(const TriggerProcessingState &handled) override;

     TriggerProcessingState ss_t_rst1_pressed()override;
     TriggerProcessingState ss_t_rst2_pressed()override;
    TriggerProcessingState height_calibration()override;
    TriggerProcessingState height_band() override;
    TriggerProcessingState height_flat()override;
    TriggerProcessingState height_high()override;
    TriggerProcessingState height_hole()override;
    TriggerProcessingState ws_gone()override;
    TriggerProcessingState ss_ls_str1_continuous()override;
    TriggerProcessingState ss_ls_str1_interrupted()override;
    TriggerProcessingState ss_ls_srt1_continuous() override;
    TriggerProcessingState ss_ls_srt1_interrupted()override;
    TriggerProcessingState ss_ls_end1_continuous()override;
    TriggerProcessingState ss_ls_end1_interrupted() override;


};



#endif //CALIBRATIONSTATE_H
