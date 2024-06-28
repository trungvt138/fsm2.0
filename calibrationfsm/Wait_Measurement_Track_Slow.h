#ifndef WAIT_MEASUREMENT_TRACK_SLOW_H
#define WAIT_MEASUREMENT_TRACK_SLOW_H

#include "calibrationbasestate.h"
#include "Measurement_Track_LS_STR_HEIGHT_Ready_Slow.h"

class Wait_Measurement_Track_Slow: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
};


#endif // WAIT_MEASUREMENT_TRACK_SLOW_H
