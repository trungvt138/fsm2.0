/*
 * operation_state.cpp
 *
 *  Created on: 23 Jun 2024
 *      Author: WildanmSyufie
 */

#include "operation_state.h"

#include "WSIdle.h"
#include "wsbasestate.h"
#include "../../mainfsm/error_state.h"

void Operation_State::entry() {
    std::cout << "\nWSFsm: Operation State\n" << std::endl;
}

// TODO exit
void Operation_State::exit() {

}

void Operation_State::resetDeepHistory() {
    leavingState();
    opstatemachine->exit();
    new(this) WSIdle;
    enterByDefaultEntryPoint();
}

TriggerProcessingState Operation_State::handleDefaultExit(const TriggerProcessingState &processingstate) {
    if (processingstate == TriggerProcessingState::endstatereached) {
        // leavingState();         // not needed, as sub-state machine cannot act anymore.
    	opstatemachine->exit();   // just call own exit.
        new(this) WSIdle;
        enterByDefaultEntryPoint();
        return TriggerProcessingState::consumed;
    }
    if (processingstate == TriggerProcessingState::both_slide_full) {
        opstatemachine->exit();
        return TriggerProcessingState::both_slide_full;
    }
    return TriggerProcessingState::pending;
}

void Operation_State::enterByDefaultEntryPoint() {
    entry();
    opstatemachine->enterViaPseudoStart();
}

// void Operation_State::enterByDeepHistoryEntryPoint(){
//     entry();
//     opstatemachine->enterViaDeepHistory();
// }

//FBA1

TriggerProcessingState Operation_State::ss_ls_str1_interrupted() {
    std::cout << "Operation_State::ss_ls_str1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str1_interrupted();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_str1_continuous() {
    std::cout << "Operation_State::ss_ls_str1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str1_continuous();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::lightbarrier_height1_interrupted() {
    std::cout << "Operation_State::lightbarrier_height1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height1_interrupted();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::lightbarrier_height1_continuous() {
    std::cout << "Operation_State::lightbarrier_height1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height1_continuous();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::height_ok1_active() {
    std::cout << "Operation_State::height_ok1_active called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok1_active();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::height_ok1_unactive() {
    std::cout << "Operation_State::height_ok1_unactive called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok1_unactive();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_srt1_interrupted() {
    std::cout << "Operation_State::ss_ls_srt1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt1_interrupted();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_srt1_continuous() {
    std::cout << "Operation_State::ss_ls_srt1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt1_continuous();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ms1_erkannt() {
    std::cout << "Operation_State::ss_ms1_erkannt called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms1_erkannt();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ms1_fall() {
    std::cout << "Operation_State::ss_ms1_fall called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms1_fall();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::switch1_open() {
    std::cout << "Operation_State::switch1_open called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch1_open();
    return handleDefaultExit(processingstate);
}


TriggerProcessingState Operation_State::switch1_unopen() {
    std::cout << "Operation_State::switch1_unopen called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch1_unopen();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_sli1_full() {
    std::cout << "Operation_State::ss_ls_sli1_full called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli1_full();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_sli1_rise() {
    std::cout << "Operation_State::ss_ls_sli1_rise called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli1_rise();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::ss_ls_end1_continuous() {
    std::cout << "Operation_State::ss_ls_end1_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end1_continuous();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_end1_interrupted() {
    std::cout << "Operation_State::ss_ls_end1_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end1_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str1_pressed() {
    std::cout << "Operation_State::ss_t_str1_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_pressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str1_unpressed() {
    std::cout << "Operation_State::ss_t_str1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_stp1_unpressed() {
    std::cout << "Operation_State::ss_t_stp1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_stp1_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_rst1_pressed() {
    std::cout << "Operation_State::ss_t_rst1_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst1_pressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_rst1_unpressed() {
    std::cout << "Operation_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst1_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str1_shortpressed() {
    std::cout << "Operation_State::ss_t_str1_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str1_shortpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ws_sorted_FBA1() {
    std::cout << "Operation_State::ws_sorted_FBA1 called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ws_sorted_FBA1();
    return handleDefaultExit(processingstate);

}

//FBA2

