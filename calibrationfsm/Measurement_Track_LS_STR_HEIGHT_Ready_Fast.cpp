#include "Measurement_Track_LS_STR_HEIGHT_Ready_Fast.h"

void Measurement_Track_LS_STR_HEIGHT_Ready_Fast::entry() {

    if(data->checkFBA1()){
        action->ak_fbm1_right_on(); 
    }else{
        action->ak_fbm2_right_on(); 
    }
    
    cout << "Entry: Measurement_Track_LS_STR_HEIGHT_Ready_Fast" << endl;
    }

void Measurement_Track_LS_STR_HEIGHT_Ready_Fast::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Fast::ss_ls_str1_continuous(){

    if(data->checkFBA1()){
       leavingState();
        new(this) Measurement_Track_LS_STR_HEIGHT1_Fast;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed; 
    }else{
        return TriggerProcessingState::pending; 
    }
    
}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Fast::ss_ls_str2_continuous(){

    if(!data->checkFBA1()){
       leavingState();
        new(this) Measurement_Track_LS_STR_HEIGHT1_Fast;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed; 
    }else{
        return TriggerProcessingState::pending; 
    }
    
}
