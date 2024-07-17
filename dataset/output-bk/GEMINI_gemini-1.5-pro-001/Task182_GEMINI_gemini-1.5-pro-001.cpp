#include <iostream>
#include <string>
#include <regex>

using namespace std;

string cleanPhoneNumber(string phoneNumber) {
    phoneNumber = regex_replace(phoneNumber, regex("[^0-9]"), "");
    if (phoneNumber.length() == 11 && phoneNumber[0] == '1') {
        phoneNumber = phoneNumber.substr(1);
    }
    return phoneNumber;
}

int main() {
    string phoneNumbers[] = {
            "+1 (613)-995-0253",
            "613-995-0253",
            "1 613 995 0253",
            "613.995.0253"
    };

    for (string phoneNumber : phoneNumbers) {
        string cleanedNumber = cleanPhoneNumber(phoneNumber);
        cout << cleanedNumber << endl;
    }

    return 0;
}