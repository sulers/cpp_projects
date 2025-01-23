#include <iostream>
#include <iomanip>  // For formatting output
#include <cstdlib>  // For generating receipt number
#include <ctime>    // For random seed

using namespace std;

// Structure to hold bus details
struct Bus {
    string destination;
    string stops[5];
    float fares[5];  // Different fares for each stop
};

// Function to display available buses
void showBuses(Bus buses[], int size) {
    cout << "\n🚌 Welcome to Express Travel Agency!\n";
    cout << "Choose your destination:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << buses[i].destination << endl;
    }
}

// Function to display stops and fare for a selected bus
void showStops(Bus bus) {
    cout << "\n🚏 Stops for " << bus.destination << ":\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << bus.stops[i] << " - $" << fixed << setprecision(2) << bus.fares[i] << endl;
    }
}

// Function to process payment
void processPayment(string customerName, Bus bus, int stopIndex) {
    float amountPaid, change;
    float fare = bus.fares[stopIndex];

    cout << "\n💰 The fare to " << bus.stops[stopIndex] << " is $" << fare << ". Enter amount to pay: ";
    cin >> amountPaid;

    while (amountPaid < fare) {
        cout << "❌ Insufficient amount. Please enter at least $" << fare << ": ";
        cin >> amountPaid;
    }

    change = amountPaid - fare;
    if (change > 0) {
        cout << "✅ Payment successful! Your change is $" << fixed << setprecision(2) << change << endl;
    } else {
        cout << "✅ Payment successful! No change needed.\n";
    }

    // Generate a random receipt number
    srand(time(0));
    int receiptNumber = rand() % 9000 + 1000; // Random number between 1000-9999

    // Display receipt
    cout << "\n🧾 TRAVEL RECEIPT\n";
    cout << "--------------------------------\n";
    cout << "🚌 Express Travel Agency\n";
    cout << "👤 Customer: " << customerName << endl;
    cout << "🎯 Destination: " << bus.destination << endl;
    cout << "🚏 Stop: " << bus.stops[stopIndex] << endl;
    cout << "🆔 Receipt No: #" << receiptNumber << endl;
    cout << "💰 Paid: $" << fixed << setprecision(2) << amountPaid << endl;
    cout << "--------------------------------\n";
}

int main() {
    // Travel agency buses with actual stop names
    Bus buses[3] = {
        {"New York", {"Times Square", "Central Park", "Brooklyn Bridge", "Wall Street", "JFK Airport"}, {5.0, 7.5, 10.0, 12.5, 15.0}},
        {"Los Angeles", {"Hollywood", "Beverly Hills", "Downtown LA", "Santa Monica", "LAX Airport"}, {6.0, 8.0, 11.0, 13.0, 16.0}},
        {"Chicago", {"Navy Pier", "Millennium Park", "Willis Tower", "The Loop", "O'Hare Airport"}, {4.5, 6.5, 9.0, 11.5, 14.0}}
    };

    string customerName;
    int busChoice, stopChoice;

    cout << "Enter your name: ";
    getline(cin, customerName);

    // Select bus
    showBuses(buses, 3);
    cout << "\nEnter your choice (1-3): ";
    cin >> busChoice;
    
    while (busChoice < 1 || busChoice > 3) {
        cout << "❌ Invalid choice. Please select a valid bus (1-3): ";
        cin >> busChoice;
    }

    Bus selectedBus = buses[busChoice - 1];

    // Select stop
    showStops(selectedBus);
    cout << "\nEnter stop number (1-5): ";
    cin >> stopChoice;

    while (stopChoice < 1 || stopChoice > 5) {
        cout << "❌ Invalid choice. Please select a valid stop (1-5): ";
        cin >> stopChoice;
    }

    // Process payment and print receipt
    processPayment(customerName, selectedBus, stopChoice - 1);

    cout << "\n✅ Thank you for using Express Travel Agency. Have a safe trip!\n";

    return 0;
}
