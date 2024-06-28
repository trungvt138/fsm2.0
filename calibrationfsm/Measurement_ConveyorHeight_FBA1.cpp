#include "Measurement_ConveyorHeight_FBA1.h"

void Measurement_ConveyorHeight_FBA1::entry() {
cout << "Entry: Measurement_ConveyorHeight_FBA1 " << endl;
cout << "Bandmessung läuft" << endl;
action->sample_band_start();

    //TODO: remove this before pushing to git
//usleep(3000000);
leavingState();
new (this) Wait_Measurement_WS_High;
enterByDefaultEntryPoint();
}

void Measurement_ConveyorHeight_FBA1::exit(){

    action->sample_band_stop();

}


//hier nach drei Sekunden raus

/* TriggerProcessingState Measurement_ConveyorHeight_FBA1::ss_t_rst1_pressed(){
    leavingState();

    new(this) Wait_Measurement_WS_High;

    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
    
} */
