#ifndef WAIT_MEASUREMENT_WS_HIGH_H
#define WAIT_MEASUREMENT_WS_HIGH_H

#include "calibrationbasestate.h"
#include "Transport_WS_High.h"

class Wait_Measurement_WS_High : public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
};


#endif // WAIT_MEASUREMENT_WS_HIGH_H
