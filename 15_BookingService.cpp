#pragma once
#include <iostream>
#include <vector>

#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "13_PriceCalculator.cpp"
#include "14_TicketPrinter.cpp"

using namespace std;

class BookingService {
private:
    PriceCalculator calculator;
    TicketPrinter printer;

public:
    Booking* bookTicket(
        Customer* customer,
        Show* show,
        vector<int> seatNumbers,
        Payment* payment
    ) {
        vector<ShowSeat*> selectedSeats;

        for (int number : seatNumbers) {
            ShowSeat* selectedSeat = nullptr;

            for (ShowSeat* seat : show->getShowSeats()) {
                if (seat->getSeatNumber() == number) {
                    selectedSeat = seat;
                    break;
                }
            }

            if (selectedSeat == nullptr) {
                cout << "Invalid seat number" << endl;
                return nullptr;
            }

            if (!selectedSeat->isAvailable()) {
                cout << "Seat already BOOKED" << endl;
                return nullptr;
            }

            selectedSeats.push_back(selectedSeat);
        }

        double total = calculator.calculate(selectedSeats);

        Booking* booking = new Booking(
            customer,
            show,
            selectedSeats,
            total
        );

        for (ShowSeat* seat : selectedSeats) {
            seat->bookSeat();
        }

        bool paid = payment->pay(total);

        if (!paid) {
            for (ShowSeat* seat : selectedSeats) {
                seat->cancelSeat();
            }

            delete booking;

            cout << "Payment Failed" << endl;
            cout << "Seats Released" << endl;

            return nullptr;
        }

        booking->confirm();
        printer.printTicket(booking);

        return booking;
    }

    void cancelBooking(Booking* booking) {
        if (booking == nullptr) {
            cout << "Invalid Booking" << endl;
            return;
        }

        for (ShowSeat* seat : booking->getSeats()) {
            seat->cancelSeat();
        }

        booking->cancel();

        cout << "Booking Cancelled" << endl;
        cout << "Seats are AVAILABLE again" << endl;
    }
};
