#include "Wait_FBA2_WS_Flat.h"


void Wait_FBA2_WS_Flat::entry() {
    cout << "Entry: Wait_FBA2_WS_Flat"<< endl;
    action->ak_fbm1_slow_off();
}

void Wait_FBA2_WS_Flat::exit(){


}

TriggerProcessingState Wait_FBA2_WS_Flat::ss_ls_end1_interrupted(){
    leavingState();

    new(this) Wait_Measurement_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
