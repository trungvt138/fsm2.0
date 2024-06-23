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
void Context::ss_t_str_longpressed() {
    state->ss_t_str_longpressed();
}

void Context::ss_t_str_shortpressed() {
    state->ss_t_str_shortpressed();
}

void Context::ss_t_stp_pressed() {
    state->ss_t_stp_pressed();
}

void Context::ws_gone() {
    state->ws_gone();
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

void Context::showState() {
    state->showState();
}


