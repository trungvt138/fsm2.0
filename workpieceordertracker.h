#ifndef WORKPIECEORDERTRACKER_H
#define WORKPIECEORDERTRACKER_H

#include "workpiece.h"
#include <vector>

class WorkPieceOrderTracker {
private:
    std::vector<WorkPiece> order;
    std::vector<WorkPiece::WorkPieceType> defaultOrder = {
        WorkPiece::WorkPieceType::WP_High_Hole_Metal,
        WorkPiece::WorkPieceType::WP_High_Hole_Metal,
        WorkPiece::WorkPieceType::WP_Flat
    };
    size_t expectedIndex = 0;

    void resetTracker();
public:
    // Constructor
    WorkPieceOrderTracker()= default;

    // Add a WorkPiece to the order
    void addWorkPiece(const WorkPiece *wp);

    void removeWorkPiece();

    WorkPiece getLastWorkPiece();

    // Check if a WorkPiece is in the correct order
    bool isInCorrectOrder();

    bool isOrderCompleted();

    // Display all WorkPieces in the order
    void displayOrder() const;
};

#endif // WORKPIECEORDERTRACKER_H
