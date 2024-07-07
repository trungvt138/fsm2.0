//
// Created by trung on 31/05/2024.
//

#include "contextdata.h"
#include <iostream>
#include <algorithm>

void ContextData::clearErrorCounter() {
    errorCounter = 0;
}

void ContextData::incErrorCounter() {
    errorCounter++;
    show();
}


void ContextData::addWorkpiece(WorkPiece::StateType type){

    WorkPiece* workpiece = new WorkPiece();
    workpiece->setStateType(type);
    wsList.push_back(workpiece);

}
WorkPiece::StateType ContextData::getHighestIDWorkPieceState() {
    if (wsList.empty()) {
        return WorkPiece::StateType::noWsState;
    }

    WorkPiece* highestIDWorkPiece = wsList[0];
    for (WorkPiece* workpiece : wsList) {
        if (workpiece->getId() > highestIDWorkPiece->getId()) {
            highestIDWorkPiece = workpiece;
        }
    }

    return highestIDWorkPiece->getStateType();
}

WorkPiece::StateType ContextData::sortWsListDescendingById() {
    std::sort(wsList.begin(), wsList.end(), [](const WorkPiece* a, const WorkPiece* b) {
        return a->getId() > b->getId();
    });
}

// Funktion, die den StateType des WorkPieces mit der zweithöchsten ID zurückgibt
WorkPiece::StateType ContextData::getSecondHighestIDWorkPieceState() {
    if (wsList.size() < 2) return WorkPiece::StateType::noWsState;
    sortWsListDescendingById();
    return wsList[1]->getStateType();
}

// Funktion, die den StateType des WorkPieces mit der dritthöchsten ID zurückgibt
WorkPiece::StateType ContextData::getThirdHighestIDWorkPieceState() {
    if (wsList.size() < 3) return WorkPiece::StateType::noWsState;
    sortWsListDescendingById();
    return wsList[2]->getStateType();
}

// Funktion, die den StateType des WorkPieces mit der viert-höchsten ID zurückgibt
WorkPiece::StateType ContextData::getFourthHighestIDWorkPieceState() {
    if (wsList.size() < 4) return WorkPiece::StateType::noWsState;
    sortWsListDescendingById();
    return wsList[3]->getStateType();
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

bool ContextData::checkFBA1(){
    return FBA1;
}

bool ContextData::checkSlide1Full() {
    return slide1Full;
}

int ContextData::checkFBA2Counter(){
    return ws_FBA2;
}

bool ContextData::checkSlide2Full() {
    return slide2Full;
}

void ContextData::show() const {
    std::cout << "Error counter: " << errorCounter << std::endl;
}
void ContextData::startStrHeightTickFast() {
    //start_str_height_time_Fast = std::chrono::high_resolution_clock::now();
}

void ContextData::startHeightSrtTickFast() {
    //start_height_srt_time_Fast = std::chrono::high_resolution_clock::now();
}

void ContextData::startSrtEndTickFast() {
    //start_srt_end_time_Fast = std::chrono::high_resolution_clock::now();
}

// Methods to set the ticks
int ContextData::setStrHeightTickFast() {
    //auto end_time = std::chrono::high_resolution_clock::now();
    //ls_str_height_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_str_height_time_Fast).count();
    //return ls_str_height_tick_Fast;
}

int ContextData::setHeightSrtTickFast() {
   //auto end_time = std::chrono::high_resolution_clock::now();
    //ls_height_srt_tick_Fast = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_height_srt_time_Fast).count();
    //return ls_height_srt_tick_Fast;
}

int ContextData::setSrtEndTickFast() {
    //auto end_time = std::chrono::high_resolution_clock::now();
    //ls_srt_end_tick_Fast = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_srt_end_time_Fast).count();
    //return ls_srt_end_tick_Fast;
}

void ContextData::startStrHeightTickSlow() {
    //start_str_height_time_Slow = std::chrono::high_resolution_clock::now();
}

void ContextData::startHeightSrtTickSlow() {
    //start_height_srt_time_Slow = std::chrono::high_resolution_clock::now();
}

void ContextData::startSrtEndTickSlow() {
    //start_srt_end_time_Slow = std::chrono::high_resolution_clock::now();
}

void ContextData::setFBA2(){
    FBA2 = true;
    FBA1 = false;
}

void ContextData::setFBA1(){
    FBA1 = true;
    FBA2 = false;
}


// Methods to set the ticks
int ContextData::setStrHeightTickSlow() {
   // auto end_time = std::chrono::high_resolution_clock::now();
    //ls_str_height_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_str_height_time_Slow).count();
    //return ls_str_height_tick_Slow;
}

int ContextData::setHeightSrtTickSlow() {
    //auto end_time = std::chrono::high_resolution_clock::now();
    //ls_height_srt_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_height_srt_time_Slow).count();
    //return ls_height_srt_tick_Slow;
}

int ContextData::setSrtEndTickSlow() {
    //auto end_time = std::chrono::high_resolution_clock::now();
    //ls_srt_end_tick_Slow = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_srt_end_time_Slow).count();
    //return ls_srt_end_tick_Slow;
}


// tracker

void ContextData::addWSToTracker(WorkPiece *wp) {
    tracker.addWorkPiece(wp);
}

void ContextData::removeWSFromTracker() {
    tracker.removeWorkPiece();
}

bool ContextData::checkOrder() {
    return tracker.isInCorrectOrder();
}

void ContextData::displayOrder() {
    tracker.displayOrder();
}

bool ContextData::checkFBA2() {
    return FBA2;
}
