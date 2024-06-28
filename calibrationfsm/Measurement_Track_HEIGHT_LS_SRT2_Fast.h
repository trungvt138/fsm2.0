#ifndef MEASUREMENT_TRACK_HEIGHT_LS_SRT2_FAST_H
#define MEASUREMENT_TRACK_HEIGHT_LS_SRT2_FAST_H


#include "calibrationbasestate.h"
#include "Measurement_Track_LS_SRT_END1_Fast.h"

class Measurement_Track_HEIGHT_LS_SRT2_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_srt1_continuous() override;
};


#endif // MEASUREMENT_TRACK_HEIGHT_LS_SRT2_FAST_H
