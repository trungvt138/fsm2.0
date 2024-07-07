//
// Created by wild on 22/06/2024.
//

#include "../mainfsm/ws_state.h"

#include <iostream>

#include "idle.h"
#include "../mainfsm/error_state.h"

void WS_State::entry() {

    //std::cout << "WSSate_State Entry" << std::endl;

    std::cout << "\nMainFsm: WS State\n" << std::endl;

    action->ak_l_grn1_on();
    action->ak_l_grn2_on();

    //action->entered_WS_State();
}


void WS_State::exit() {
	action->ak_l_grn1_off();
	action->ak_l_grn2_off();
	action->ak_fbm1_right_off();
	action->ak_fbm2_right_off();
}

void WS_State::enterByDefaultEntryPoint() {
    entry();
    wsstatemachine1->enterViaPseudoStart();
    wsstatemachine2->enterViaPseudoStart();
    wsstatemachine3->enterViaPseudoStart();
}

void WS_State::enterByDeepHistoryEntryPoint(){
    entry();
    wsstatemachine1->enterViaDeepHistory();
    wsstatemachine2->enterViaDeepHistory();
    wsstatemachine3->enterViaDeepHistory();
}

void WS_State::resetDeepHistory() {
    wsstatemachine1->resetDeepHistory();
    wsstatemachine2->resetDeepHistory();
    wsstatemachine3->resetDeepHistory();
}

//FBA1

