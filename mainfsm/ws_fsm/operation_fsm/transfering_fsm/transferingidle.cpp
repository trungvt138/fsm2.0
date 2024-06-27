//
// Created by Trung Dam on 26.06.24.
//

#include "transferingidle.h"

#include "checking_fba2.h"
#include "transferingws.h"
#include "waiting_remove.h"

TriggerProcessingState TransferingIdle::ss_ls_end1_interrupted() {
    cout << "TranfseringIdle: ss_ls_end1_interrupted called" << endl;
    if (data->checkFBA1()) {
        leavingState();
        if (data->checkFBA2Counter() == 0) {
            new(this) TransferingWS;
        }
        else {
            new(this) Checking_FBA2;
        }
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
    cout << "Transfering FSM: Idle State" << endl;
}

