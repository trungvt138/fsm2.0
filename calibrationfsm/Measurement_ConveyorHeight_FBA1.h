#ifndef MEASUREMENT_CONVEYORHEIGHT_FBA1_H
#define MEASUREMENT_CONVEYORHEIGHT_FBA1_H


#include "calibrationbasestate.h"
#include "Wait_Measurement_WS_High.h"

class Measurement_ConveyorHeight_FBA1: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	//nach drei Sekunden
};


#endif // MEASUREMENT_CONVEYORHEIGHT_FBA1_H
