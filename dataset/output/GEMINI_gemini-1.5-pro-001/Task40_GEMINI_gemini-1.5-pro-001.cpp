// CSRF protection typically involves server-side frameworks
// and isn't easily implemented in pure C++ without external libraries.
// This code focuses on the form structure and user input handling.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string username;

    cout << "<html><body>";
    cout << "<form method='post'>";
    // CSRF protection mechanisms would be added here
    cout << "<label for='username'>Username:</label>";
    cout << "<input type='text' id='username' name='username' />";
    cout << "<button type='submit'>Update Settings</button>";
    cout << "</form>";
    cout << "</body></html>";

    // Simulated form submission handling
    getline(cin, username); // Assuming input is sent via POST
    cout << "Username to update: " << username << endl;

    return 0;
}