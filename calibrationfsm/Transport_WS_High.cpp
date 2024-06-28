#include "Transport_WS_High.h"


void Transport_WS_High::entry() {
std::cout << "Entry: Transport_WS_High"<< endl;
action->ak_fbm1_right_on();
action->start_calibration();
}

void Transport_WS_High::exit(){


}

TriggerProcessingState Transport_WS_High::height_calibration(){
    leavingState();

    new(this) Measurement_WS_High;
;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
