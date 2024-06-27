/*
 * bothslidefullpseudostartstate.h
 *
 *  Created on: 25.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLPSEUDOSTARTSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLPSEUDOSTARTSTATE_H_


class BothSlideFullPseudoEndState : public BothSlideFullBaseState {
public:
	bool isPseudoEndState() override {return true;};

};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_BOTH_SLIDE_FULL_STATE_BOTHSLIDEFULLPSEUDOSTARTSTATE_H_ */
