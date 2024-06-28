#include "Wait_Measurement_WS_Hole.h"

void Wait_Measurement_WS_Hole::entry() {
cout << "Wait_Measurement_WS_Hole"<< endl;    
cout << "WS Bohrung vorne auflegen" << endl;
action->ak_fbm1_right_off();
cout << "Reset drücken für WS Bohrung Messung" << endl;
}

void Wait_Measurement_WS_Hole::exit(){


}

TriggerProcessingState Wait_Measurement_WS_Hole::ss_t_rst1_pressed(){
    leavingState();

    new(this) Transport_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}

TriggerProcessingState Wait_Measurement_WS_Hole::ss_t_rst2_pressed(){
    leavingState();

    new(this) Transport_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}

