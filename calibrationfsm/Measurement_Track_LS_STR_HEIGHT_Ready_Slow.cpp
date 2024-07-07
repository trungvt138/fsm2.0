#include "Measurement_Track_LS_STR_HEIGHT_Ready_Slow.h"

void Measurement_Track_LS_STR_HEIGHT_Ready_Slow::entry() {
cout << "Entry: Measurement_Track_LS_STR_HEIGHT_Ready_Slow"  << endl; 

if(data->checkFBA1()){
    action->ak_fbm1_right_on();
    action->ak_fbm1_slow_on();
}else{
    action->ak_fbm2_right_on();
    action->ak_fbm2_slow_on();
}

cout<< "LS_STR_HEIGHT Streckenmessung" << endl;
cout<< "Reset drücken zum Starten" << endl;
}

void Measurement_Track_LS_STR_HEIGHT_Ready_Slow::exit(){


}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Slow::ss_ls_str1_continuous(){

    if(data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_STR_HEIGHT1_Slow;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT_Ready_Slow::ss_ls_str2_continuous(){

    if(!data->checkFBA1()){
        leavingState();

        new(this) Measurement_Track_LS_STR_HEIGHT1_Slow;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }else{
        return TriggerProcessingState::pending;
    }

    
}
