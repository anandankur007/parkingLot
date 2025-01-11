#include "iostream"
#include "ParkingLot.h"
using namespace std;

int main() {
    unordered_map<ParkingType, vector<ParkingSlot*> > slotMap1;
    unordered_map<ParkingType, vector<ParkingSlot*> > slotMap2;
    vector<ParkingSlot*> slotList11;
    vector<ParkingSlot*> slotList12;
    vector<ParkingSlot*> slotList13;
    vector<ParkingSlot*> slotList21;
    vector<ParkingSlot*> slotList22;
    vector<ParkingSlot*> slotList23;
    for(int i=0;i<3;i++) {
        //for first floor
        ParkingSlot *parkingSlot11 = new ParkingSlot("dkjsh");
        slotList11.push_back(parkingSlot11);
        ParkingSlot *parkingSlot12 = new ParkingSlot(to_string(i+1));
        slotList12.push_back(parkingSlot12);
        ParkingSlot *parkingSlot13 = new ParkingSlot(to_string(i+1));
        slotList13.push_back(parkingSlot13);
        //for second floor
        ParkingSlot *parkingSlot21 = new ParkingSlot(to_string(i+1));
        slotList21.push_back(parkingSlot21);
        ParkingSlot *parkingSlot22 = new ParkingSlot(to_string(i+1));
        slotList22.push_back(parkingSlot22);
        ParkingSlot *parkingSlot23 = new ParkingSlot(to_string(i+1));
        slotList23.push_back(parkingSlot23);
    }
    slotMap1[COMPACT] = slotList12;
    slotMap1[MIDRANGE] = slotList12;
    slotMap1[LARGE] = slotList13;
    slotMap2[COMPACT] = slotList21;
    slotMap2[MIDRANGE] = slotList22;
    slotMap2[LARGE] = slotList23;
    Floor *floor1 = new Floor("F1", slotMap1);
    Floor *floor2 = new Floor("F2", slotMap2);
    vector<Floor*> floorList;
    floorList.push_back(floor1);
    //comment the below line for slot not available case
    floorList.push_back(floor2);
    ParkingLot *parkingLot = ParkingLot::getInstance(floorList);
    Ticket *ticket1 = parkingLot->getTicket(Sedan, "BR05E5676");
    Ticket *ticket2 = parkingLot->getTicket(Sedan, "BR05E7892");
    Ticket *ticket3 = parkingLot->getTicket(Sedan, "BR05E0007");
    Ticket *ticket4 = parkingLot->getTicket(Sedan, "BR05E5676");
    Ticket *ticket5 = parkingLot->getTicket(Sedan, "BR05E5676");
    Ticket *ticket6 = parkingLot->getTicket(Sedan, "BR05E5676");
    Ticket *ticket7 = parkingLot->getTicket(Sedan, "BR05E5676");
    Ticket *ticket8 = parkingLot->getTicket(Sedan, "BR05E5676");
    sleep_for(seconds(1));
    if(ticket1)
    bool payment1 = parkingLot->scanAndPay(ticket1);
    Ticket *ticket9 = parkingLot->getTicket(Sedan, "BR05E5676");
    sleep_for(seconds(1));
    if(ticket2)
    bool payment2 = parkingLot->scanAndPay(ticket2);
    sleep_for(seconds(1));
    if(ticket3)
    bool payment3 = parkingLot->scanAndPay(ticket3);
    if(ticket4)
    bool payment4 = parkingLot->scanAndPay(ticket4);
}
