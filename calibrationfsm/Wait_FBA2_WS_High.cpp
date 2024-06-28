#include "Wait_FBA2_WS_High.h"
void Wait_FBA2_WS_High::entry() {
    cout << "Wait_FBA2_WS_High" <<endl;
	action->ak_fbm1_slow_off();
}

void Wait_FBA2_WS_High::exit(){


}

TriggerProcessingState Wait_FBA2_WS_High::ws_gone(){
    leavingState();

    new(this) Wait_Measurement_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}


TriggerProcessingState Wait_FBA2_WS_High::ss_ls_end1_interrupted(){
    leavingState();

    new(this) Wait_Measurement_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;

}
