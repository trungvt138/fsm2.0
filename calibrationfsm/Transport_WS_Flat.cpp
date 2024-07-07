#include "Transport_WS_Flat.h"

void Transport_WS_Flat::entry() {
cout << "Transport_WS_Flat" << endl;

if(data->checkFBA1()){
    action->ak_fbm1_right_on();
}else{
    action->ak_fbm2_right_on();
}

}

void Transport_WS_Flat::exit(){


}

TriggerProcessingState Transport_WS_Flat::height_calibration(){
    leavingState();

    new(this) Measurement_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
