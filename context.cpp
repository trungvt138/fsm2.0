//
// Created by trung on 31/05/2024.
//



#include "context.h"

#include "estfsm/estpseudostartstate.h"
#include "rootfsm/pseudostartstate.h"

Context::Context(Actions *shared_action) : action(shared_action) {
    state = new PseudoStartState();
    state->initSubStateMachines();

    // all state pointer should be initialised now
    state->setData(&data);
    state->setAction(shared_action);

    // ready to go ...
    state->enterViaPseudoStart();  // Start state machine with initial transition

}

Context::~Context() {
    delete state;

}

// forward all events

void Context::ss_t_est1_pressed() {
    state->ss_t_est1_pressed();
}

void Context::ss_t_est1_unpressed() {
    state->ss_t_est1_unpressed();
}

void Context::ss_t_est2_pressed() {
    state->ss_t_est2_pressed();
}

void Context::ss_t_est2_unpressed() {
    state->ss_t_est2_unpressed();
}


void Context::showState() {
    cout << "--------------------------" << endl;
    state->showState();
}
void Context::ss_t_str1_pressed() {
	//std::cout << "in Context" << std::endl;

    state->ss_t_str1_pressed();
}

void Context::ss_ls_str1_continuous() {
    state->ss_ls_str1_continuous();
}

void Context::ss_ls_str1_interrupted() {
    state->ss_ls_str1_interrupted();
}

void Context::lightbarrier_height1_continuous() {
    state->lightbarrier_height1_continuous();
}

void Context::lightbarrier_height1_interrupted() {
    state->lightbarrier_height1_interrupted();
}

void Context::height_ok1_active() {
    state->height_ok1_active();
}

void Context::height_ok1_unactive() {
    state->height_ok1_unactive();
}

void Context::ss_ls_srt1_continuous() {
    state->ss_ls_srt1_continuous();
}

void Context::ss_ls_srt1_interrupted() {
    state->ss_ls_srt1_interrupted();
}

void Context::ss_ms1_erkannt() {
    state->ss_ms1_erkannt();
}

void Context::ss_ms1_fall() {
    state->ss_ms1_fall();
}

void Context::switch1_open() {
    state->switch1_open();
}

void Context::switch1_unopen() {
    state->switch1_unopen();
}

void Context::ss_ls_sli1_rise() {
    state->ss_ls_sli1_rise();
}

void Context::ss_ls_sli1_full() {
    state->ss_ls_sli1_full();
}

void Context::ss_ls_end1_continuous() {
    state->ss_ls_end1_continuous();
}

void Context::ss_ls_end1_interrupted() {
    state->ss_ls_end1_interrupted();
}


void Context::ss_t_str1_unpressed() {
    state->ss_t_str1_unpressed();
}

void Context::ss_t_stp1_unpressed() {
    state->ss_t_stp1_unpressed();
}

void Context::ss_t_stp1_pressed() {
    state->ss_t_stp1_pressed();
}

void Context::ss_t_rst1_pressed() {

	//std::cout << "RST Transition ausgelöst" << std::endl;
    state->ss_t_rst1_pressed();
}

void Context::ss_t_rst1_unpressed() {
    state->ss_t_rst1_unpressed();
}


void Context::ss_t_str1_longpressed() {
    state->ss_t_str1_longpressed();
}

void Context::ss_t_str1_shortpressed() {
    state->ss_t_str1_shortpressed();
}

void Context::ss_ls_str2_continuous() {
    state->ss_ls_str2_continuous();
}

void Context::ss_ls_str2_interrupted() {
    state->ss_ls_str2_interrupted();
}

void Context::lightbarrier_height2_continuous() {
    state->lightbarrier_height2_continuous();
}

void Context::lightbarrier_height2_interrupted() {
    state->lightbarrier_height2_interrupted();
}

void Context::height_ok2_active() {
    state->height_ok2_active();
}

void Context::height_ok2_unactive() {
    state->height_ok2_unactive();
}

void Context::ss_ls_srt2_continuous() {
    state->ss_ls_srt2_continuous();
}

void Context::ss_ls_srt2_interrupted() {
    state->ss_ls_srt2_interrupted();
}

void Context::ss_ms2_erkannt() {
    state->ss_ms2_erkannt();
}

void Context::ss_ms2_fall() {
    state->ss_ms2_fall();
}

void Context::switch2_open() {
    state->switch2_open();
}

void Context::switch2_unopen() {
    state->switch2_unopen();
}

void Context::ss_ls_sli2_rise() {
    state->ss_ls_sli2_rise();
}

void Context::ss_ls_sli2_full() {
    state->ss_ls_sli2_full();
}

void Context::ss_ls_end2_continuous() {
    state->ss_ls_end2_continuous();
}

void Context::ss_ls_end2_interrupted() {
    state->ss_ls_end2_interrupted();
}

void Context::ss_t_str2_unpressed() {
    state->ss_t_str2_unpressed();
}

void Context::ss_t_stp2_unpressed() {
    state->ss_t_stp2_unpressed();
}

void Context::ss_t_stp2_pressed() {
    state->ss_t_stp2_pressed();
}

void Context::ss_t_rst2_pressed() {
    state->ss_t_rst2_pressed();
}

void Context::ss_t_rst2_unpressed() {
    state->ss_t_rst2_unpressed();
}


void Context::ss_t_str2_longpressed() {
    state->ss_t_str2_longpressed();
}

void Context::ss_t_str2_shortpressed() {
    state->ss_t_str2_shortpressed();
}

void Context::ss_t_str2_pressed() {
    state->ss_t_str2_pressed();
}

void Context::ws_missing() {
    state->ws_missing();
}

void Context::both_slide_full() {
    state->both_slide_full();
}

void Context::ws_false_placement() {
    state->ws_false_placement();
}

void Context::connection_lost() {
    state->connection_lost();
}

void Context::connection_back() {
    state->connection_back();
}

void Context::ws_gone() {
    state->ws_gone();
}

void Context::height_high() {
    state->height_high();
}

void Context::height_flat() {
    state->height_flat();
}

void Context::height_calibration() {
    state->height_calibration();
}

void Context::height_hole() {
    state->height_hole();
}

void Context::height_band() {
    state->height_band();
}

void Context::slide1_free() {
    state->slide1_free();
}

void Context::slide2_free() {
    state->slide2_free();
}

void Context::right_order() {
    state->right_order();
}

void Context::unwanted_ws() {
    state->unwanted_ws();
}

// void Context::ss_ls_end2_interrupted() {
//     state->ss_ls_end2_interrupted();
// }


