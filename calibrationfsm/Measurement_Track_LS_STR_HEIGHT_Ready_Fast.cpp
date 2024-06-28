#include "Measurement_Track_LS_STR_HEIGHT_Ready_Fast.h"

void Measurement_Track_LS_STR_HEIGHT_Ready_Fast::entry() {
action->ak_fbm1_right_on();
cout << "Entry: Measurement_Track_LS_STR_HEIGHT_Ready_Fast" << endl;
}

void Measurement_Track_LS_STR_HEIGHT_Ready_Fast::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Fast::ss_ls_str1_continuous(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT1_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
