/*
 * EStop1_pressed.h
 *
 *  Created on: 21.06.2024
 *      Author: infwnj843
 */

#ifndef RESET_H_
#define RESET_H_
#include "estbasestate.h"

class Reset : public EstBaseState {
public:
    void enterByDefaultEntryPoint() override;

    TriggerProcessingState handleDefaultExit();

    TriggerProcessingState ss_t_est1_pressed() override;
    TriggerProcessingState ss_t_est2_pressed() override;
    TriggerProcessingState connection_lost() override;

    void ss_t_rst1_pressed();
    void ss_t_rst2_pressed();

    void showState() override;
};



#endif /* RESET_H_ */
