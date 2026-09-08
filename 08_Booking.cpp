#pragma once
#include <iostream>
#include <vector>
#include "07_Customer.cpp"
#include "06_Show.cpp"
using namespace std;

class Booking {
private:
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double bookingAmount;
    bool confirmed;

    static int nextBookingId;

public:
    Booking(Customer* customer, Show* show,
            vector<ShowSeat*> seats, double bookingAmount) {
        this->bookingId = nextBookingId++;
        this->customer = customer;
        this->show = show;
        this->seats = seats;
        this->bookingAmount = bookingAmount;
        confirmed = false;
    }

    int getBookingId() {
        return bookingId;
    }

    Customer* getCustomer() {
        return customer;
    }

    Show* getShow() {
        return show;
    }

    vector<ShowSeat*>& getSeats() {
        return seats;
    }

    double getBookingAmount() {
        return bookingAmount;
    }

    void confirm() {
        confirmed = true;
    }

    void cancel() {
        confirmed = false;
    }

    bool isConfirmed() {
        return confirmed;
    }
};

int Booking::nextBookingId = 1001;
