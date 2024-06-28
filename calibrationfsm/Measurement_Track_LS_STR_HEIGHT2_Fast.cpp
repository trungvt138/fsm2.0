#include "Measurement_Track_LS_STR_HEIGHT2_Fast.h"

void Measurement_Track_LS_STR_HEIGHT2_Fast::entry() {
    cout <<"Entry: Measurement_Track_LS_STR_HEIGHT2_Fast"<<endl;
}

void Measurement_Track_LS_STR_HEIGHT2_Fast::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT2_Fast::height_band(){
    leavingState();

    new(this) Measurement_Track_HEIGHT_LS_SRT1_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
