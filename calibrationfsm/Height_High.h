#ifndef HEIGHT_HIGH_H
#define HEIGHT_HIGH_H

#include "calibrationbasestate.h"
#include "Measurement_WS_Hole.h"


class Height_High: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_calibration() override;
};


#endif // HEIGHT_HIGH_H
