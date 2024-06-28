#ifndef WAIT_MEASUREMENT_TRACK_FAST_H
#define WAIT_MEASUREMENT_TRACK_FAST_H

#include "calibrationbasestate.h"
#include "Measurement_Track_LS_STR_HEIGHT_Ready_Fast.h"


class Wait_Measurement_Track_Fast: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
};


#endif // WAIT_MEASUREMENT_TRACK_FAST_H
