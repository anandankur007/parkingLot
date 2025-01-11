#include "ParkingSlot.h"
#include "ParkingType.h"

class Floor {
    string name;
    bool isOperational;
    public:
    unordered_map<ParkingType, vector<ParkingSlot*> > parkingSlotMap;
    Floor(){}
    Floor(string name, unordered_map<ParkingType, vector<ParkingSlot*> > parkingSlotMap);
    void closeOperation();
};

// Floor::Floor(string name, unordered_map<ParkingType, vector<ParkingSlot*> > parkingSlotMap) {
//     this->name = name;
//     this->isOperational = true;
//     this->parkingSlotMap = parkingSlotMap;
// }

// void Floor::closeOperation() {
//     this->isOperational = false;
// }