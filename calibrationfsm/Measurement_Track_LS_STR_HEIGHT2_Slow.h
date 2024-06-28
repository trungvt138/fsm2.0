#ifndef MEASUREMENT_TRACK_LS_STR_HEIGHT2_SLOW_H
#define MEASUREMENT_TRACK_LS_STR_HEIGHT2_SLOW_H

#include "calibrationbasestate.h"
#include "Measurement_Track_HEIGHT_LS_SRT1_Slow.h"

class Measurement_Track_LS_STR_HEIGHT2_Slow: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_band() override;
};


#endif // MEASUREMENT_TRACK_LS_STR_HEIGHT2_SLOW_H
