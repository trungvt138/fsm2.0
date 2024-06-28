#include "Measurement_WS_Hole.h"

void Measurement_WS_Hole::entry() {
    cout << "Measurement_WS_Hole" << endl;
action->sample_hole_start();
}

void Measurement_WS_Hole::exit(){


}

TriggerProcessingState Measurement_WS_Hole::height_band(){
    leavingState();

    new(this) Wait_FBA2_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
