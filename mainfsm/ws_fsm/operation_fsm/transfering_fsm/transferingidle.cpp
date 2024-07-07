//
// Created by Trung Dam on 26.06.24.
//

#include "transferingidle.h"

#include "checking_fba2.h"
#include "transferingpseudoendstate.h"
#include "transferingws.h"
#include "waiting_remove.h"
void TransferingIdle::entry() {
    cout << "\nTransferingFsm: Idle State\n" << endl;
}


TriggerProcessingState TransferingIdle::ss_ls_end1_interrupted() {
    cout << "TranfseringIdle: ss_ls_end1_interrupted called" << endl;
    if (data->checkFBA1()) {
        leavingState();
        if (data->checkFBA2Counter() == 0) {
            data->setFBA2();
            data->wsCounterUpFBA2();
            data->wsCounterDownFBA1();
            new(this) TransferingPseudoEndState;
            enterByDefaultEntryPoint();
            return TriggerProcessingState::endstatereached;
        }
        new(this) Checking_FBA2;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }
    return TriggerProcessingState::pending;
}

TriggerProcessingState TransferingIdle::ss_ls_end2_interrupted() {
    cout << "TransferingIdle: ss_ls_end2_interrupted called" << endl;
    if (!data->checkFBA1()) {
        leavingState();
        new(this) Waiting_Remove;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }
    return TriggerProcessingState::pending;
}


void TransferingIdle::showState() {
    cout << "          TransferingFsm: Idle State" << endl;
}

