//
// Created by Trung Dam on 26.06.24.
//

#include "checking_fba2.h"

#include "transferingws.h"

void Checking_FBA2::entry() {
    cout << "\nTransferingFsm: Checking_FBA2 State\n" << endl;
    action->ak_fbm1_stop_on();
}

void Checking_FBA2::exit() {
    action->ak_fbm1_stop_off();
}

TriggerProcessingState Checking_FBA2::ws_sorted() {
    cout << "Checking_FBA2: ws_sorted called" << endl;
    leavingState();
    new(this) TransferingWS;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void Checking_FBA2::showState() {
    cout << "          TransferingFsm: Checking_FBA2 State" << endl;
}
