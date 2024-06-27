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
void Context::ss_t_str1_longpressed() {
    state->ss_t_str1_longpressed();
}

void Context::ss_t_str1_shortpressed() {
    state->ss_t_str1_shortpressed();
}

void Context::ss_t_stp1_pressed() {
    state->ss_t_stp1_pressed();
}

void Context::ss_t_str2_longpressed() {
    state->ss_t_str2_longpressed();
}

void Context::ss_t_str2_shortpressed() {
    state->ss_t_str2_shortpressed();
}

void Context::ss_t_stp2_pressed() {
    state->ss_t_stp2_pressed();
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

void Context::connection_back() {
    state->connection_back();
}

void Context::connection_lost() {
    state->connection_lost();
}

void Context::ss_t_rst1_pressed() {
    state->ss_t_rst1_pressed();
}

void Context::ss_t_rst2_pressed() {
    state->ss_t_rst2_pressed();
}

void Context::height_ok1_active() {
    state->height_ok1_active();
}

void Context::height_ok1_unactive() {
    state->height_ok1_unactive();
}

void Context::lightbarrier_height1_continuous() {
    state->lightbarrier_height1_continuous();
}

void Context::lightbarrier_height1_interrupted() {
    state->lightbarrier_height1_interrupted();
}

void Context::ss_ls_end1_continuous() {
    state->ss_ls_end1_continuous();
}

void Context::ss_ls_end1_interrupted() {
    state->ss_ls_end1_interrupted();
}

void Context::ss_ls_sli1_full() {
    state->ss_ls_sli1_full();
}

void Context::ss_ls_sli1_rise() {
    state->ss_ls_sli1_rise();
}

void Context::ss_ls_str1_continuous() {
    state->ss_ls_str1_continuous();
}

void Context::ss_ls_str1_interrupted() {
    state->ss_ls_str1_interrupted();
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

void Context::slide1_free() {
    state->slide1_free();
}

void Context::slide2_free() {
    state->slide2_free();
}


void Context::showState() {
    state->showState();
}

