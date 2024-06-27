//
// Created by Trung Dam on 26.06.24.
//

#include "waiting_remove.h"

#include "transferingpseudoendstate.h"

void Waiting_Remove::entry() {
    action->ak_fbm2_stop_on();
}

void Waiting_Remove::exit() {
    action->ak_fbm2_stop_off();
}

TriggerProcessingState Waiting_Remove::ss_ls_end2_continuous() {
    cout << "Waiting_Remove: ss_ls_end2_continuous called" << endl;
    leavingState();
    new(this) TransferingPseudoEndState;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::endstatereached;
}

void Waiting_Remove::showState() {
    cout << "Tranfering Fsm: Waiting_Remove State";
}
