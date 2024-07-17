#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string username = "user";
    string password = "password";
    string inputUsername, inputPassword;
    int otp, inputOTP;

    cout << "Enter username:" << endl;
    cin >> inputUsername;
    cout << "Enter password:" << endl;
    cin >> inputPassword;

    if (inputUsername == username && inputPassword == password) {
        // Generate OTP
        srand(time(0));
        otp = rand() % 1000000;
        cout << "Generated OTP: " << setfill('0') << setw(6) << otp << endl;
        cout << "Enter OTP:" << endl;
        cin >> inputOTP;

        if (inputOTP == otp) {
            cout << "Login Successful" << endl;
        } else {
            cout << "Invalid OTP" << endl;
        }
    } else {
        cout << "Invalid username or password" << endl;
    }

    return 0;
}