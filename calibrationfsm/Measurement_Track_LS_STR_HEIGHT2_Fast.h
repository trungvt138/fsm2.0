#ifndef MEASUREMENT_TRACK_LS_STR_HEIGHT2_FAST_H
#define MEASUREMENT_TRACK_LS_STR_HEIGHT2_FAST_H

#include "calibrationbasestate.h"
#include "Measurement_Track_HEIGHT_LS_SRT1_Fast.h"

class Measurement_Track_LS_STR_HEIGHT2_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_band() override;
};


#endif // MEASUREMENT_TRACK_LS_STR_HEIGHT2_FAST_H
