//
// Created by Trung Dam on 02.07.24.
//

#ifndef WORKPIECE_H
#define WORKPIECE_H

#include <iostream>
#include <string>

class WorkPiece {
public:
    // Enum for HoleType
    enum class HoleType {
        None,
        Normal,
        Concentric
    };

    // Enum for WorkPieceType
    enum class WorkPieceType {
        Unknown,
        WP_Flat,
		WP_High,
        WP_High_Hole,
        WP_High_Hole_Metal,
        WP_Binary
    };

    enum class StateType {
        WsState1,
        WsState2,
        WsState3,
        WsState4,
        noWsState
        
    };
private:
    bool isTall;
    bool hasHole;
    bool isFlat;
    bool containsMetal;
    HoleType holeType;
    WorkPieceType type;
    StateType statetype;
    int id;
    static int nextId;
public:
    // Constructors
    WorkPiece();
    WorkPiece(bool tall, bool hole, bool flat, bool metal, HoleType holeType, WorkPieceType workPieceType);

    // Accessors
    int getId() const { return id; }

    bool getIsTall() const;
    void setIsTall(bool tall);

    bool getHasHole() const;
    void setHasHole(bool hole);

    bool getIsFlat() const;
    void setIsFlat(bool flat);

    StateType getStateType() const;

    bool getContainsMetal() const;
    void setContainsMetal(bool metal);

    HoleType getHoleType() const;
    void setHoleType(HoleType holeType);

    void setStateType(StateType type);

    WorkPieceType getType() const;
    void setType(WorkPieceType type);

    // Display method
    void display() const;

private:
    std::string getHoleTypeString(HoleType holeType) const;
    std::string getTypeString(WorkPieceType type) const;
    int wsState;
};

#endif // WORKPIECE_H

