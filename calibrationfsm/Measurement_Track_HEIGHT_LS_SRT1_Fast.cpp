#include "Measurement_Track_HEIGHT_LS_SRT1_Fast.h"

void Measurement_Track_HEIGHT_LS_SRT1_Fast::entry() {
data->startHeightSrtTickFast();
cout <<"Entry: Measurement_Track_HEIGHT_LS_SRT1_Fast"<< endl;
}

void Measurement_Track_HEIGHT_LS_SRT1_Fast::exit(){
data->setHeightSrtTickFast();


}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT1_Fast::ss_ls_srt1_interrupted(){
    leavingState();

    new(this) Measurement_Track_HEIGHT_LS_SRT2_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
