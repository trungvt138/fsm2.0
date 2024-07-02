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

    //Enter Operation
    fsmA.ss_ls_str1_interrupted();

    fsmA.ss_ls_str1_continuous();
    fsmA.height_calibration();
    fsmA.height_calibration();
    fsmA.ss_ls_srt1_interrupted();

    WorkPieceOrderTracker tracker;

    // Create WorkPiece objects
    WorkPiece wp1(false, false, true, false, WorkPiece::HoleType::None, WorkPiece::WorkPieceType::WP_High_Hole_Metal);
    WorkPiece wp2(true, true, false, true, WorkPiece::HoleType::Normal, WorkPiece::WorkPieceType::WP_High_Hole_Metal);
    WorkPiece wp3(true, true, false, true, WorkPiece::HoleType::Normal, WorkPiece::WorkPieceType::WP_Flat);

    // Add WorkPieces to the tracker
    tracker.addWorkPiece(wp1);
    std::cout << "Is wp1 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";

    tracker.addWorkPiece(wp2);
    std::cout << "Is wp2 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";

    tracker.addWorkPiece(wp3);
    std::cout << "Is wp3 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";

    tracker.addWorkPiece(wp1);
    std::cout << "Is wp1 in correct order? " << (tracker.isInCorrectOrder() ? "Yes" : "No") << "\n";

    // Display the order
    tracker.displayOrder();

}