TriggerProcessingState Operation_State::ss_ls_str2_interrupted() {
    std::cout << "Operation_State::ss_ls_str2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_str2_continuous() {
    std::cout << "Operation_State::ss_ls_str2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_str2_continuous();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::lightbarrier_height2_interrupted() {
    std::cout << "Operation_State::lightbarrier_height2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::lightbarrier_height2_continuous() {
    std::cout << "Operation_State::lightbarrier_height2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->lightbarrier_height2_continuous();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_ok2_active() {
    std::cout << "Operation_State::height_ok2_active called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok2_active();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_ok2_unactive() {
    std::cout << "Operation_State::height_ok2_unactive called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_ok2_unactive();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_srt2_interrupted() {
    std::cout << "Operation_State::ss_ls_srt2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_srt2_continuous() {
    std::cout << "Operation_State::ss_ls_srt2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_srt2_continuous();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ms2_erkannt() {
    std::cout << "Operation_State::ss_ms2_erkannt called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms2_erkannt();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ms2_fall() {
    std::cout << "Operation_State::ss_ms2_fall called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ms2_fall();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::switch2_open() {
    std::cout << "Operation_State::switch2_open called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch2_open();
    return handleDefaultExit(processingstate);

}


TriggerProcessingState Operation_State::switch2_unopen() {
    std::cout << "Operation_State::switch2_unopen called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->switch2_unopen();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_sli2_full() {
    std::cout << "Operation_State::ss_ls_sli2_full called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli2_full();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_sli2_rise() {
    std::cout << "Operation_State::ss_ls_sli2_rise called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_sli2_rise();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_end2_continuous() {
    std::cout << "Operation_State::ss_ls_end2_continuous called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end2_continuous();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_ls_end2_interrupted() {
    std::cout << "Operation_State::ss_ls_end2_interrupted called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_ls_end2_interrupted();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str2_pressed() {
    std::cout << "Operation_State::ss_t_str2_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_pressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str2_unpressed() {
    std::cout << "Operation_State::ss_t_str2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_stp2_unpressed() {
    std::cout << "Operation_State::ss_t_stp2_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_stp2_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_rst2_pressed() {
    std::cout << "Operation_State::ss_t_rst2_pressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst2_pressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_rst2_unpressed() {
    std::cout << "Operation_State::ss_t_rst1_unpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_rst2_unpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ss_t_str2_shortpressed() {
    std::cout << "Operation_State::ss_t_str2_shortpressed called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ss_t_str2_shortpressed();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::ws_sorted_FBA2() {
    std::cout << "Operation_State::ws_sorted_FBA2 called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->ws_sorted_FBA2();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::slide1_free() {
    std::cout << "Operation_State::slide1_free called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->slide1_free();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::slide2_free() {
    std::cout << "Operation_State::slide2_free called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->slide2_free();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::right_order() {
    std::cout << "Operation_State::right_order called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->right_order();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::unwanted_ws() {
    std::cout << "Operation_State::unwanted_ws called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->unwanted_ws();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::error_gone() {
    std::cout << "Operation_State::error_gone called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->error_gone();
    return handleDefaultExit(processingstate);
}

TriggerProcessingState Operation_State::height_calibration() {
    std::cout << "Operation_State::height_calibration called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_calibration();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_high() {
    std::cout << "Operation_State::height_high called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_high();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_flat() {
    std::cout << "Operation_State::height_flat called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_flat();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_hole() {
    std::cout << "Operation_State::height_hole called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_hole();
    return handleDefaultExit(processingstate);

}

TriggerProcessingState Operation_State::height_band() {
    std::cout << "Operation_State::height_band called" << std::endl;

    TriggerProcessingState processingstate = opstatemachine->height_band();
    return handleDefaultExit(processingstate);

}

//for other fsm

// TriggerProcessingState Operation_State::ws_missing() {
//     std::cout << "WS_State: ws_missing_received called" << std::endl;
//     leavingState();
//     new(this) Error_State;
//     enterByDefaultEntryPoint();
//     return TriggerProcessingState::consumed;
// }
//
// TriggerProcessingState Operation_State::ws_false_placement() {
//     std::cout << "WS_State: ws_false_placement_received called" << std::endl;
//     leavingState();
//     new(this) Error_State;
//     enterByDefaultEntryPoint();
//     return TriggerProcessingState::consumed;
// }


void Operation_State::showState() {
    std::cout << "      WSFsm: Operation State" << std::endl;
    opstatemachine->showState();
}

void Operation_State::enterByDeepHistoryEntryPoint() {
    entry();
    opstatemachine->enterViaDeepHistory();
}
