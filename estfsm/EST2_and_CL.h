/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef EST2_AND_CL_H_
#define EST2_AND_CL_H_
#include "estbasestate.h"

class EST2_and_CL : public EstBaseState {
public:
    TriggerProcessingState ss_t_est2_unpressed() override;
    TriggerProcessingState connection_back() override;
    void showState() override;
};



#endif /* EST2_AND_CL_H_ */
