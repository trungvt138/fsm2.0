#include "workpieceordertracker.h"

void WorkPieceOrderTracker::addWorkPiece(const WorkPiece& wp) {
    if (isOrderCompleted()) {
        resetTracker();
    }
    order.push_back(wp);
}

bool WorkPieceOrderTracker::isInCorrectOrder() {
    WorkPiece wp = getLastWorkPiece();
    bool isRightOrder = wp.getType() == defaultOrder[expectedIndex];
    if (isRightOrder) {
        expectedIndex++;
    }
    return isRightOrder;
}

bool WorkPieceOrderTracker::isOrderCompleted() {
    return expectedIndex == 3;
}

void WorkPieceOrderTracker::resetTracker() {
    order.clear();
    expectedIndex = 0;
}

WorkPiece WorkPieceOrderTracker::getLastWorkPiece() {
    return order.back();
}

void WorkPieceOrderTracker::removeWorkPiece() {
    if (!order.empty()) {
        order.pop_back(); // Remove the last WorkPiece
    }
}

void WorkPieceOrderTracker::displayOrder() const {
    std::cout << "WorkPiece Order:\n";
    for (const auto& wp : order) {
        wp.display();
        std::cout << "\n";
    }
}
