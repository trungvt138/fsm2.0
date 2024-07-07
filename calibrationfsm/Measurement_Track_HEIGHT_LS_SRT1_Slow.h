#ifndef MEASUREMENT_TRACK_HEIGHT_LS_SRT1_SLOW_H
#define MEASUREMENT_TRACK_HEIGHT_LS_SRT1_SLOW_H

#include "calibrationbasestate.h"
#include "Measurement_Track_HEIGHT_LS_SRT2_Slow.h"

class Measurement_Track_HEIGHT_LS_SRT1_Slow: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_srt1_interrupted() override;
    TriggerProcessingState ss_ls_srt2_interrupted() override;
};


#endif // MEASUREMENT_TRACK_HEIGHT_LS_SRT1_SLOW_H
