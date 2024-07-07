/*
 * Check_WS_Data.cpp
 *
 *  Created on: 26.06.2024
 *      Author: maxge
 */

#include "Check_WS_Data.h"
#include <thread>
#include <chrono>
#include <iostream>
#include "Sorting_FBA1.h"
#include "Sorting_FBA2.h"
#include "Wait_Slide_Free.h"

void Check_WS_Data::entry() {

	std::cout << "\nSortingFsm: Check_WS_Data\n" << std::endl;
}

//TODO: Make transitions to other states
TriggerProcessingState Check_WS_Data::unwanted_ws() {
	std::cout << "Check_WS_Data::unwanted_ws called" << std::endl;
	//TODO checkSlide()
	if(data->checkFBA1()) {
		if(data->checkSlide1Full()) {
			//TODO transfer WS Data
			leavingState();
			return TriggerProcessingState::ws_transfered_reached;
		}
		//if slide 1 not full
		else {
			leavingState();
			new(this)Sorting_FBA1;
			enterByDefaultEntryPoint();
			return TriggerProcessingState::consumed;
		}
	}
	//if FBA 2
	if(data->checkFBA2()) {
		if(data->checkSlide2Full()) {
			//TODO:  BOTH_SLIDE_FULL
			//TODO: Send event message both_slide_full to context
			leavingState();
			new(this) Wait_Slide_Free;
			enterByDefaultEntryPoint();
			return TriggerProcessingState::both_slide_full;
		}
		//if slide 2 not full
		else {
			leavingState();
			new(this)Sorting_FBA2;
			enterByDefaultEntryPoint();
			return TriggerProcessingState::consumed;
		}
	}

}


TriggerProcessingState Check_WS_Data::right_order() {
	std::cout << "Check_WS_Data::right_order called" << std::endl;
	//TODO: send transferWSData()

	return TriggerProcessingState::ws_transfered_reached;

}

void Check_WS_Data::showState() {
	std::cout << "          SortingFsm: Check_WS_Data" << std::endl;
}
