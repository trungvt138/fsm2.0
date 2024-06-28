#include "Measurement_Track_LS_STR_HEIGHT_Ready_Slow.h"

void Measurement_Track_LS_STR_HEIGHT_Ready_Slow::entry() {
cout << "Entry: Measurement_Track_LS_STR_HEIGHT_Ready_Slow"  << endl; 
action->ak_fbm1_right_on();
action->ak_fbm1_slow_on();
cout<< "LS_STR_HEIGHT Streckenmessung" << endl;
cout<< "Reset drücken zum Starten" << endl;
}

void Measurement_Track_LS_STR_HEIGHT_Ready_Slow::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Slow::ss_ls_str1_continuous(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT1_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
