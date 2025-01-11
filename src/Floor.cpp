#include "Floor.h"

Floor::Floor(string name, unordered_map<ParkingType, vector<ParkingSlot*> > parkingSlotMap) {
    this->name = name;
    this->isOperational = true;
    this->parkingSlotMap = parkingSlotMap;
}

void Floor::closeOperation() {
    this->isOperational = false;
}