#pragma once
#include <iostream>
#include <vector>
#include "05_ShowSeat.cpp"
using namespace std;

class PriceCalculator {
public:
    double calculate(ShowSeat* seat) {
        return seat->getSeat()->getPrice();
    }

    double calculate(vector<ShowSeat*>& seats) {
        double total = 0;

        for (ShowSeat* seat : seats)
            total += calculate(seat);

        return total;
    }
};
