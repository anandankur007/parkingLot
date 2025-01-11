#include "iostream"
#include <chrono>  // For time functions
#include <iomanip> // For formatting
#include <ctime>   // For time conversion
#include <sstream>  // for std::ostringstream
#include "string"
#include "ParkingType.h"
using namespace std;
using namespace std::chrono;

#ifndef TICKET_H
#define TICKET_H
class Ticket {
    public:
    time_point<high_resolution_clock> start_time;
    time_point<high_resolution_clock> end_time;
    string ticketId;
    ParkingType parkingType;
    Ticket(){}
    Ticket(string regNumber, ParkingType parkingType);
    void closeTicket();
};
#endif

// Ticket::Ticket(string regNumber, ParkingType parkingType) {
//     start_time = high_resolution_clock::now();
//     ticketId = regNumber + to_string(start_time.time_since_epoch().count());
//     parkingType = parkingType;
// }

// void Ticket::closeTicket() {
//     end_time = high_resolution_clock::now();
// }