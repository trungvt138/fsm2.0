#include "Wait_FBA2_WS_Flat.h"


void Wait_FBA2_WS_Flat::entry() {
    cout << "Entry: Wait_FBA2_WS_Flat"<< endl;

    if(data->checkFBA1()){
        action->ak_fbm1_slow_off();
    }else{
        action->ak_fbm2_slow_off();
    }
    
}

void Wait_FBA2_WS_Flat::exit(){


}

TriggerProcessingState Wait_FBA2_WS_Flat::ss_ls_end1_interrupted(){

    if(data->checkFBA1()){
    leavingState();

    new(this) Wait_Measurement_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }
    
}

TriggerProcessingState Wait_FBA2_WS_Flat::ss_ls_end2_interrupted(){

    if(!data->checkFBA1()){
    leavingState();

    new(this) Wait_Measurement_WS_Hole;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }
    
}
