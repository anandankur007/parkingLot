#include "iostream"
#include "mutex"
#include "chrono"
#include "Floor.h"
#include "Ticket.h"
#include "thread"
#include "ParkingType.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

class ParkingLot {
    static mutex mtx;
    static ParkingLot *parkingLotInstance;
    ParkingLot(){}
    ParkingLot(vector<Floor*> floorList);
    //ParkingLot operator =(const ParkingLot&);
    public:
    vector<Floor*> floorList;
    unordered_map<Ticket*, ParkingSlot*> ticketToSlotMap;
    static ParkingLot* getInstance(vector<Floor*> floorList);
    Ticket* getTicket(VehicleType vehicleType, string regNumber);
    ParkingType getParkingType(VehicleType vehicleType);
    int getParkingCharges(ParkingType parkingType);
    bool scanAndPay(Ticket *ticket);
};

