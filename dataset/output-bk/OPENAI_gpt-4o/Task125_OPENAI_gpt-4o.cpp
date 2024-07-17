#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> resources;
    resources["resource1"] = "Access to Resource 1";
    resources["resource2"] = "Access to Resource 2";

    string userInput;
    cout << "Enter your resource: ";
    cin >> userInput;

    if (resources.find(userInput) != resources.end()) {
        cout << resources[userInput] << endl;
    } else {
        cout << "Resource not found" << endl;
    }

    return 0;
}