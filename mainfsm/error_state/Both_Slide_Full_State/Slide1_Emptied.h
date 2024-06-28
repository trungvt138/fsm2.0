/*
* Slide1_Emptied.h
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_SLIDE1_EMPTIED_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_SLIDE1_EMPTIED_H_

#include "bothslidefullbasestate.h"

class Slide1_Emptied : public BothSlideFullBaseState {
public:
    TriggerProcessingState slide2_free() override;

    void showState() override;
};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_SLIDE1_EMPTIED_H_ */
