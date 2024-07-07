#include "Measurement_Track_LS_SRT_END1_Slow.h"

void Measurement_Track_LS_SRT_END1_Slow::entry() {
cout << "Entry: Measurement_Track_LS_SRT_END1_Slow" << endl;

data->startSrtEndTickSlow();


}

void Measurement_Track_LS_SRT_END1_Slow::exit(){
data->setSrtEndTickSlow();

if(data->checkFBA1()){
    action->ak_fbm1_slow_off();
}else{
    action->ak_fbm2_slow_off();
}

}

TriggerProcessingState Measurement_Track_LS_SRT_END1_Slow::ss_ls_end1_interrupted(){

    if(data->checkFBA1()){
        leavingState();

        new(this) CalibrationPseudoEndState;
        enterByDefaultEntryPoint();

        return TriggerProcessingState::endstatereached;
    }else{
        return TriggerProcessingState::pending;
    }

    
}

TriggerProcessingState Measurement_Track_LS_SRT_END1_Slow::ss_ls_end2_interrupted(){

    if(!data->checkFBA1()){
        leavingState();

        new(this) CalibrationPseudoEndState;
        enterByDefaultEntryPoint();

        return TriggerProcessingState::endstatereached;
    }else{
        return TriggerProcessingState::pending;
    }

    
}
