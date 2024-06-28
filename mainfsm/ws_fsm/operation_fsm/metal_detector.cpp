/*
 * metal_detector.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "metal_detector.h"
#include "Sorting.h"

#include "Sorting.h"

void Metal_Detector::entry() {
    //std::cout << "Metal_Detector Entry" << std::endl;
//    action->entered_Operation_State();
}

TriggerProcessingState Metal_Detector::ss_ls_srt1_interrupted(){
	if (this->data->checkFBA1()){
		action->ak_fbm1_slow_off();
//		updateWSData(nonmetal);
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ls_srt2_interrupted(){
	if (this->data->checkFBA1() == false){
		action->ak_fbm2_slow_off();
//		updateWSData(nonmetal);
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ms1_erkannt(){
	if (this->data->checkFBA1()){
		action->ak_fbm1_slow_off();
//		updateWSData(metal);
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ms2_erkannt(){
	if (this->data->checkFBA1() == false){
		action->ak_fbm2_slow_off();
//		updateWSData(metal);
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

void Metal_Detector::showState() {
    std::cout << "  Operation_State Fsm: Metal_Detector State" << std::endl;
}
