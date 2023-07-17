#include <iostream>
#include <string>

using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

public:
    // Constructor to initialize the Train object with user input
    Train() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cout << "Enter Train Name: ";
        getline(cin, trainName);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    void displayTrainInfo() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << "====================" << endl;
    }
};

class RailwayReservationSystem {
private:
    Train* trains[10]; // Array of Train pointers to store train objects
    int numTrains;

public:
    RailwayReservationSystem() {
        numTrains = 0; // Initialize the number of trains to zero
    }

    void addTrain() {
        if (numTrains < 10) {
            trains[numTrains] = new Train(); // Create a new Train object and store its pointer
            numTrains++;
        } else {
            cout << "Maximum number of trains reached. Cannot add more trains." << endl;
        }
    }

    void displayAllTrains() {
        cout << "===== All Train Records =====" << endl;
        for (int i = 0; i < numTrains; ++i) {
            trains[i]->displayTrainInfo();
        }
    }

    void searchByTrainNumber(int number) {
        cout << "===== Train Record for Train Number " << number << " =====" << endl;
        bool found = false;
        for (int i = 0; i < numTrains; ++i) {
            if (trains[i]->getTrainNumber() == number) {
                trains[i]->displayTrainInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with Train Number " << number << " not found." << endl;
        }
    }

    ~RailwayReservationSystem() {
        // Delete dynamically allocated Train objects to avoid memory leaks
        for (int i = 0; i < numTrains; ++i) {
            delete trains[i];
        }
    }
};

int main() {
    RailwayReservationSystem reservationSystem;

    // Adding 3 train records initially
    for (int i = 0; i < 3; ++i) {
        cout << "Enter details for Train " << i + 1 << ":" << endl;
        reservationSystem.addTrain();
    }

    int choice;
     do {
        cout << "\n========= Railway Reservation System Menu =========" << endl;
        cout << "1. Add Train" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Train Number" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            reservationSystem.addTrain();
            break;
        case 2:
            reservationSystem.displayAllTrains();
            break;
        case 3:
            int trainNumber;
            cout << "Enter Train Number to search: ";
            cin >> trainNumber;
            reservationSystem.searchByTrainNumber(trainNumber);
            break;
        case 0:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

