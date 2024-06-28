#ifndef MEASUREMENT_TRACK_LS_STR_HEIGHT1_FAST_H
#define MEASUREMENT_TRACK_LS_STR_HEIGHT1_FAST_H
#include <chrono>
#include "calibrationbasestate.h"
#include "Measurement_Track_LS_STR_HEIGHT2_Fast.h"


class Measurement_Track_LS_STR_HEIGHT1_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_flat() override;
};


#endif // MEASUREMENT_TRACK_LS_STR_HEIGHT1_FAST_H
