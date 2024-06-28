#include "Wait_Measurement_WS_Flat.h"

void Wait_Measurement_WS_Flat::entry() {
    cout << "Entry: Wait_Measurement_WS_Flat " << endl;    
    cout << "WS Flat vorne auflegen" << endl;
    action->ak_fbm1_right_off();
    cout << "Reset drücken für WS Flat Messung" << endl;

}

void Wait_Measurement_WS_Flat::exit(){


}

TriggerProcessingState Wait_Measurement_WS_Flat::ss_t_rst1_pressed(){
    leavingState();

    new(this) Transport_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}

TriggerProcessingState Wait_Measurement_WS_Flat::ss_t_rst2_pressed(){
    leavingState();

    new(this) Transport_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}