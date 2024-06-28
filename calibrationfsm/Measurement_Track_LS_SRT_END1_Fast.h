#ifndef MEASUREMENT_TRACK_LS_SRT_END1_FAST_H
#define MEASUREMENT_TRACK_LS_SRT_END1_FAST_H

#include "calibrationbasestate.h"
#include "Measurement_Track_LS_SRT_END2_Fast.h"


class Measurement_Track_LS_SRT_END1_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_end1_interrupted() override;
};


#endif // MEASUREMENT_TRACK_LS_SRT_END1_FAST_H
