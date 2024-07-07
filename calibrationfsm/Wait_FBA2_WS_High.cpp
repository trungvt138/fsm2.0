#include "Wait_FBA2_WS_High.h"
void Wait_FBA2_WS_High::entry() {
    cout << "Wait_FBA2_WS_High" <<endl;

    if(data->checkFBA1()){
	    action->ak_fbm1_slow_off();
    }else{
        action->ak_fbm2_slow_off();
    }
}

void Wait_FBA2_WS_High::exit(){


}



TriggerProcessingState Wait_FBA2_WS_High::ss_ls_end1_interrupted(){
    if(data->checkFBA1()){
    leavingState();

    new(this) Wait_Measurement_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

}

TriggerProcessingState Wait_FBA2_WS_High::ss_ls_end2_interrupted(){

    if(!data->checkFBA1()){
    leavingState();

    new(this) Wait_Measurement_WS_Flat;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }
}
