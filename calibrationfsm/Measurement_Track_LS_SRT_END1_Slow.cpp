#include "Measurement_Track_LS_SRT_END1_Slow.h"

void Measurement_Track_LS_SRT_END1_Slow::entry() {
cout << "Entry: Measurement_Track_LS_SRT_END1_Slow" << endl;

data->startSrtEndTickSlow();


}

void Measurement_Track_LS_SRT_END1_Slow::exit(){
data->setSrtEndTickSlow();

}

TriggerProcessingState Measurement_Track_LS_SRT_END1_Slow::ss_ls_end1_interrupted(){
    leavingState();

    new(this) CalibrationPseudoEndState;
    enterByDefaultEntryPoint();

    return TriggerProcessingState::endstatereached;
    
}