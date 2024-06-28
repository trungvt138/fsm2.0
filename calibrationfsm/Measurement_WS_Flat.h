#ifndef MEASUREMENT_WS_FLAT_H
#define MEASUREMENT_WS_FLAT_H

#include "calibrationbasestate.h"
#include "Wait_FBA2_WS_Flat.h"


class Measurement_WS_Flat: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_band() override;
};


#endif // MEASUREMENT_WS_FLAT_H
