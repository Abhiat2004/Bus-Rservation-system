#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger {
public:
    string name, age, gender, mobileNumber;
};

class Bus {
public:
    string name, number, startingPoint, endingPoint, timing;
    int seatsAvailable;
    double seatCost;

    void displayDetails() const {
        cout << "Bus Name: " << name << endl;
        cout << "Bus Number: " << number << endl;
        cout << "Starting Point: " << startingPoint << endl;
        cout << "Ending Point: " << endingPoint << endl;
        cout << "Bus Timing at Starting Position: " << timing << endl;
        cout << "Number of seats Available in Bus: " << seatsAvailable << endl;
        cout << "Cost of each Seat: " << seatCost << endl << endl;
    }
};


class Account {
public:
    string name, age, email, mobileNumber, username, password, confirmPassword;
};

class Booking {
public:
    int busIndex;
    vector<Passenger> passengers;

    void bookTicket(const Bus& bus) {
        busIndex = -1;
        passengers.clear();

        cout << "Select a Bus: ";
        cin >> busIndex;
        cout << "Enter number of Passengers: ";
        int totalSeats;
        cin >> totalSeats;

        for (int i = 0; i < totalSeats; ++i) {
            Passenger passenger;
            cout << "Enter Name of Passenger " << i + 1 << ": ";
            cin >> passenger.name;
            cout << "Enter Age of " << passenger.name << ": ";
            cin >> passenger.age;
            cout << "Enter Gender of " << passenger.name << ": ";
            cin >> passenger.gender;
            cout << "Enter Mobile number of " << passenger.name << ": ";
            cin >> passenger.mobileNumber;
            cout << endl;
            passengers.push_back(passenger);
        }
    }
};

class Ticket {
public:
    void showTicket(const Bus& bus, const Booking& booking) {
        cout << "Bus Name: " << bus.name << endl;
        cout << "Bus Number: " << bus.number << endl;
        cout << "Bus Starting Point: " << bus.startingPoint << endl;
        cout << "Bus Ending Point: " << bus.endingPoint << endl;
        cout << "Bus Timing at Starting Position: " << bus.timing << endl;
        cout << "Number of seats booked: " << booking.passengers.size() << endl;
        cout << "Total Amount: " << bus.seatCost * booking.passengers.size() << endl << endl;

        cout << "Details of Passengers:" << endl;
        for (int i = 0; i < booking.passengers.size(); ++i) {
            const Passenger& passenger = booking.passengers[i];
            cout << "Name of the Passenger " << i + 1 << ": " << passenger.name << endl;
            cout << "Age of " << passenger.name << ": " << passenger.age << endl;
            cout << "Gender of " << passenger.name << ": " << passenger.gender << endl;
            cout << "Mobile number of " << passenger.name << ": " << passenger.mobileNumber << endl << endl;
        }
    }
};

class BusPortal {
private:
    vector<Account> accounts;
    vector<Bus> buses;
    vector<Booking> bookings;
    Ticket ticket;

public:
    void run() {
        int choice;
        do {
            cout << "Welcome to SRM BUS Portal" << endl;
            cout << "1. Admin Portal" << endl << "2. User Portal" << endl << "3. Exit" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    adminPortal();
                    break;
                case 2:
                    userPortal();
                    break;
                case 3:
                    cout << "Exiting the program" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 3);
    }

private:
    void adminPortal() {
        string adminName, adminPassword;

        cout << "Enter Admin Username: ";
        cin >> adminName;

        if (adminName == "srmadmin") {
            cout << "Enter Admin Password: ";
            cin >> adminPassword;

            if (adminPassword == "Admin22") {
                adminMenu();
            } else {
                cout << "Invalid Password" << endl;
            }
        } else {
            cout << "Invalid Username" << endl;
        }
    }

    void adminMenu() {
        int choice;
        do {
            cout << "Welcome to Admin Portal" << endl;
            cout << "1. Display Buses" << endl << "2. Install Bus" << endl << "3. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    displayBuses();
                    break;
                case 2:
                    installBus();
                    break;
                case 3:
                    cout << "Logging out from Admin Portal" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 3);
    }

    void displayBuses() {
        if (buses.empty()) {
            cout << "No Buses are Installed!" << endl;
        } else {
            for (const auto& bus : buses) {
                bus.displayDetails();
            }
        }
    }

    void installBus() {
        Bus bus;
        cout << "Bus Name: ";
        cin >> bus.name;
        cout << "Bus Number: ";
        cin >> bus.number;
        cout << "Bus Starting Point: ";
        cin >> bus.startingPoint;
        cout << "Bus Ending Point: ";
        cin >> bus.endingPoint;
        cout << "Bus Timing at Starting Position: ";
        cin >> bus.timing;
        cout << "Total number of seats in Bus: ";
        cin >> bus.seatsAvailable;
        cout << "Cost of each Seat: ";
        cin >> bus.seatCost;

        buses.push_back(bus);
    }

    void userPortal() {
        int choice;
        do {
            cout << "1. Login" << endl << "2. Sign Up" << endl << "3. Exit" << endl;
            cout << "Enter your Choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    signUp();
                    break;
                case 3:
                    cout << "Exiting User Portal" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 3);
    }

    void login() {
        string username, password;

        cout << "Enter Username: ";
        cin >> username;

        for (const auto& account : accounts) {
            if (account.username == username) {
                cout << "Enter Password: ";
                cin >> password;

                if (account.password == password) {
                    userMenu(account);
                    return;
                } else {
                    cout << "Invalid Password" << endl;
                    return;
                }
            }
        }

        cout << "No Account found!" << endl;
    }

    void userMenu(const Account& account) {
        int choice;
        Booking booking;

        do {
            cout << "Welcome " << account.name << endl;
            cout << "1. Book Tickets" << endl << "2. Show my Ticket" << endl << "3. Display Buses" << endl << "4. Logout"
                 << endl;
            cout << "Enter your Choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    if (booking.passengers.empty()) {
                        booking.bookTicket(buses[booking.busIndex]);
                        bookings.push_back(booking);
                    } else {
                        cout << "Max Limit is Exceeded" << endl;
                    }
                    break;
                case 2:
                    if (!booking.passengers.empty()) {
                        ticket.showTicket(buses[booking.busIndex], booking);
                    } else {
                        cout << "No Tickets are Booked" << endl;
                    }
                    break;
                case 3:
                    displayBuses();
                    break;
                case 4:
                    cout << "Logging out" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 4);
    }

    void signUp() {
        Account account;
        cout << "Enter your Name: ";
        cin >> account.name;
        cout << "Enter your Age: ";
        cin >> account.age;
        cout << "Enter your E-mail: ";
        cin >> account.email;
        cout << "Enter your Mobile number: ";
        cin >> account.mobileNumber;
        cout << "Create your Username: ";
        cin >> account.username;

        string password, confirmPassword;
        do {
            cout << "Create your Password: ";
            cin >> password;
            cout << "Confirm your Password: ";
            cin >> confirmPassword;

            if (password != confirmPassword) {
                cout << "Passwords do not match. Please try again." << endl;
            }

        } while (password != confirmPassword);

        account.password = password;
        accounts.push_back(account);

        cout << "Account Created" << endl;
    }
};

int main() {
    BusPortal busPortal;
    busPortal.run();

    return 0;
}
