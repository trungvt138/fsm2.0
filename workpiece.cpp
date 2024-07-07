//
// Created by Trung Dam on 02.07.24.
//

#include "workpiece.h"

// Initialize static member nextId
int WorkPiece::nextId = 0;

// Constructors
WorkPiece::WorkPiece()
    : id(nextId++), isTall(false), hasHole(false), isFlat(false), containsMetal(false), holeType(HoleType::None), type(WorkPieceType::Unknown) {}

WorkPiece::WorkPiece(bool tall, bool hole, bool flat, bool metal, HoleType holeType, WorkPieceType workPieceType)
    : id(nextId++), isTall(tall), hasHole(hole), isFlat(flat), containsMetal(metal), holeType(holeType), type(workPieceType) {}

// Accessors
bool WorkPiece::getIsTall() const {
    return isTall;
}

void WorkPiece::setIsTall(bool tall) {
    isTall = tall;
}

bool WorkPiece::getHasHole() const {
    return hasHole;
}

void WorkPiece::setHasHole(bool hole) {
    hasHole = hole;
}

bool WorkPiece::getIsFlat() const {
    return isFlat;
}

void WorkPiece::setIsFlat(bool flat) {
    isFlat = flat;
}

WorkPiece::StateType WorkPiece::getStateType() const {
    return statetype;
}

bool WorkPiece::getContainsMetal() const {
    return containsMetal;
}

void WorkPiece::setContainsMetal(bool metal) {
    containsMetal = metal;
}

WorkPiece::HoleType WorkPiece::getHoleType() const {
    return holeType;
}

void WorkPiece::setHoleType(HoleType holeType) {
    this->holeType = holeType;
}

WorkPiece::WorkPieceType WorkPiece::getType() const {
    return type;
}

void WorkPiece::setType(WorkPieceType type) {
    this->type = type;
}

void WorkPiece::setStateType(StateType type) {
    this->statetype = type;
}

// Display method
void WorkPiece::display() const {
    std::cout << "WorkPiece Type: " << getTypeString(type) << "\n"
              << "Tall: " << (isTall ? "Yes" : "No") << "\n"
              << "Has Hole: " << (hasHole ? "Yes" : "No") << "\n"
              << "Hole Type: " << getHoleTypeString(holeType) << "\n"
              << "Flat: " << (isFlat ? "Yes" : "No") << "\n"
              << "Contains Metal: " << (containsMetal ? "Yes" : "No") << "\n";
}

// Private helper methods
std::string WorkPiece::getHoleTypeString(HoleType holeType) const {
    switch (holeType) {
        case HoleType::None: return "None";
        case HoleType::Normal: return "Normal";
        case HoleType::Concentric: return "Concentric";
        default: return "Unknown";
    }
}

std::string WorkPiece::getTypeString(WorkPieceType type) const {
    switch (type) {
        case WorkPieceType::Unknown: return "Unknown";
        case WorkPieceType::WP_Flat: return "WP Flat";
        case WorkPieceType::WP_High: return "WP High";
        case WorkPieceType::WP_High_Hole: return "WP High Hole";
        case WorkPieceType::WP_High_Hole_Metal: return "WP High Hole Metal";
        case WorkPieceType::WP_Binary: return "WP Binary";
        default: return "Unknown";
    }
}
