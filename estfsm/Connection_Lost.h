/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef CONNECTIONLOST_H
#define CONNECTIONLOST_H


#include "estbasestate.h"


class Connection_Lost : public EstBaseState {
public:
    //void entry() override;
    TriggerProcessingState ss_t_est1_pressed() override;
    TriggerProcessingState ss_t_est2_pressed() override;
    TriggerProcessingState connection_back() override;
    void showState() override;
};



#endif //CONNECTIONLOST_H
