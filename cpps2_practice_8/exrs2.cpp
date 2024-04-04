#include <string>
#include <iostream>
using namespace std;

int main() {
    cout << "Enter your password: "; 
    string password;
    getline(cin, password);
    

    bool validLength = password.length() >= 8;
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (char ch : password) {
        
        if (isupper(ch)) {
            hasUpperCase = true;
        } else if (islower(ch)) {
            hasLowerCase = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else if (!isalnum(ch)) {
            hasSpecialChar = true;
        }
         
    }

    if (validLength && hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
        cout << "The password is valid" << endl;
    } else {
        if (!validLength) {
            cout << "The password must be 8 characters long" << endl;
        }
        if (!hasUpperCase) {
            cout << "The password must have at least one upper case letter" << endl;
        }
        if (!hasLowerCase) {
            cout << "The password must have at least one lower case letter" << endl;
        }
        if (!hasDigit) {
            cout << "The password must have at least one digit" << endl;
        }
        if (!hasSpecialChar) {
            cout << "The password must have at least one special character" << endl;
        }
    }

    return 0;
}
