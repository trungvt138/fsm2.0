//
// Created by Trung Dam on 26.06.24.
//

#include "transferingws.h"

#include "transferingpseudoendstate.h"

void TransferingWS::entry() {
    cout << "\nTransferingFsm: TransferingWS State\n" << endl;;
    action->ak_fbm2_right_on();
}

TriggerProcessingState TransferingWS::ss_ls_str2_interrupted() {
    cout << "TransferingWS: ss_ls_str2_interrupted called" << endl;
    data->setFBA1(false);
    data->setFBA2(true);
    if (!data->checkFBA1()) {
        leavingState();
        new(this) TransferingPseudoEndState;
        data->wsCounterUpFBA2();
        data->wsCounterDownFBA1();
        enterByDefaultEntryPoint();
        return TriggerProcessingState::endstatereached;
    }
    return TriggerProcessingState::pending;
}

void TransferingWS::showState() {
    cout << "          TransferingFsm: TransferingWS State" << endl;;
}
