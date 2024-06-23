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

void ContextData::show() const {
    std::cout << "Error counter: " << errorCounter << std::endl;
}


