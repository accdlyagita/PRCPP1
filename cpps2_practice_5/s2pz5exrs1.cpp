#include <iostream>
#include <ctime>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0) {
            return true;
        }
    }
    return false;
}

int monthLength(int year, int month) {
    switch (month) {
        case 2:
            return 28 + isLeap(year);
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

Date today() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    Date currentDate;
    currentDate.year = 1900 + ltm->tm_year;
    currentDate.month = 1 + ltm->tm_mon;
    currentDate.day = ltm->tm_mday;

    return currentDate;
}

int main() {
    Date birthday = {2005, 10, 29}; 
    Date currentDate = today(); 

    int daysPassed = 0;
    for (int year = birthday.year; year < currentDate.year; ++year) {
        for (int month = 1; month <= 12; ++month) {
            daysPassed += monthLength(year, month);
        }
    }
    for (int month = 1; month < birthday.month; ++month) {
        daysPassed -= monthLength(birthday.year, month);
    }
    daysPassed += currentDate.day - birthday.day;

    cout << "Days passed since your birthday: " << daysPassed << endl;

    return 0;
}
