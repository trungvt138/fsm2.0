//
// Created by Trung Dam on 07.07.24.
//

#ifndef WAIT_SLIDE_FREE_H
#define WAIT_SLIDE_FREE_H
#include "sortingbasestate.h"


class Wait_Slide_Free : public SortingBaseState {
public:
    void entry() override;
    TriggerProcessingState error_gone() override;
    void showState() override;
};



#endif //WAIT_SLIDE_FREE_H
