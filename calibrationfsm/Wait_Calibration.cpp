#include "Wait_Calibration.h"


void Wait_Calibration::entry(){
cout << "Entry: Wait_Calibration" << endl;    
cout << "Reset drücken für Bandhöhenmessung" << endl;
}

void Wait_Calibration::exit(){


}

TriggerProcessingState Wait_Calibration::ss_t_rst1_pressed(){
    leavingState();
    new(this) Measurement_ConveyorHeight_FBA1;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}

TriggerProcessingState Wait_Calibration::ss_t_rst2_pressed(){
    leavingState();
    new(this) Measurement_ConveyorHeight_FBA1;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}


