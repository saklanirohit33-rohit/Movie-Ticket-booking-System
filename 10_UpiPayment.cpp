#pragma once
#include <iostream>
#include "09_Payment.cpp"
using namespace std;

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI Payment: Rs. " << amount << endl;
        cout << "Payment Successful" << endl;
        return true;
    }
};
