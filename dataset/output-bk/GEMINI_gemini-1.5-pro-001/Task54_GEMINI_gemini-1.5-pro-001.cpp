#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

// Simulated authentication function (replace with actual database check)
bool authenticate(const string& username, const string& password) {
    return username == "user" && password == "password";
}

// Generate a random 6-digit OTP
int generateOTP() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(100000, 999999);
    return distribution(generator);
}

int main() {
    string username, password;
    int otp, enteredOtp;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Simulated user authentication
    if (authenticate(username, password)) {
        otp = generateOTP();
        cout << "One-Time Password: " << otp << endl;

        cout << "Enter OTP: ";
        cin >> enteredOtp;

        if (enteredOtp == otp) {
            cout << "Two-factor authentication successful. Access granted!" << endl;
        } else {
            cout << "Incorrect OTP. Access denied!" << endl;
        }
    } else {
        cout << "Invalid username or password. Access denied!" << endl;
    }

    return 0;
}