#include "Measurement_Track_HEIGHT_LS_SRT2_Slow.h"
void Measurement_Track_HEIGHT_LS_SRT2_Slow::entry() {
cout << "Entry: Measurement_Track_HEIGHT_LS_SRT2_Slow"<< endl;
}

void Measurement_Track_HEIGHT_LS_SRT2_Slow::exit(){


}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT2_Slow::ss_ls_srt1_continuous(){

    if(data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_SRT_END1_Slow;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT2_Slow::ss_ls_srt2_continuous(){

    if(!data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_SRT_END1_Slow;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}
