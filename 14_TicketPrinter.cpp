#pragma once
#include <iostream>
#include "08_Booking.cpp"
using namespace std;

class TicketPrinter {
public:
    void printTicket(Booking* booking) {
        cout << endl;
        cout << "============ TICKET ============" << endl;
        cout << "Booking ID: " << booking->getBookingId() << endl;
        cout << "Customer: " << booking->getCustomer()->getName() << endl;
        cout << "Movie: " << booking->getShow()->getMovie()->getTitle() << endl;
        cout << "Screen: " << booking->getShow()->getScreen()->getScreenNumber() << endl;
        cout << "Time: " << booking->getShow()->getTime() << endl;

        cout << "Seats: ";

        for (ShowSeat* seat : booking->getSeats())
            cout << seat->getSeatNumber() << " ";

        cout << endl;
        cout << "Amount: Rs. " << booking->getBookingAmount() << endl;
        cout << "Status: CONFIRMED" << endl;
        cout << "================================" << endl;
    }
};
