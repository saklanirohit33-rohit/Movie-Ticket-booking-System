#pragma once
#include <iostream>
#include <vector>
#include "02_Seat.cpp"
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;

        for (int i = 1; i <= 10; i++) {
            if (i <= 4)
                seats.push_back(Seat(i, "Silver"));
            else if (i <= 7)
                seats.push_back(Seat(i, "Gold"));
            else
                seats.push_back(Seat(i, "Platinum"));
        }
    }

    int getScreenNumber() {
        return screenNumber;
    }

    vector<Seat>& getSeats() {
        return seats;
    }
};
