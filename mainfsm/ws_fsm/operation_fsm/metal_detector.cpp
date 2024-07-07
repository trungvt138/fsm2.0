/*
 * metal_detector.cpp
 *
 *  Created on: 24.06.2024
 *      Author: infwur761
 */

#include "metal_detector.h"

#include "Sorting.h"
#include "../../ws_state.h"

void Metal_Detector::entry() {
    //std::cout << "Metal_Detector Entry" << std::endl;
//    action->entered_Operation_State();
	std::cout << "\nOperationFsm: Metal_Detector State\n" << std::endl;
}

TriggerProcessingState Metal_Detector::ss_ls_srt1_interrupted(){
	if (this->data->checkFBA1()){
		action->ak_fbm1_right_on();
		this->wp->setContainsMetal(false);
		if (this->wp->getIsFlat()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_Flat);
		}
		else if (this->wp->getHasHole()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High_Hole);
		}
		else if (this->wp->getIsTall()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High);
		}
		else {
			this->wp->setType(WorkPiece::WorkPieceType::Unknown);
		}
		this->data->addWSToTracker(this->wp);
		this->data->displayOrder();
		leavingState();
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ls_srt2_interrupted(){
	if (this->data->checkFBA2()){
		action->ak_fbm2_right_on();
		this->wp->setContainsMetal(false);
		if (this->wp->getIsFlat()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_Flat);
		}
		else if (this->wp->getHasHole()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High_Hole);
		}
		else if (this->wp->getIsTall()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High);
		}
		else {
			this->wp->setType(WorkPiece::WorkPieceType::Unknown);
		}
		this->data->addWSToTracker(this->wp);
		this->data->displayOrder();
		leavingState();
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ms1_erkannt(){
	if (this->data->checkFBA1()){
		action->ak_fbm1_right_on();
		this->wp->setContainsMetal(true);
		if (this->wp->getHasHole()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High_Hole_Metal);
		}
		else {
			this->wp->setType(WorkPiece::WorkPieceType::Unknown);

		}
		this->data->addWSToTracker(this->wp);
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

TriggerProcessingState Metal_Detector::ss_ms2_erkannt(){
	if (!this->data->checkFBA1()){
		action->ak_fbm2_right_on();
		this->wp->setContainsMetal(true);
		if (this->wp->getHasHole()){
			this->wp->setType(WorkPiece::WorkPieceType::WP_High_Hole_Metal);
			this->data->addWSToTracker(this->wp);
		}
		else {
			this->wp->setType(WorkPiece::WorkPieceType::Unknown);
			this->data->addWSToTracker(this->wp);
		}
		new(this) Sorting;
		enterByDefaultEntryPoint();
	}
	return TriggerProcessingState::consumed;
}

void Metal_Detector::showState() {
    std::cout << "\n        OperationFsm: Metal_Detector State\n" << std::endl;
}
