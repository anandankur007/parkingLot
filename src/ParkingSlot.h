#include "iostream"
#include "Ticket.h"
#include "ParkingType.h"
using namespace std;

class ParkingSlot {
    string name;
    public:
    bool isAvailable;
    ParkingSlot(string name);
    Ticket* addVehicle(ParkingType parkingType, string regNumber);
    bool removeVehicle(Ticket *ticket);
    void underMaintenance();
};