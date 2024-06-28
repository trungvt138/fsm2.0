#ifndef WAIT_MEASUREMENT_WS_HOLE_H
#define WAIT_MEASUREMENT_WS_HOLE_H

#include "calibrationbasestate.h"
#include "Transport_WS_Hole.h"


class Wait_Measurement_WS_Hole : public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
};


#endif // WAIT_MEASUREMENT_WS_HOLE_H
