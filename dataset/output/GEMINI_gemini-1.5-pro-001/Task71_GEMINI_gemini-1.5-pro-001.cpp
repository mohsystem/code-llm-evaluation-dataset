#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide an argument to be converted to an integer." << endl;
        return 1;
    }

    try {
        string userInput = argv[1];
        int convertedInteger = stoi(userInput);
        cout << "Successfully converted '" << userInput << "' to integer: " << convertedInteger << endl;
    } catch (const std::invalid_argument& e) {
        cout << "Unable to convert '" << argv[1] << "' to an integer." << endl;
    } catch (const std::out_of_range& e) {
        cout << "Unable to convert '" << argv[1] << "' to an integer. Value out of range." << endl;
    }

    return 0;
}