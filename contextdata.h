//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXTDATA_H
#define CONTEXTDATA_H


class ContextData {

private:
    enum Type{metal, nonmetal};

    int errorCounter = 0;
    int ws_count = 0;
    int ws_ID = 0;
    bool FBA1 = true;

    int ws_FBA1 = 0;
    int ws_FBA2 = 0;

public:
    void incErrorCounter();
    void clearErrorCounter();
    void show() const;
    void wsCounterUp();
    void wsCounterUpFBA1();
    void wsCounterDownFBA1();
    void wsCounterUpFBA2();
    void wsCounterDownFBA2();
    void setID(int ws_count);
    int checkFBA1Counter();
    int checkFBA2Counter();
    bool checkFBA1();
    //    WSData::Type updateWSData() const {return type;}


};

#endif //CONTEXTDATA_H
