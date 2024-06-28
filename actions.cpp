//
// Created by Trung Dam on 12.06.24.
//

#include "actions.h"
#include <iostream>
using namespace std;

Actions::~Actions(){
    cout << "  Actions destructor called" << endl;
}
void Actions::ak_l_grn1_off(){
    cout << "  Action ak_l_grn1_off called" << endl;
}
void Actions::ak_l_grn1_on(){
    cout << "  Action ak_l_grn1_on called" << endl;
}
void Actions::ak_l_grn2_off(){
    cout << "  Action ak_l_grn2_off called" << endl;
}
void Actions::ak_l_grn2_on(){
    cout << "  Action ak_l_grn2_on called" << endl;
}
void Actions::ak_l_grn1_blink_fast(){
    cout << "  Action ak_l_grn1_blink_fast called" << endl;
}
void Actions::ak_l_grn2_blink_fast(){
    cout << "  Action ak_l_grn2_blink_fast called" << endl;
}
void Actions::ak_l_rot1_off(){
    cout << "  Action ak_l_rot1_off called" << endl;
}
void Actions::ak_l_rot2_off(){
    cout << "  Action ak_l_rot2_off called" << endl;
}
void Actions::ak_l_rot1_on(){
    cout << "  Action ak_l_rot1_on called" << endl;
}
void Actions::ak_l_rot2_on(){
    cout << "  Action ak_l_rot2_on called" << endl;
}
void Actions::ak_fbm1_right_off(){
    cout << "  Action ak_fbm1_right_off called" << endl;
}
void Actions::ak_fbm2_right_off(){
    cout << "  Action ak_fbm2_right_off called" << endl;
}
void Actions::ak_l_glb1_on(){
    cout << "  Action ak_l_glb1_on called" << endl;
}
void Actions::ak_l_glb2_on(){
    cout << "  Action ak_l_glb2_on called" << endl;
}
void Actions::ak_l_glb1_off(){
    cout << "  Action ak_l_glb1_off called" << endl;
}
void Actions::ak_l_glb2_off(){
    cout << "  Action ak_l_glb2_off called" << endl;
}
void Actions::ak_awf_wch1_on(){
    cout << "  Action ak_awf_wch1_on called" << endl;
}
void Actions::ak_awf_wch2_on(){
    cout << "  Action ak_awf_wch2_on called" << endl;
}
void Actions::ak_awf_wch1_off(){
    cout << "  Action ak_awf_wch1_off called" << endl;
}
void Actions::ak_awf_wch2_off(){
    cout << "  Action ak_awf_wch2_off called" << endl;
}
void Actions::ak_fbm1_left_on(){
    cout << "  Action ak_fbm1_left_on called" << endl;
}
void Actions::ak_fbm1_slow_on(){
    cout << "  Action ak_fbm1_slow_on called" << endl;
}
void Actions::ak_fbm1_stop_on(){
    cout << "  Action ak_fbm1_stop_on called" << endl;
}
void Actions::ak_fbm2_left_on(){
    cout << "  Action ak_fbm2_left_on called" << endl;
}

void Actions::ak_fbm2_slow_on(){
    cout << "  Action ak_fbm2_slow_on called" << endl;
}
void Actions::ak_fbm2_stop_on(){
    cout << "  Action ak_fbm2_stop_on called" << endl;
}
void Actions::ak_fbm1_left_off(){
    cout << "  Action ak_fbm1_left_off called" << endl;
}
void Actions::ak_fbm1_slow_off(){
    cout << "  Action ak_fbm1_slow_off called" << endl;
}
void Actions::ak_fbm1_stop_off(){
    cout << "  Action ak_fbm1_stop_off called" << endl;
}
void Actions::ak_fbm2_left_off(){
    cout << "  Action ak_fbm2_left_off called" << endl;
}
void Actions::ak_fbm2_right_on(){
    cout << "  Action ak_fbm2_right_on called" << endl;
}
void Actions::ak_fbm2_slow_off(){
    cout << "  Action ak_fbm2_slow_off called" << endl;
}
void Actions::ak_fbm2_stop_off(){
    cout << "  Action ak_fbm2_stop_off called" << endl;
}
void Actions::ak_l_glb1_blink_fast(){
    cout << "  Action ak_l_glb1_blink_fast called" << endl;
}
void Actions::ak_l_glb2_blink_fast(){
    cout << "  Action ak_l_glb2_blink_fast called" << endl;
}
void Actions::ak_l_rot1_blink_fast(){
    cout << "  Action ak_l_rot1_blink_fast called" << endl;
}
void Actions::ak_l_rot1_blink_slow(){
    cout << "  Action ak_l_rot1_blink_slow called" << endl;
}
void Actions::ak_l_rot2_blink_fast(){
    cout << "  Action ak_l_rot2_blink_fast called" << endl;
}
void Actions::ak_l_rot2_blink_slow(){
    cout << "  Action ak_l_rot2_blink_slow called" << endl;
}
void Actions::ak_fbm1_right_on() {
    cout << "  Action ak_fbm1_right_on called" << endl;
}

void Actions::start_calibration() {
    cout << "  Action start_calibration called" << endl;
}

void Actions::stop_calibration() {
    cout << "  Action stop_calibration called" << endl;
}

void Actions::sample_band_start() {
    cout << "  Action sample_band_start called" << endl;
}

void Actions::sample_band_stop() {
    cout << "  Action sample_band_stop called" << endl;
}

void Actions::sample_high_start() {
    cout << "  Action sample_high_start called" << endl;
}

void Actions::sample_hole_start() {
    cout << "  Action sample_hole_start called" << endl;
}

void Actions::sample_flat_start() {
    cout << "  Action sample_flat_start called" << endl;
}
