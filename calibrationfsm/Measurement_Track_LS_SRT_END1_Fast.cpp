#include "Measurement_Track_LS_SRT_END1_Fast.h"

void Measurement_Track_LS_SRT_END1_Fast::entry() {
    cout << "Entry: Measurement_Track_LS_SRT_END1_Fast" << endl;
data->startSrtEndTickFast();
}

void Measurement_Track_LS_SRT_END1_Fast::exit(){
    data->startSrtEndTickFast();
}

TriggerProcessingState Measurement_Track_LS_SRT_END1_Fast::ss_ls_end1_interrupted(){
    leavingState();

    new(this) Measurement_Track_LS_SRT_END2_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}