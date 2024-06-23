/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef ESTOP2_PRESSED_H
#define ESTOP2_PRESSED_H
#include "estbasestate.h"


class EStop2_pressed : public EstBaseState {
public:
    //void entry() override;
    TriggerProcessingState ss_t_est1_pressed() override;
    TriggerProcessingState ss_t_est2_unpressed() override;
    //TODO how to implement connection_lost[FBA1] and connection_lost[!FBA1]
    TriggerProcessingState connection_lost() override;
    void showState() override;
};


#endif /*ESTOP2_PRESSED_H*/
