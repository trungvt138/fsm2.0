/*
 * Operation_State2.h
 *
 *  Created on: 23 Jun 2024
 *      Author: WildanmSyufie
 */

#ifndef SRC_FSMSIMPLE_MAINFSM_OPERATION2_STATE_H_
#define SRC_FSMSIMPLE_MAINFSM_OPERATION2_STATE_H_

#include "wsbasestate.h"

class Operation_State2 : public WSBaseState2 {
public:


	bool isPseudoStartState() override {return false;};
	bool isPseudoEndState(){return false;};

	void enterByDefaultEntryPoint() override;
	void enterByDeepHistoryEntryPoint() override;
	void leavingState() override {exit();};
	void enterViaPseudoStart() override {};

	void resetDeepHistory() override;
	void entry() override;
	void exit() override;


	void handleDefaultExit(const TriggerProcessingState &handled) override;
	void showState() override;

	//estopp
	// TriggerProcessingState ss_t_est2_pressed() override{};
	// TriggerProcessingState ss_t_est2_unpressed() override{};
	//
	// TriggerProcessingState ss_t_est1_pressed() override{};
	// TriggerProcessingState ss_t_est1_unpressed() override{};
	//
	// TriggerProcessingState connection_back() override{};
	// TriggerProcessingState connection_lost() override{};

	//FBA1
	TriggerProcessingState ss_ls_str1_continuous() override;
	TriggerProcessingState ss_ls_str1_interrupted() override;
	TriggerProcessingState lightbarrier_height1_continuous() override;
	TriggerProcessingState lightbarrier_height1_interrupted() override;
	TriggerProcessingState height_ok1_active() override;
	TriggerProcessingState height_ok1_unactive() override;
	TriggerProcessingState ss_ls_srt1_continuous() override;
	TriggerProcessingState ss_ls_srt1_interrupted() override;
	TriggerProcessingState ss_ms1_erkannt() override;
	TriggerProcessingState ss_ms1_fall() override;
	TriggerProcessingState switch1_open() override;
	TriggerProcessingState switch1_unopen() override;

	TriggerProcessingState ss_ls_sli1_rise() override;
	TriggerProcessingState ss_ls_sli1_full() override;
	TriggerProcessingState ss_ls_end1_continuous() override;
	TriggerProcessingState ss_ls_end1_interrupted() override;
	TriggerProcessingState ss_t_str1_pressed() override;
	TriggerProcessingState ss_t_str1_unpressed() override;
	TriggerProcessingState ss_t_stp1_unpressed() override;
	//TriggerProcessingState ss_t_stp1_pressed() override;
	TriggerProcessingState ss_t_rst1_pressed() override;
	TriggerProcessingState ss_t_rst1_unpressed() override;
	//TriggerProcessingState ss_t_str1_longpressed() override;
	TriggerProcessingState ss_t_str1_shortpressed() override;
	TriggerProcessingState ws_sorted_FBA1() override;

	//FBA2
	TriggerProcessingState ss_ls_str2_continuous() override;
	TriggerProcessingState ss_ls_str2_interrupted() override;
	TriggerProcessingState lightbarrier_height2_continuous() override;
	TriggerProcessingState lightbarrier_height2_interrupted() override;
	TriggerProcessingState height_ok2_active() override;
	TriggerProcessingState height_ok2_unactive() override;
	TriggerProcessingState ss_ls_srt2_continuous() override;
	TriggerProcessingState ss_ls_srt2_interrupted() override;
	TriggerProcessingState ss_ms2_erkannt() override;
	TriggerProcessingState ss_ms2_fall() override;
	TriggerProcessingState switch2_open() override;
	TriggerProcessingState switch2_unopen() override;
	TriggerProcessingState ss_ls_sli2_rise() override;
	TriggerProcessingState ss_ls_sli2_full() override;
	TriggerProcessingState ss_ls_end2_continuous() override;
	TriggerProcessingState ss_ls_end2_interrupted() override;
	TriggerProcessingState ss_t_str2_pressed() override;
	TriggerProcessingState ss_t_str2_unpressed() override;
	TriggerProcessingState ss_t_stp2_unpressed() override;
	//TriggerProcessingState ss_t_stp2_pressed() override;
	TriggerProcessingState ss_t_rst2_pressed() override;
	TriggerProcessingState ss_t_rst2_unpressed() override;
	//TriggerProcessingState ss_t_str2_longpressed() override;
	TriggerProcessingState ss_t_str2_shortpressed() override;
	TriggerProcessingState ws_sorted_FBA2() override;
	TriggerProcessingState slide1_free() override;
	TriggerProcessingState slide2_free() override;
	TriggerProcessingState right_order() override;
	TriggerProcessingState unwanted_ws() override;

	TriggerProcessingState height_calibration() override;
	TriggerProcessingState height_high() override;
	TriggerProcessingState height_flat() override;
	TriggerProcessingState height_hole() override;
	TriggerProcessingState height_band() override;

	//TODO: These three methods must be renamed!!!
	//TriggerProcessingState ws_missing() override;
	//TriggerProcessingState ws_false_placement() override;
	//TriggerProcessingState both_slide_full() override;
};
#endif /* SRC_FSMSIMPLE_MAINFSM_Operation_State2_H_ */
