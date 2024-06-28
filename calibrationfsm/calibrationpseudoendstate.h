#include "calibrationbasestate.h"
#include <iostream>

class CalibrationPseudoEndState : public CalibrationBaseState {
public:
    bool isPseudoEndState() override {return true;};

    void showState() override {std::cout << "State: Calibration End State" << std::endl;}; // Just for illustration!
};