//
// Created by trung on 07/06/2024.
//

#ifndef WSSTATE_H
#define WSSTATE_H

#include "mainbasestate.h"

class WS_State : public MainBaseState {
public:


    void entry() override;
    void exit() override;

    void enterByDefaultEntryPoint() override;

    void enterByDeepHistoryEntryPoint() override;

    void resetDeepHistory() override;

    void handleDefaultExit(const TriggerProcessingState &handled) override{};

    //FBA1
    TriggerProcessingState ss_ls_str1_continuous() override;
    TriggerProcessingState ss_ls_str1_interrupted() override;
    TriggerProcessingState lightbarrier_height1_continuous() override;
    TriggerProcessingState lightbarrier_height1_interrupted() override;
    TriggerProcessingState height_ok1_active() override;
    TriggerProcessingState height_ok1_unactive() override;
    TriggerProcessingState ss_ls_srt1_continuous() override;
    TriggerProcessingState ss_ls_srt1_interrupted() override;
    TriggerProcessingState ss_ms1_erkannt() override;
    TriggerProcessingState ss_ms1_fall() override;
    TriggerProcessingState ss_ls_sli1_rise() override;
    TriggerProcessingState ss_ls_sli1_full() override;
    TriggerProcessingState ss_ls_end1_continuous() override;
    TriggerProcessingState ss_ls_end1_interrupted() override;
    TriggerProcessingState ss_t_stp1_pressed() override;
    TriggerProcessingState ws_sorted_FBA1() override;

    //FBA2
    TriggerProcessingState ss_ls_str2_continuous() override;
    TriggerProcessingState ss_ls_str2_interrupted() override;
    TriggerProcessingState height_ok2_active() override;
    TriggerProcessingState height_ok2_unactive() override;
    TriggerProcessingState ss_ls_srt2_continuous() override;
    TriggerProcessingState ss_ls_srt2_interrupted() override;
    TriggerProcessingState ss_ms2_erkannt() override;
    TriggerProcessingState ss_ms2_fall() override;
    TriggerProcessingState ss_ls_sli2_rise() override;
    TriggerProcessingState ss_ls_sli2_full() override;
    TriggerProcessingState ss_ls_end2_continuous() override;
    TriggerProcessingState ss_ls_end2_interrupted() override;
    TriggerProcessingState ss_t_stp2_pressed() override;
    TriggerProcessingState ws_sorted_FBA2() override;
    TriggerProcessingState slide1_free() override;
    TriggerProcessingState slide2_free() override;
    TriggerProcessingState right_order() override;
    TriggerProcessingState unwanted_ws() override;

    TriggerProcessingState height_calibration() override;
    TriggerProcessingState height_high() override;
    TriggerProcessingState height_flat() override;
    TriggerProcessingState height_hole() override;
    TriggerProcessingState height_band() override;

    //TODO: These three methods must be renamed!!!
    TriggerProcessingState ws_missing() override;
    TriggerProcessingState ws_false_placement() override;
    TriggerProcessingState both_slide_full() override;

    void showState() override;
};


#endif //WSSTATE_H
