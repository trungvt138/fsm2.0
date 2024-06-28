#include "Measurement_Track_HEIGHT_LS_SRT2_Slow.h"
void Measurement_Track_HEIGHT_LS_SRT2_Slow::entry() {
cout << "Entry: Measurement_Track_HEIGHT_LS_SRT2_Slow"<< endl;
}

void Measurement_Track_HEIGHT_LS_SRT2_Slow::exit(){


}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT2_Slow::ss_ls_str1_continuous(){
    leavingState();

    new(this) Measurement_Track_LS_SRT_END1_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
