//
// Created by Trung Dam on 07.07.24.
//

#include "Wait_Slide_Free.h"

#include "Sorting_FBA2.h"

void Wait_Slide_Free::entry() {
    std::cout << "\nSortingFsm: Wait_Slide_Free\n" << std::endl;
}

TriggerProcessingState Wait_Slide_Free::error_gone() {
    std::cout << "Wait_Slide_Free: error_gone" << std::endl;
    leavingState();
    new(this) Sorting_FBA2;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

void Wait_Slide_Free::showState() {
    std::cout << "          SortingFsm: Wait_Slide_Free" << std::endl;
}
