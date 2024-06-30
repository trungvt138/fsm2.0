//
// Created by Trung Dam on 29.06.24.
//

#ifndef CHECKSLIDEBASESTATE_H
#define CHECKSLIDEBASESTATE_H


enum class TriggerProcessingState;
class Actions;
class ContextData;

class CheckSlideBaseState {
protected:
    ContextData *data;
    Actions *action;
public:
    virtual void initSubStateMachines(){};

    void setData(ContextData *data) {this->data = data;};
    void setAction(Actions *action) {this->action = action;};

    virtual bool isPseudoStartState() {return false;};
    virtual bool isPseudoEndState() {return false;};

    virtual void enterByDefaultEntryPoint(){entry();};
    virtual void enterByDeepHistoryEntryPoint(){entry();};

    virtual void leavingState(){exit();};

    virtual void enterViaPseudoStart();
    virtual void enterViaPortE1(){};
    virtual void enterViaPortE2(){};
    virtual void enterViaPortCL(){};
    virtual void handleDefaultExit(const TriggerProcessingState &handled) {};

    virtual void resetDeepHistory(){};

    virtual void entry(){showState();};
    virtual void exit(){};

    //Trigger
    virtual void ss_ls_sli1_rise() {};
    virtual void ss_ls_sli1_full() {};
    virtual void ss_ls_sli2_rise() {};
    virtual void ss_ls_sli2_full() {};
    virtual void after1s() {};

    virtual void slide1_free(){};
    virtual void slide2_free(){};

    virtual void showState(){};
};



#endif //CHECKSLIDEBASESTATE_H
