#ifndef TRANSPORT_WS_HIGH_H
#define TRANSPORT_WS_HIGH_H
#include "calibrationbasestate.h"
#include "Measurement_WS_High.h"
class Transport_WS_High : public CalibrationBaseState
{

public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_calibration() override;

};


#endif // TRANSPORT_WS_HIGH_H
