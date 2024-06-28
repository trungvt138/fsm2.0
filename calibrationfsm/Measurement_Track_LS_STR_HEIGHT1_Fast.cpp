#include "Measurement_Track_LS_STR_HEIGHT1_Fast.h"

void Measurement_Track_LS_STR_HEIGHT1_Fast::entry() {
        data->startStrHeightTickFast();
        cout << "Entry: Measurement_Track_LS_STR_HEIGHT_Ready_Fast" <<endl;
}

void Measurement_Track_LS_STR_HEIGHT1_Fast::exit(){
        data->setStrHeightTickFast();

}

TriggerProcessingState Measurement_Track_LS_STR_HEIGHT1_Fast::height_flat(){
    leavingState();

    new(this) Measurement_Track_LS_STR_HEIGHT2_Fast;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
}
