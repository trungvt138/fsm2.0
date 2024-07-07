/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef EST1_AND_CL_H
#define EST1_AND_CL_H


#include "estbasestate.h"


class EST1_and_CL : public EstBaseState {
public:
    TriggerProcessingState ss_t_est1_unpressed() override;
    TriggerProcessingState connection_back() override;
    void showState() override;
};

#endif //EST1_AND_CL_H


