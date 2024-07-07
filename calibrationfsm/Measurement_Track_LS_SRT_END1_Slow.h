#ifndef MEASUREMENT_TRACK_LS_SRT_END1_SLOW_H
#define MEASUREMENT_TRACK_LS_SRT_END1_SLOW_H

#include "calibrationbasestate.h"
#include "calibrationpseudoendstate.h"
class Measurement_Track_LS_SRT_END1_Slow: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_end1_interrupted() override;
    TriggerProcessingState ss_ls_end2_interrupted() override;
};


#endif // MEASUREMENT_TRACK_LS_SRT_END1_SLOW_H
