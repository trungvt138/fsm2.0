#include "Wait_FBA2_WS_Hole.h"

void Wait_FBA2_WS_Hole::entry() {
cout << "Entry: Wait_FBA2_WS_Hole" << endl;    
action->ak_fbm1_slow_off();
}

void Wait_FBA2_WS_Hole::exit(){


}

TriggerProcessingState Wait_FBA2_WS_Hole::ss_ls_end1_interrupted(){
    leavingState();

    new(this) Wait_Measurement_Track_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}

