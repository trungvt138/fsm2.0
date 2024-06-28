#ifndef TRANSPORT_WS_FLAT_H
#define TRANSPORT_WS_FLAT_H

#include "calibrationbasestate.h"
#include "Measurement_WS_Flat.h"

class Transport_WS_Flat: public CalibrationBaseState
{
public:
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_calibration() override;

};


#endif // TRANSPORT_WS_FLAT_H
