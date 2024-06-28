#include "Wait_Measurement_Track_Slow.h"

void Wait_Measurement_Track_Slow::entry() {
    cout << "Entry: Wait_Measurement_Track_Slow"<< endl;
action->ak_fbm1_right_off();
cout << "Streckenmessung Flaches Werkstück runterlegen" << endl;
cout << "Reset drücken zum Starten" << endl;
}

void Wait_Measurement_Track_Slow::exit(){


}

TriggerProcessingState Wait_Measurement_Track_Slow::ss_t_rst1_pressed(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT_Ready_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
TriggerProcessingState Wait_Measurement_Track_Slow::ss_t_rst2_pressed(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT_Ready_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}