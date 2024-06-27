//
// Created by Trung Dam on 12.06.24.
//

#ifndef ACTIONS_H
#define ACTIONS_H



class Actions {
public:
    virtual ~Actions();
    virtual void ak_l_grn1_blink_fast();
    virtual void ak_l_grn2_blink_fast();
    virtual void ak_l_grn1_off();
    virtual void ak_l_grn2_off();
    virtual void ak_l_grn1_on();
    virtual void ak_l_grn2_on();
    virtual void ak_l_rot1_off();
    virtual void ak_l_rot2_off();
    virtual void ak_l_rot1_on();
    virtual void ak_l_rot2_on();
    virtual void ak_fbm1_right_off();
    virtual void ak_fbm2_right_off();

    virtual void ak_fbm1_right_on();

    virtual void ak_l_glb1_on();
    virtual void ak_l_glb1_off();

    virtual void ak_fbm1_left_on();
    virtual void ak_fbm1_left_off();
    virtual void ak_fbm1_slow_on();
    virtual void ak_fbm1_slow_off();
    virtual void ak_fbm1_stop_on();
    virtual void ak_fbm1_stop_off();
    virtual void ak_l_rot1_blink_fast();
    virtual void ak_l_rot1_blink_slow();
    virtual void ak_l_glb1_blink_fast();

    virtual void ak_awf_wch1_on();
    virtual void ak_awf_wch1_off();


    virtual void ak_l_glb2_on();
    virtual void ak_l_glb2_off();
    virtual void ak_fbm2_right_on();
    virtual void ak_fbm2_left_on();
    virtual void ak_fbm2_left_off();
    virtual void ak_fbm2_slow_on();
    virtual void ak_fbm2_slow_off();
    virtual void ak_fbm2_stop_on();
    virtual void ak_fbm2_stop_off();
    virtual void ak_l_rot2_blink_fast();
    virtual void ak_l_rot2_blink_slow();
    virtual void ak_l_glb2_blink_fast();
    virtual void ak_awf_wch2_on();
    virtual void ak_awf_wch2_off();




    // for didactic / testing purpose only
    virtual void enteredMainFSM();
    virtual void enteredEStoppFSM();
    virtual void entered_Error_State();
    virtual void entered_Operation_State();
    virtual void entered_Calibration_State();
    virtual void entered_WS_State();
    virtual void entered_Idle();
};



#endif //ACTIONS_H
