//
// Created by Trung Dam on 12.06.24.
//

#ifndef ACTIONS_H
#define ACTIONS_H



class Actions {
public:
    virtual ~Actions();
    virtual void green1_Blink_Fast();
    virtual void green2_Blink_Fast();
    virtual void green1_Off();
    virtual void green2_Off();
    virtual void green1_On();
    virtual void green2_On();
    virtual void red1_Off();
    virtual void red2_Off();
    virtual void red1_On();
    virtual void red2_On();
    virtual void motor1_Off();
    virtual void motor2_Off();

    // for didactic / testing purpose only
    virtual void enteredMainFSM();
    virtual void enteredEStoppFSM();
    virtual void entered_Error_State();
    virtual void entered_Calibration_State();
    virtual void entered_WS_State();
    virtual void entered_Idle();
};



#endif //ACTIONS_H
