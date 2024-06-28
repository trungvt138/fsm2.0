#ifndef WAIT_FBA2_WS_HOLE_H
#define WAIT_FBA2_WS_HOLE_H

#include "calibrationbasestate.h"
#include "Wait_Measurement_Track_Fast.h"


class Wait_FBA2_WS_Hole: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_end1_interrupted() override;
};


#endif // WAIT_FBA2_WS_HOLE_H
