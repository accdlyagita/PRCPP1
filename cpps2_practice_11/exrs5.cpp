#include <iostream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved) : id(id), capacity(capacity), reserved(reserved) {}

void FlightBooking::printStatus() {
    double percentage = static_cast<double>(reserved) / capacity * 100.0;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats reserved" << endl;
}

int main() {
    int reserved = 0,
        capacity = 0;
    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;
    FlightBooking booking(1, capacity, reserved);
    booking.printStatus();
    return 0;
}