TriggerProcessingState WS_State::ss_ls_str1_interrupted() {
    std::cout << "WS_State::ss_ls_str1_interrupted called" << std::endl;

    TriggerProcessingState processingstate1 = wsstatemachine1->ss_ls_str1_interrupted();
    if(processingstate1 == TriggerProcessingState::pending) {
        TriggerProcessingState processingstate2 = wsstatemachine2->ss_ls_str1_interrupted();
        if(processingstate2 == TriggerProcessingState::pending){
            return wsstatemachine3->ss_ls_str1_interrupted();
        }
    }

    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ss_ls_str1_continuous() {
    std::cout << "WS_State::ss_ls_str1_continuous called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str1_continuous();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str1_continuous();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_str1_continuous();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str1_continuous();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str1_continuous();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_str1_continuous();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str1_continuous();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str1_continuous();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_str1_continuous();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };


    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::lightbarrier_height1_interrupted() {
    std::cout << "WS_State::lightbarrier_height1_interrupted called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height1_interrupted();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height1_interrupted();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::lightbarrier_height1_continuous() {
    std::cout << "WS_State::lightbarrier_height1_continuous called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->lightbarrier_height1_continuous();
    TriggerProcessingState processingstate1 = wsstatemachine1->lightbarrier_height1_continuous();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok1_active() {
    std::cout << "WS_State::height_ok1_active called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok1_active();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok1_active();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok1_unactive() {
    std::cout << "WS_State::height_ok1_unactive called" << std::endl;

    TriggerProcessingState processingstate2 = wsstatemachine2->height_ok1_unactive();
    TriggerProcessingState processingstate1 = wsstatemachine1->height_ok1_unactive();

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt1_interrupted() {
    std::cout << "WS_State::ss_ls_srt1_interrupted called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt1_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    //Feherfall False Placement
    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt1_continuous() {
    std::cout << "WS_State::ss_ls_srt1_continuous called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_continuous();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_continuous();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt1_continuous();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_continuous();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_continuous();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt1_continuous();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_continuous();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_continuous();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt1_continuous();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms1_erkannt() {
    std::cout << "WS_State::ss_ms1_erkannt called" << std::endl;

TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms1_erkannt();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms1_erkannt();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms1_erkannt();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms1_erkannt();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms1_erkannt();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms1_erkannt();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms1_erkannt();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms1_erkannt();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms1_erkannt();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms1_fall() {
    std::cout << "WS_State::ss_ms1_fall called" << std::endl;

  TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli1_full() {
    std::cout << "WS_State::ss_ls_sli1_full called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_full();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_full();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_full();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_full();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_full();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_full();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_full();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_full();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_full();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli1_rise() {
    std::cout << "WS_State::ss_ls_sli1_rise called" << std::endl;

TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_rise();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_rise();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_rise();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_rise();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_rise();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_rise();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli1_rise();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli1_rise();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli1_rise();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end1_continuous() {
    std::cout << "WS_State::ss_ls_end1_continuous called" << std::endl;

TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_srt1_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end1_interrupted() {
    std::cout << "WS_State::ss_ls_end1_interrupted called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end1_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end1_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end1_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end1_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end1_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end1_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end1_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end1_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ws_sorted_FBA1() {
    std::cout << "WS_State::ws_sorted_FBA1 called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA1();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA1();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ws_sorted_FBA1();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA1();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA1();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ws_sorted_FBA1();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA1();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA1();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ws_sorted_FBA1();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

//FBA2

TriggerProcessingState WS_State::ss_ls_str2_interrupted() {
    std::cout << "WS_State::ss_ls_str2_interrupted called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_str2_continuous() {
    std::cout << "WS_State::ss_ls_str2_continuous called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_continuous();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_continuous();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_continuous();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_continuous();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_continuous();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_continuous();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_str2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_str2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_str2_continuous();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok2_active() {
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_active();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_active();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_active();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_active();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_active();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_active();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_active();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_active();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_active();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_ok2_unactive() {
    std::cout << "WS_State::height_ok2_unactive called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_unactive();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_unactive();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_unactive();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_unactive();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_unactive();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_unactive();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_ok2_unactive();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_ok2_unactive();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_ok2_unactive();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt2_interrupted() {
    std::cout << "WS_State::ss_ls_srt2_interrupted called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_srt2_continuous() {
    std::cout << "WS_State::ss_ls_srt2_continuous called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_continuous();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_continuous();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_continuous();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_continuous();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_continuous();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_continuous();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_srt2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_srt2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_srt2_continuous();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms2_erkannt() {
    std::cout << "WS_State::ss_ms2_erkannt called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_erkannt();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_erkannt();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_erkannt();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_erkannt();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_erkannt();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_erkannt();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_erkannt();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_erkannt();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_erkannt();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ms2_fall() {
    std::cout << "WS_State::ss_ms2_fall called" << std::endl;

TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_fall();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_fall();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_fall();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_fall();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_fall();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_fall();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ms2_fall();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ms2_fall();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ms2_fall();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli2_full() {
    std::cout << "WS_State::ss_ls_sli2_full called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_full();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_full();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli2_full();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_full();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_full();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_sli2_full();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_full();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_full();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ss_ls_sli2_full();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_sli2_rise() {
    std::cout << "WS_State::ss_ls_sli2_rise called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_rise();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_rise();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli2_rise();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_rise();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_rise();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli2_rise();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_sli2_rise();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_sli2_rise();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_sli2_rise();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end2_continuous() {
    std::cout << "WS_State::ss_ls_end2_continuous called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_continuous();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_continuous();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_continuous();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_continuous();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_continuous();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_continuous();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_continuous();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_continuous();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ss_ls_end2_interrupted() {
    std::cout << "WS_State::ss_ls_end2_interrupted called" << std::endl;

    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_interrupted();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_interrupted();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_interrupted();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_interrupted();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_interrupted();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_interrupted();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ss_ls_end2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ss_ls_end2_interrupted();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ss_ls_end2_interrupted();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::ws_sorted_FBA2() {
    std::cout << "WS_State::ws_sorted_FBA2 called" << std::endl;

TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA2();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA2();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->ws_sorted_FBA2();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA2();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA2();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ws_sorted_FBA2();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->ws_sorted_FBA2();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->ws_sorted_FBA2();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->ws_sorted_FBA2();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

//trigger that is consumed
TriggerProcessingState WS_State::ss_t_stp1_pressed() {
    std::cout << "WS_State: ss_t_stp1_pressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ss_t_stp2_pressed() {
    std::cout << "WS_State: ss_t_stp2_pressed called" << std::endl;
    leavingState();
    new(this) Idle;
    enterByDefaultEntryPoint();
    return TriggerProcessingState::consumed;
}


TriggerProcessingState WS_State::unwanted_ws() {
    std::cout << "WS_State: unwanted_ws called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->unwanted_ws();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->unwanted_ws();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->unwanted_ws();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->unwanted_ws();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->unwanted_ws();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->unwanted_ws();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->unwanted_ws();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->unwanted_ws();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->unwanted_ws();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::slide1_free() {
    std::cout << "WS_State: slide1_free called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide1_free();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide1_free();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide1_free();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide1_free();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide1_free();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide1_free();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide1_free();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide1_free();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide1_free();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::slide2_free() {
    std::cout << "WS_State: slide2_free called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide2_free();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide2_free();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide2_free();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide2_free();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide2_free();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide2_free();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->slide2_free();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->slide2_free();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->slide2_free();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::right_order() {
    std::cout << "WS_State: right_order called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->right_order();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->right_order();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->right_order();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->right_order();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->right_order();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->right_order();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->right_order();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->right_order();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->right_order();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_calibration() {
    std::cout << "WS_State: height_calibration called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_calibration();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_calibration();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_calibration();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_calibration();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_calibration();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_calibration();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_calibration();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_calibration();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_calibration();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_high() {
    std::cout << "WS_State: height_high called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_high();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_high();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_high();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_high();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_high();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_high();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_high();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_high();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_high();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;

}

TriggerProcessingState WS_State::height_flat() {
    std::cout << "WS_State: height_flat called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_flat();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_flat();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_flat();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_flat();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_flat();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_flat();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_flat();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_flat();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_flat();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_hole() {
    std::cout << "WS_State: height_hole called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_hole();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_hole();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_hole();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_hole();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_hole();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_hole();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_hole();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_hole();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_hole();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::height_band() {
    std::cout << "WS_State: height_band called" << std::endl;
    TriggerProcessingState processingstate1;
    TriggerProcessingState processingstate2;
    TriggerProcessingState processingstate3;
    

    WorkPiece::StateType state = data->sortWsListDescendingById();

    WorkPiece::StateType state1 =data->getHighestIDWorkPieceState();
    WorkPiece::StateType state2 =data->getSecondHighestIDWorkPieceState();
    WorkPiece::StateType state3 =data->getThirdHighestIDWorkPieceState();
    
    if (state1 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_band();
    }else if (state1== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_band();
    }else if (state1 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_band();
    }

    if (state2 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_band();
    }else if (state2== WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_band();
    }else if (state2 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine3->height_band();
    }

    if (state3 == WorkPiece::StateType::WsState1) {
        processingstate1 = wsstatemachine1->height_band();
    }else if (state3 == WorkPiece::StateType::WsState2) {
        processingstate2 = wsstatemachine2->height_band();
    }else if (state3 == WorkPiece::StateType::WsState3) {
        processingstate3 = wsstatemachine1->height_band();
    }

    

    if (processingstate1 == TriggerProcessingState::consumed || processingstate2 ==TriggerProcessingState::consumed|| processingstate3 ==TriggerProcessingState::consumed) {
        return TriggerProcessingState::consumed;
    };

    return TriggerProcessingState::pending;
}

TriggerProcessingState WS_State::both_slide_full() {
    std::cout << "WS_State: both_slide_full_received called" << std::endl;
    TriggerProcessingState processing_state1 = wsstatemachine1->both_slide_full();
    TriggerProcessingState processing_state2 = wsstatemachine2->both_slide_full();
    TriggerProcessingState processing_state3 = wsstatemachine3->both_slide_full();
    if (processing_state1 == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending&& processing_state3 == TriggerProcessingState::pending) {
        wsstatemachine1->exit();
        wsstatemachine2->exit();
        wsstatemachine3->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}
TriggerProcessingState WS_State::ws_missing() {
    std::cout << "WS_State: ws_missing_received called" << std::endl;
    TriggerProcessingState processing_state1 = wsstatemachine1->ws_missing();
    TriggerProcessingState processing_state2 = wsstatemachine2->ws_missing();
    TriggerProcessingState processing_state3 = wsstatemachine3->ws_missing();
    if (processing_state1 == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending&& processing_state3 == TriggerProcessingState::pending) {
        wsstatemachine1->exit();
        wsstatemachine2->exit();
        wsstatemachine3->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}

TriggerProcessingState WS_State::ws_false_placement() {
    std::cout << "WS_State: ws_false_placement_received called" << std::endl;
    TriggerProcessingState processing_state = wsstatemachine1->ws_false_placement();
    TriggerProcessingState processing_state2 = wsstatemachine2->ws_false_placement();
    TriggerProcessingState processing_state3 = wsstatemachine3->ws_false_placement();
    if (processing_state == TriggerProcessingState::pending && processing_state2 == TriggerProcessingState::pending&& processing_state3 == TriggerProcessingState::pending) {
        wsstatemachine1->exit();
        wsstatemachine2->exit();
        wsstatemachine3->exit();
        leavingState();
        new(this) Error_State;
        enterByBothSlideFullPoint();
    }
    return TriggerProcessingState::consumed;
}

void WS_State::showState() {
    std::cout << "    MainFsm: WS State" << std::endl;
    cout << " " << endl;
    std::cout << "----First WS State-----" << std::endl;
    wsstatemachine1->showState();
    cout << " " << endl;
    std::cout << "----Second WS State----" << std::endl;
    wsstatemachine2->showState();
    std::cout << "----Third WS State-----" << std::endl;
    wsstatemachine3->showState();
}
