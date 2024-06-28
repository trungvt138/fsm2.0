//
// Created by trung on 31/05/2024.
//

#include "contextdata.h"
#include <iostream>

void ContextData::clearErrorCounter() {
    errorCounter = 0;
}

void ContextData::incErrorCounter() {
    errorCounter++;
    show();
}

void ContextData::setID(int ws_count){
	ws_ID = ws_count;
}

void ContextData::wsCounterUp(){
	ws_count++;
}

void ContextData::wsCounterUpFBA1(){
	ws_FBA1++;
}

void ContextData::wsCounterUpFBA2(){
	ws_FBA2++;
}

void ContextData::wsCounterDownFBA1(){
	ws_FBA1--;
}

void ContextData::wsCounterDownFBA2(){
	ws_FBA2--;
}

int ContextData::checkFBA1Counter(){
	return ws_count;
}

// type ContextData::updateWSData(Type type){
//	return type;
//
//}
int ContextData::checkFBA2Counter() {
    return ws_FBA2;
}


bool ContextData::checkFBA1(){
	return FBA1;
}

bool ContextData::checkSlide1Full() {
	return slide1Full;
}

bool ContextData::checkSlide2Full() {
	return slide2Full;
}

void ContextData::show() const {
    std::cout << "Error counter: " << errorCounter << std::endl;
}
void ContextData::startStrHeightTickFast() {
    start_str_height_time_Fast = std::chrono::high_resolution_clock::now();
}

void ContextData::startHeightSrtTickFast() {
    start_height_srt_time_Fast = std::chrono::high_resolution_clock::now();
}

void ContextData::startSrtEndTickFast() {
    start_srt_end_time_Fast = std::chrono::high_resolution_clock::now();
}

// Methods to set the ticks
int ContextData::setStrHeightTickFast() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_str_height_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_str_height_time_Fast).count();
    return ls_str_height_tick_Fast;
}

int ContextData::setHeightSrtTickFast() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_height_srt_tick_Fast = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_height_srt_time_Fast).count();
    return ls_height_srt_tick_Fast;
}

int ContextData::setSrtEndTickFast() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_srt_end_tick_Fast = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_srt_end_time_Fast).count();
    return ls_srt_end_tick_Fast;
}

void ContextData::startStrHeightTickSlow() {
    start_str_height_time_Slow = std::chrono::high_resolution_clock::now();
}

void ContextData::startHeightSrtTickSlow() {
    start_height_srt_time_Slow = std::chrono::high_resolution_clock::now();
}

void ContextData::startSrtEndTickSlow() {
    start_srt_end_time_Slow = std::chrono::high_resolution_clock::now();
}

// Methods to set the ticks
int ContextData::setStrHeightTickSlow() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_str_height_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_str_height_time_Slow).count();
    return ls_str_height_tick_Slow;
}

int ContextData::setHeightSrtTickSlow() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_height_srt_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_height_srt_time_Slow).count();
    return ls_height_srt_tick_Slow;
}

int ContextData::setSrtEndTickSlow() {
    auto end_time = std::chrono::high_resolution_clock::now();
    ls_srt_end_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_srt_end_time_Slow).count();
    return ls_srt_end_tick_Slow;
}

