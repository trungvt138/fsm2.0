/*
 * calibrationbasestate.cpp
 *
 *  Created on: 22.06.2024
 *      Author: sebas
 */

#include "calibrationbasestate.h"
#include "Wait_Calibration.h"
#include <iostream>

void CalibrationBaseState::enterViaPseudoStart() {
    std::cout << "Calibration FSM Trasition taken" << std::endl;
    new(this) Wait_Calibration;
    enterByDefaultEntryPoint();
}


void CalibrationBaseState::setAction(Actions *action){
    this->action = action;
}


void CalibrationBaseState::setData(ContextData *data){
    this->data = data;


    
}