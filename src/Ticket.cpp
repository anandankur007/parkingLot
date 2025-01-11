#include "Ticket.h"

Ticket::Ticket(string regNumber, ParkingType parkingType) {
    start_time = high_resolution_clock::now();
    //ticketId = regNumber + to_string(start_time.time_since_epoch().count());
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* localTime = std::localtime(&currentTime);

    // Use stringstream to format date and time as a string
    std::ostringstream dateTimeStream;
    dateTimeStream << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    ticketId = regNumber + " " + dateTimeStream.str();
    cout<<"This is you ticket id: "<<ticketId<<"\n";
}

void Ticket::closeTicket() {
    end_time = high_resolution_clock::now();
}