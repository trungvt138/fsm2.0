#include "Wait_Measurement_Track_Fast.h"

void Wait_Measurement_Track_Fast::entry() {
cout << "Wait_Measurement_Track_Fast" << endl;  

if(data->checkFBA1()){
   action->ak_fbm1_right_off(); 
}else{
    action->ak_fbm2_right_off(); 
}

action->stop_calibration();
cout <<"Streckenmessung Flaches Werkstück rauflegen" << endl;
cout << "Wait_Measurement_Track_Fast" << endl;
}

void Wait_Measurement_Track_Fast::exit(){


}

TriggerProcessingState Wait_Measurement_Track_Fast::ss_t_rst1_pressed(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT_Ready_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
TriggerProcessingState Wait_Measurement_Track_Fast::ss_t_rst2_pressed(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT_Ready_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
