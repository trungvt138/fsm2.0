//
// Created by Trung Dam on 29.06.24.
//

#include "checkslidebasestate.h"
#include <iostream>

#include "Slide_Free.h"
using namespace std;

void CheckSlideBaseState::enterViaPseudoStart() {
    cout << "CheckSlideBaseState Initial Transition taken" << endl;
    new(this) Slide_Free;
    enterByDefaultEntryPoint();
}
