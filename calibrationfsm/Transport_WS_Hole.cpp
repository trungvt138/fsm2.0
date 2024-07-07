#include "Transport_WS_Hole.h"

void Transport_WS_Hole::entry() {
    cout << "Entry: Transport_WS_Hole" << endl;

    if(data->checkFBA1()){
action->ak_fbm1_right_on();
    }else{
        action->ak_fbm2_right_on();
    }
    
}

void Transport_WS_Hole::exit(){


}

TriggerProcessingState Transport_WS_Hole::height_high(){
    leavingState();

    new(this) Height_High;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
