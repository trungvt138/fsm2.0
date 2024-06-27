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

bool ContextData::checkFBA1(){
    return FBA1;
}

int ContextData::checkFBA2Counter() {
    return ws_FBA2;
}


void ContextData::show() const {
    std::cout << "Error counter: " << errorCounter << std::endl;
}


