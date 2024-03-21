#include <iostream>
#include <vector>
using namespace std;

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; 
    } else {
        return false; 
    }
}

int monthLength(int year, int month) {
    vector<int> daysInMonth = {31, 28 + isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month - 1];
}

int main() {
    int year, month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month!" << endl;
        return 1;
    }

    cout << "Number of days in the specified month: " << monthLength(year, month) << endl;

    return 0;
}
