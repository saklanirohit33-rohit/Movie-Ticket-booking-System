#pragma once
#include <iostream>
using namespace std;

class Seat {
private:
    int number;
    string type;

public:
    Seat(int number, string type) {
        this->number = number;
        this->type = type;
    }

    int getNumber() {
        return number;
    }

    string getType() {
        return type;
    }

    double getPrice() {
        if (type == "Silver")
            return 150;

        if (type == "Gold")
            return 250;

        return 400;
    }
};
