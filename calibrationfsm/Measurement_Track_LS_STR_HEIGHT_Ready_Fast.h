#ifndef MEASUREMENT_TRACK_LS_STR_HEIGHT_READY_FAST_H
#define MEASUREMENT_TRACK_LS_STR_HEIGHT_READY_FAST_H

#include "calibrationbasestate.h"
#include "Measurement_Track_LS_STR_HEIGHT1_Fast.h"

class Measurement_Track_LS_STR_HEIGHT_Ready_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_str1_continuous() override;
    TriggerProcessingState ss_ls_str2_continuous() override;
};


#endif // MEASUREMENT_TRACK_LS_STR_HEIGHT_READY_FAST_H
