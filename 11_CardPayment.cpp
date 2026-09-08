#pragma once
#include <iostream>
#include "09_Payment.cpp"
using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card Payment: Rs. " << amount << endl;
        cout << "Payment Successful" << endl;
        return true;
    }
};
