#include "Measurement_WS_Flat.h"

void Measurement_WS_Flat::entry() {
cout << "Entry: Measurement_WS_Flat " <<endl;
action->ak_fbm1_slow_on();
action->sample_flat_start();
}

void Measurement_WS_Flat::exit(){


}

TriggerProcessingState Measurement_WS_Flat::height_band(){
    leavingState();

    new(this) Wait_FBA2_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
