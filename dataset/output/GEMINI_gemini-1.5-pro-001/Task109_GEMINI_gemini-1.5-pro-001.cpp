#include <iostream>
#include <regex>
using namespace std;

int main() {
    string email;
    cout << "Enter an email address: ";
    cin >> email;
    regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (regex_match(email, pattern)) {
        cout << "Valid email address" << endl;
    } else {
        cout << "Invalid email address" << endl;
    }
    return 0;
}