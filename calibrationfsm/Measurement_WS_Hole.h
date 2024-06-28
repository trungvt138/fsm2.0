#ifndef MEASUREMENT_WS_HOLE_H
#define MEASUREMENT_WS_HOLE_H

#include "calibrationbasestate.h"
#include "Wait_FBA2_WS_Hole.h"


class Measurement_WS_Hole: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_band() override;
};


#endif // MEASUREMENT_WS_HOLE_H
