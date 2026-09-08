#include <iostream>
#include <vector>
#include <string>

#include "04_Cinema.cpp"
#include "15_BookingService.cpp"
#include "10_UpiPayment.cpp"
#include "11_CardPayment.cpp"
#include "12_CashPayment.cpp"

using namespace std;

void showSeats(Show* show) {

    cout << endl;
    cout << "========== SEATS ==========" << endl;

    for (ShowSeat* seat : show->getShowSeats()) {

        cout << "Seat "
             << seat->getSeatNumber();

        if (seat->isAvailable()) {
            cout << " - AVAILABLE";
        }
        else {
            cout << " - BOOKED";
        }

        cout << endl;
    }

    cout << "===========================" << endl;
}

int main() {

    Cinema cinema("PVR Cinema");

    Movie movie(
        "Avengers Endgame",
        "English",
        181
    );

    vector<Screen>& screens = cinema.getScreens();

    Screen& screen = screens[0];

    Show show(
        &movie,
        &screen,
        "06:30 PM"
    );

    string customerName;
    string phone;

    cout << "Enter Customer Name: ";
    cin >> customerName;

    cout << "Enter Phone Number: ";
    cin >> phone;

    Customer customer(
        customerName,
        phone
    );

    BookingService service;

    Booking* booking = nullptr;

    int choice;

    do {

        cout << endl;
        cout << "===== MOVIE TICKET BOOKING =====" << endl;

        cout << "1. Show Movie" << endl;
        cout << "2. Show Seats" << endl;
        cout << "3. Book Ticket" << endl;
        cout << "4. Cancel Booking" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {

            cout << endl;

            cout << "Movie: "
                 << movie.getTitle()
                 << endl;

            cout << "Language: "
                 << movie.getLanguage()
                 << endl;

            cout << "Duration: "
                 << movie.getDuration()
                 << " minutes"
                 << endl;

            cout << "Show Time: "
                 << show.getTime()
                 << endl;
        }

        else if (choice == 2) {

            showSeats(&show);
        }

        else if (choice == 3) {

            int count;

            cout << "Enter number of seats: ";
            cin >> count;

            if (count <= 0) {

                cout << "Invalid number of seats."
                     << endl;

                continue;
            }

            vector<int> seatNumbers;

            for (int i = 0; i < count; i++) {

                int number;

                cout << "Enter seat number: ";
                cin >> number;

                seatNumbers.push_back(number);
            }

            int paymentChoice;

            cout << endl;
            cout << "1. UPI" << endl;
            cout << "2. Card" << endl;
            cout << "3. Cash" << endl;

            cout << "Enter payment method: ";
            cin >> paymentChoice;

            if (paymentChoice == 1) {

                UpiPayment payment;

                booking = service.bookTicket(
                    &customer,
                    &show,
                    seatNumbers,
                    &payment
                );
            }

            else if (paymentChoice == 2) {

                CardPayment payment;

                booking = service.bookTicket(
                    &customer,
                    &show,
                    seatNumbers,
                    &payment
                );
            }

            else if (paymentChoice == 3) {

                CashPayment payment;

                booking = service.bookTicket(
                    &customer,
                    &show,
                    seatNumbers,
                    &payment
                );
            }

            else {

                cout << "Invalid payment method."
                     << endl;
            }
        }

        else if (choice == 4) {

            service.cancelBooking(booking);
        }

        else if (choice == 5) {

            cout << "Thank you for using the system."
                 << endl;
        }

        else {

            cout << "Invalid choice."
                 << endl;
        }

    } while (choice != 5);

    return 0;
}
