#ifndef CALIBRATIONPSEUDOSTARTSTATE_H
#define CALIBRATIONPSEUDOSTARTSTATE_H

#include "calibrationbasestate.h"


class calibrationpseudostartstate : public CalibrationBaseState
{

public:
    bool isPseudoStartState() override {return true;};

    void showState() override {

    }
};


#endif // CALIBRATIONPSEUDOSTARTSTATE_H
