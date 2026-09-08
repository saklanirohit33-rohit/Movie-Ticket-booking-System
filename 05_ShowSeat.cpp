#pragma once
#include <iostream>
#include "02_Seat.cpp"
using namespace std;

class ShowSeat {
private:
    Seat* seat;
    bool seatStatus;

public:
    ShowSeat(Seat* seat) {
        this->seat = seat;
        seatStatus = true;
    }

    int getSeatNumber() {
        return seat->getNumber();
    }

    Seat* getSeat() {
        return seat;
    }

    bool isAvailable() {
        return seatStatus;
    }

    bool bookSeat() {
        if (!seatStatus)
            return false;

        seatStatus = false;
        return true;
    }

    bool cancelSeat() {
        if (seatStatus)
            return false;

        seatStatus = true;
        return true;
    }
};
