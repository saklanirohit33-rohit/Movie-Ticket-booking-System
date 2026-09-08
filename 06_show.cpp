#pragma once
#include <iostream>
#include <vector>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
#include "05_ShowSeat.cpp"
using namespace std;

class Show {
private:
    Movie* movie;
    Screen* screen;
    string time;
    vector<ShowSeat*> showSeats;

public:
    Show(Movie* movie, Screen* screen, string time) {
        this->movie = movie;
        this->screen = screen;
        this->time = time;
    }

    void addShowSeat(ShowSeat* seat) {
        showSeats.push_back(seat);
    }

    Movie* getMovie() {
        return movie;
    }

    Screen* getScreen() {
        return screen;
    }

    string getTime() {
        return time;
    }

    vector<ShowSeat*>& getShowSeats() {
        return showSeats;
    }
};
