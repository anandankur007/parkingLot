#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(string name) {
    this->name = name;
    this->isAvailable = true;
}

Ticket* ParkingSlot::addVehicle(ParkingType parkingType, string regNumber) {
    return new Ticket(regNumber, parkingType);
}

bool ParkingSlot::removeVehicle(Ticket *ticket) {
    if(!ticket)
    return 0;
    isAvailable = true;
    ticket->closeTicket();
    return 1;
}

void ParkingSlot::underMaintenance() {
    if(isAvailable)
        isAvailable = false;
}