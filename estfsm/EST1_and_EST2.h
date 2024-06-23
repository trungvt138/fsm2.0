/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef EST1_AND_EST2_H
#define EST1_AND_EST2_H
#include "estbasestate.h"

class EST1_and_EST2 : public EstBaseState {
public:
    TriggerProcessingState ss_t_est1_unpressed() override;
    TriggerProcessingState ss_t_est2_unpressed() override;
    void showState() override;
};



#endif /* EST1_AND_EST2_H */
