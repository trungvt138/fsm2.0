cmake_minimum_required(VERSION 3.28)
project(fsm2_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(fsm2_0 main.cpp
        contextdata.cpp
        context.cpp
        actions.cpp
        actions.cpp
        rootfsm/basestate.cpp
        rootfsm/basestate.cpp
        rootfsm/estoppfsm.cpp
        rootfsm/mainfsm.cpp
        rootfsm/pseudostartstate.cpp
        mainfsm/mainbasestate.cpp
        mainfsm/ws_state.cpp
        mainfsm/idle.cpp
        mainfsm/error_state.cpp
        mainfsm/calibration_state.cpp
        mainfsm/calibration_state.h
        mainfsm/ws_state.h
        estfsm/Connection_Lost.h
        estfsm/estbasestate.cpp
        estfsm/Connection_Lost.cpp
        estfsm/EStop1_pressed.cpp
        estfsm/EStop2_pressed.cpp
        estfsm/EST1_and_CL.h
        estfsm/EST2_and_CL.h
        estfsm/EST2_and_CL.cpp
        estfsm/Reset.h
        estfsm/EST1_and_EST2.h
        estfsm/EST1_and_CL.cpp
        estfsm/EST1_and_EST2.cpp
        estfsm/Reset.cpp
        resetfsm/resetbasestate.cpp
        resetfsm/resetbasestate.h
        resetfsm/resetpseudostartstate.h
        estfsm/estpseudoendstate.h
        resetfsm/Wait_For_Reset1.cpp
        resetfsm/Wait_For_Reset1.h
        resetfsm/Wait_For_Reset2.cpp
        resetfsm/Wait_For_Reset2.h
        resetfsm/resetidle.cpp
        resetfsm/resetidle.h)
