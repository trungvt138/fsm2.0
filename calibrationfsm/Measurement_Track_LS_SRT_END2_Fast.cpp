#include "Measurement_Track_LS_SRT_END2_Fast.h"

void Measurement_Track_LS_SRT_END2_Fast::entry() {
cout << "Entry: Measurement_Track_LS_SRT_END2_Fast" << endl;
}

void Measurement_Track_LS_SRT_END2_Fast::exit(){


}

TriggerProcessingState Measurement_Track_LS_SRT_END2_Fast::ss_ls_end1_continuous(){
    leavingState();

    new(this) Wait_Measurement_Track_Slow;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
