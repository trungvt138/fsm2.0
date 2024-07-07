#ifndef WAIT_FBA2_WS_FLAT_H
#define WAIT_FBA2_WS_FLAT_H

#include "calibrationbasestate.h"
#include "Wait_Measurement_WS_Hole.h"


class Wait_FBA2_WS_Flat: public CalibrationBaseState
{
public:
    void entry() override;
    void exit() override;

	TriggerProcessingState ss_ls_end1_interrupted() override;
    TriggerProcessingState ss_ls_end2_interrupted() override;
};


#endif // WAIT_FBA2_WS_FLAT_H
