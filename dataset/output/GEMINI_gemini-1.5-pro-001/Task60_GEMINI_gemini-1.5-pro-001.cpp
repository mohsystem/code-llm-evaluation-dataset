#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string expandedForm(int num) {
    string str = "";
    int len = to_string(num).length();
    for (int i = 0; i < len; i++) {
        int digit = (int)(num / pow(10, len - i - 1)) % 10;
        if (digit != 0) {
            str += to_string((int)(digit * pow(10, len - i - 1)));
            if (i != len - 1) {
                str += " + ";
            }
        }
    }
    return str;
}

int main() {
    cout << expandedForm(12) << endl;
    cout << expandedForm(42) << endl;
    cout << expandedForm(70304) << endl;
    return 0;
}