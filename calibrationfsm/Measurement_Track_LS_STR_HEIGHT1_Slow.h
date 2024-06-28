#ifndef MEASUREMENT_TRACK_LS_STR_HEIGHT1_SLOW_H
#define MEASUREMENT_TRACK_LS_STR_HEIGHT1_SLOW_H

#include "calibrationbasestate.h"
#include "Measurement_Track_LS_STR_HEIGHT2_Slow.h"


class Measurement_Track_LS_STR_HEIGHT1_Slow: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_flat() override;
};


#endif // MEASUREMENT_TRACK_LS_STR_HEIGHT1_SLOW_H
