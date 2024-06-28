#include "Wait_Measurement_WS_High.h"

void Wait_Measurement_WS_High::entry() {
cout << "Entry: Wait_Measurement_WS_High" << endl;
cout << "WS Hoch vorne auflegen" << endl;
cout << "Reset drücken für WS Hoch Messung" << endl;
}

void Wait_Measurement_WS_High::exit(){


}

TriggerProcessingState Wait_Measurement_WS_High::ss_t_rst1_pressed(){
    leavingState();

    new(this) Transport_WS_High;

    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}


TriggerProcessingState Wait_Measurement_WS_High::ss_t_rst2_pressed(){
    leavingState();

    new(this) Transport_WS_High;

    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}