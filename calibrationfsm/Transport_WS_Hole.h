#ifndef TRANSPORT_WS_HOLE_H
#define TRANSPORT_WS_HOLE_H

#include "calibrationbasestate.h"
#include "Height_High.h"

class Transport_WS_Hole: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState height_high() override;
};


#endif // TRANSPORT_WS_HOLE_H
