//
// Created by trung on 31/05/2024.
//

#include <iostream>

#include "actions.h"
#include "context.h"
#include "workpiece.h"
#include "workpieceordertracker.h"

int main(int argc, char** argv) {
    auto *action = new Actions();

    //Enter Idle
    Context fsmA(action);
    fsmA.ss_t_str1_shortpressed();

    //Enter 1st WS Operation FBA1
    fsmA.ss_ls_str1_interrupted();
    fsmA.ss_ls_str1_continuous();
    fsmA.height_calibration();

    //High_Hole
    fsmA.height_high();
    fsmA.height_hole();
    fsmA.height_high();
    fsmA.height_band();
    fsmA.ss_ls_srt1_interrupted();
    fsmA.ss_ls_sli1_full();

    fsmA.ss_ls_str1_interrupted();
    fsmA.ss_ls_str1_interrupted();


    //1st WS now enters FBA2
    //Enter 1st WS Operation FBA2
    //fsmA.ss_ls_str1_interrupted();
    //fsmA.ss_ls_str2_continuous();

    //Enter 2nd WS Operation FBA1
    //fsmA.ss_ls_str1_interrupted();
    //fsmA.ss_ls_str1_continuous();
    cout <<"---------------" << endl;

    fsmA.showState();

    // WorkPieceOrderTracker tracker;
    //
    // // Create WorkPiece objects
    // WorkPiece wp1(false, false, true, false, WorkPiece::HoleType::None, WorkPiece::WorkPieceType::WP_High_Hole_Metal);
    // WorkPiece wp2(true, true, false, true, WorkPiece::HoleType::Normal, WorkPiece::WorkPieceType::WP_High_Hole_Metal);
    // WorkPiece wp3(true, true, false, true, WorkPiece::HoleType::Normal, WorkPiece::WorkPieceType::WP_Flat);
    //
    // // Add WorkPieces to the tracker
    // tracker.addWorkPiece(wp1);
    // std::cout << "Is wp1 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";
    //
    // tracker.addWorkPiece(wp2);
    // std::cout << "Is wp2 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";
    //
    // tracker.addWorkPiece(wp3);
    // std::cout << "Is wp3 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";
    //
    // tracker.addWorkPiece(wp1);
    // std::cout << "Is wp1 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";
    //
    // // Display the order
    // tracker.displayOrder();

}

