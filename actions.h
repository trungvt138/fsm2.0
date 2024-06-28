//
// Created by Trung Dam on 12.06.24.
//

#ifndef ACTIONS_H
#define ACTIONS_H



class Actions {
public:

   virtual ~Actions();



//

    // for didactic / testing purpose only
    virtual void enteredMainFSM(){};
    virtual void enteredEStoppFSM(){};
    virtual void entered_Error_State(){};
    virtual void entered_Operation_State(){};
    virtual void entered_Calibration_State(){};
    virtual void entered_WS_State(){};
    virtual void entered_Idle(){};

	Actions(){};

    //virtual void send(Message message); // Methodendeklaration für den Nachrichtenversand
   // virtual void setLogicInstance(Logic *logic); // Methode zur Übergabe der Logic-Instanz

    virtual void ak_l_grn1_on();
    virtual void ak_l_grn1_off();
    virtual void ak_l_rot1_on();
    virtual void ak_l_rot1_off();
    virtual void ak_l_glb1_on();
    virtual void ak_l_glb1_off();
    virtual void ak_fbm1_right_on();
    virtual void ak_fbm1_right_off();
    virtual void ak_fbm1_left_on();
    virtual void ak_fbm1_left_off();
    virtual void ak_fbm1_slow_on();
    virtual void ak_fbm1_slow_off();
    virtual void ak_fbm1_stop_on();
    virtual void ak_fbm1_stop_off();
    virtual void ak_l_rot1_blink_fast();
    virtual void ak_l_rot1_blink_slow();    
    virtual void ak_l_glb1_blink_fast();    
    virtual void ak_l_grn1_blink_fast();   
    virtual void ak_awf_wch1_on();    
    virtual void ak_awf_wch1_off();    
    virtual void ak_l_grn2_on();    
    virtual void ak_l_grn2_off();    
    virtual void ak_l_rot2_on();    
    virtual void ak_l_rot2_off();    
    virtual void ak_l_glb2_on();    
    virtual void ak_l_glb2_off();    
    virtual void ak_fbm2_right_on();   
    virtual void ak_fbm2_right_off();    
    virtual void ak_fbm2_left_on();    
    virtual void ak_fbm2_left_off();    
    virtual void ak_fbm2_slow_on();    
    virtual void ak_fbm2_slow_off();    
    virtual void ak_fbm2_stop_on();    
    virtual void ak_fbm2_stop_off();    
    virtual void ak_l_rot2_blink_fast();
    virtual void ak_l_rot2_blink_slow();
    virtual void ak_l_glb2_blink_fast();
    virtual void ak_l_grn2_blink_fast();
    virtual void ak_awf_wch2_on();
    virtual void ak_awf_wch2_off();
    virtual void start_calibration();
    virtual void stop_calibration();

    
    virtual void sample_band_start();
    virtual void sample_band_stop();
    virtual void sample_high_start();
    virtual void sample_hole_start();
    virtual void sample_flat_start();



};



#endif //ACTIONS_H
