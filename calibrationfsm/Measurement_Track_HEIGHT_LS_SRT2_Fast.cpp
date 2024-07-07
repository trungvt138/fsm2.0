#include "Measurement_Track_HEIGHT_LS_SRT2_Fast.h"

void Measurement_Track_HEIGHT_LS_SRT2_Fast::entry() {
	cout <<"Entry: Measurement_Track_HEIGHT_LS_SRT2_Fast"<< endl;
}

void Measurement_Track_HEIGHT_LS_SRT2_Fast::exit(){


}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT2_Fast::ss_ls_srt1_continuous(){

    if(data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_SRT_END1_Fast;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}

TriggerProcessingState Measurement_Track_HEIGHT_LS_SRT2_Fast::ss_ls_srt2_continuous(){

    if(!data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_SRT_END1_Fast;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}
