//
// Created by trung on 07/06/2024.
//

#ifndef OPSORT_H
#define OPSORT_H
#include "mainbasestate.h"


class Error_State : public MainBaseState {
public:
    void entry() override;
    void exit() override;
    void handleDefaultExit(const TriggerProcessingState &handled) override;

    //Overridden, so no entry() is called. There is no default entry point in Error_State
    void enterByDefaultEntryPoint() override;
    void enterByWsGonePoint() override;
    void enterByBothSlideFullPoint() override;
    void enterByFalsePlacementPoint() override;

    TriggerProcessingState ss_t_rst1_pressed() override;
    TriggerProcessingState ss_t_rst2_pressed() override;
    TriggerProcessingState slide1_free() override;
    TriggerProcessingState slide2_free() override;
    void showState() override;
};

#endif //OPSORT_H
