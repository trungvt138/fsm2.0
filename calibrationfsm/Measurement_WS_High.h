#ifndef MEASUREMENT_WS_HIGH_H
#define MEASUREMENT_WS_HIGH_H

#include "calibrationbasestate.h"
#include "Wait_FBA2_WS_High.h"
class Measurement_WS_High: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_band() override;

};


#endif // MEASUREMENT_WS_HIGH_H
