//
// Created by Trung Dam on 12.06.24.
//

#include "actions.h"
#include <iostream>
using namespace std;

Actions::~Actions(){
    cout << "  Actions destructor called" << endl;
}
void Actions::green1_Off(){
    cout << "  Action green1_Off called" << endl;
}
void Actions::green1_On(){
    cout << "  Action green1_On called" << endl;
}
void Actions::green2_Off(){
    cout << "  Action green2_Off called" << endl;
}
void Actions::green2_On(){
    cout << "  Action green2_On called" << endl;
}
void Actions::green1_Blink_Fast(){
    cout << "  Action green1_Blink_Fast called" << endl;
}
void Actions::green2_Blink_Fast(){
    cout << "  Action green2_Blink_Fast called" << endl;
}
void Actions::red1_Off(){
    cout << "  Action red1_Off called" << endl;
}
void Actions::red2_Off(){
    cout << "  Action red2_Off called" << endl;
}
void Actions::red1_On(){
    cout << "  Action red1_On called" << endl;
}
void Actions::red2_On(){
    cout << "  Action red2_On called" << endl;
}
void Actions::motor1_Off(){
    cout << "  Action motor1_Off called" << endl;
}
void Actions::motor2_Off(){
    cout << "  Action motor2_Off called" << endl;
}

void Actions::entered_Calibration_State(){}
void Actions::entered_Error_State(){}
void Actions::entered_Idle(){}
void Actions::entered_WS_State(){}
void Actions::enteredMainFSM(){};
void Actions::enteredEStoppFSM(){};
