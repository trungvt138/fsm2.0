#ifndef MEASUREMENT_TRACK_LS_SRT_END2_FAST_H
#define MEASUREMENT_TRACK_LS_SRT_END2_FAST_H

#include "calibrationbasestate.h"
#include "Wait_Measurement_Track_Slow.h"


class Measurement_Track_LS_SRT_END2_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_end1_continuous() override;
};


#endif // MEASUREMENT_TRACK_LS_SRT_END2_FAST_H
