#include "Measurement_Track_LS_STR_HEIGHT2_Slow.h"

void Measurement_Track_LS_STR_HEIGHT2_Slow::entry() {
cout << "Measurement_Track_LS_STR_HEIGHT2_Slow" << endl;
}

void Measurement_Track_LS_STR_HEIGHT2_Slow::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT2_Slow::height_band(){
    leavingState();

    new(this) Measurement_Track_HEIGHT_LS_SRT1_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}