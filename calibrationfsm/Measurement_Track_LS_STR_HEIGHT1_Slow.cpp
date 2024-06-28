#include "Measurement_Track_LS_STR_HEIGHT1_Slow.h"

void Measurement_Track_LS_STR_HEIGHT1_Slow::entry() {
 cout << "Entry: Measurement_Track_LS_STR_HEIGHT1_Slow" << endl;   
data->startStrHeightTickSlow();
}

void Measurement_Track_LS_STR_HEIGHT1_Slow::exit(){
data->setStrHeightTickSlow();

}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT1_Slow::height_flat(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT2_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}