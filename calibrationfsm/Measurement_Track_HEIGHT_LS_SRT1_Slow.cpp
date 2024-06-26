#include "Measurement_Track_HEIGHT_LS_SRT1_Slow.h"

void Measurement_Track_HEIGHT_LS_SRT1_Slow::entry() {
    cout << "Measurement_Track_HEIGHT_LS_SRT1_Slow"<< endl;
data->startHeightSrtTickSlow();
}

void Measurement_Track_HEIGHT_LS_SRT1_Slow::exit(){

data->setHeightSrtTickSlow();

}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT1_Slow::ss_ls_srt1_interrupted(){
    leavingState();

    new(this) Measurement_Track_HEIGHT_LS_SRT2_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}