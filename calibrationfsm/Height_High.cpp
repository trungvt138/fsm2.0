#include "Height_High.h"

void Height_High::entry() {
cout << "Entry: Height_High " << endl;

action->ak_fbm1_slow_on();
}

void Height_High::exit(){


}

TriggerProcessingState Height_High::height_calibration(){

    leavingState();

    new(this) Measurement_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
