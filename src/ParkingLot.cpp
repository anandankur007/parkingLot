#include "ParkingLot.h"
#include "Ticket.h"
using namespace std;

mutex ParkingLot::mtx;
ParkingLot* ParkingLot::parkingLotInstance = NULL;

ParkingLot::ParkingLot(vector<Floor*> floorList) {
    this->floorList = floorList;
}

ParkingLot* ParkingLot::getInstance(vector<Floor*> floorList) {
    if(parkingLotInstance==NULL) {
        mtx.lock();
        if(parkingLotInstance==NULL) {
            parkingLotInstance = new ParkingLot(floorList);
        }
        mtx.unlock();
    }
    return parkingLotInstance;
}

ParkingType ParkingLot::getParkingType(VehicleType vehicleType) {
    switch(vehicleType) {
        case HatchBack:
        case Sedan:
            return COMPACT;
        case SUV:
            return MIDRANGE;
        case MUV:
            return LARGE;
        default:
            return LARGE;
    }
}

Ticket* ParkingLot::getTicket(VehicleType vehicleType, string regNumber) {
    ParkingType parkingType = getParkingType(vehicleType);
    for(auto floor : floorList) {
        for(auto slot : floor->parkingSlotMap[parkingType]) {
            if(slot->isAvailable) {
                cout<<"Slot is available.\n";
                Ticket *ticket = slot->addVehicle(parkingType, regNumber);
                ticketToSlotMap[ticket] = slot;
                return ticket;
            }
        }
    }
    cout<<"Slot is not available.\n";
    return NULL;
}

int ParkingLot::getParkingCharges(ParkingType parkingType) {
    switch(parkingType) {
        case COMPACT:
            return 10;
        case MIDRANGE:
            return 20;
        case LARGE:
            return 30;
        default:
            return 0;
    }
}

bool ParkingLot::scanAndPay(Ticket *ticket) {
    ParkingType parkingType = ticket->parkingType;
    ParkingSlot *parkingSlot = ticketToSlotMap[ticket];
    time_point<high_resolution_clock> now = high_resolution_clock::now();
    duration<double> duration = now - ticket->start_time;
    int durationInHOurs = duration.count();
    // int durationInHOurs = ceil(ceil(duration.count()/60))/60;
    int charges = durationInHOurs*getParkingCharges(parkingType);
    cout<<"Charges "<<charges<<" has been paid for ticket id: "<<ticket->ticketId<<"\n";
    return parkingSlot->removeVehicle(ticket);
}