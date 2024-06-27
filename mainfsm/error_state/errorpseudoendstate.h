/*
 * errorpseudoendstate.h
 *
 *  Created on: 24.06.2024
 *      Author: maxge
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORPSEUDOENDSTATE_H_
#define SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORPSEUDOENDSTATE_H_


class ErrorPseudoEndState : public ErrorBaseState {
public:
	bool isPseudoEndState() override {return true;};

};


#endif /* SRC_FSMSIMPLE_MAINFSM_ERROR_STATE_ERRORPSEUDOENDSTATE_H_ */
