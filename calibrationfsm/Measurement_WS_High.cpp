#include "Measurement_WS_High.h"

void Measurement_WS_High::entry() {
cout << "Entry: Measurement_WS_High" << endl;
action->ak_fbm1_slow_on();    
action->sample_high_start();
}

void Measurement_WS_High::exit(){


}

TriggerProcessingState Measurement_WS_High::height_band(){
    leavingState();

    new(this) Wait_FBA2_WS_High;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
