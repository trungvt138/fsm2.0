#ifndef WAIT_CALIBRATION_H
#define WAIT_CALIBRATION_H

#include "calibrationbasestate.h"
#include "Measurement_ConveyorHeight_FBA1.h"
class Wait_Calibration : public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
};


#endif // WAIT_CALIBRATION_H
