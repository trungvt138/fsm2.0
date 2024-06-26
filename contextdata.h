//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXTDATA_H
#define CONTEXTDATA_H
#include <chrono>

class ContextData {

private:
	enum Type{metal, nonmetal};

    int errorCounter = 0;

    int ws_count = 0;
    int ws_ID = 0;
    bool FBA1 = true;

    bool slide1Full;
    bool slide2Full;

    int ws_FBA1 = 0;
    int ws_FBA2 = 0;

    int ls_str_height_tick_Fast = 0;
    int ls_height_srt_tick_Fast = 0;
    int ls_srt_end_tick_Fast = 0;

    int ls_str_height_tick_Slow = 0;
    int ls_height_srt_tick_Slow = 0;
    int ls_srt_end_tick_Slow = 0;

    std::chrono::high_resolution_clock::time_point start_str_height_time_Fast;
    std::chrono::high_resolution_clock::time_point start_height_srt_time_Fast;
    std::chrono::high_resolution_clock::time_point start_srt_end_time_Fast;

    std::chrono::high_resolution_clock::time_point start_str_height_time_Slow;
    std::chrono::high_resolution_clock::time_point start_height_srt_time_Slow;
    std::chrono::high_resolution_clock::time_point start_srt_end_time_Slow;
    

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
    bool checkSlide1Full();
    bool checkSlide2Full();



    int setStrHeightTickSlow();
    int setHeightSrtTickSlow();
    int setSrtEndTickSlow();
    void startStrHeightTickSlow();
    void startHeightSrtTickSlow();
    void startSrtEndTickSlow();

    int setStrHeightTickFast();
    int setHeightSrtTickFast();
    int setSrtEndTickFast();
    void startStrHeightTickFast();
    void startHeightSrtTickFast();
    void startSrtEndTickFast();

};

#endif //CONTEXTDATA_H
