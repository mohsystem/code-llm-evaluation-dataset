
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void print_html_header() {
    cout << "Content-Type: text/html\
\
";
    cout << "<html><head><title>Form Results</title></head><body>";
}

void print_html_footer() {
    cout << "</body></html>";
}

int main() {
    string name, email;

    print_html_header();

    string request_method = getenv("REQUEST_METHOD") ? getenv("REQUEST_METHOD") : "";
    
    if (request_method == "POST") {
        int content_length = atoi(getenv("CONTENT_LENGTH"));
        char* input = new char[content_length + 1];
        cin.read(input, content_length);
        input[content_length] = \'\\0\';

        string data(input);
        delete[] input;

        size_t pos = data.find("name=");
        if (pos != string::npos) {
            name = data.substr(pos + 5, data.find("&", pos) - pos - 5);
        }

        pos = data.find("email=");
        if (pos != string::npos) {
            email = data.substr(pos + 6);
        }

        cout << "<h2>Submitted Information:</h2>";
        cout << "<p>Name: " << name << "</p>";
        cout << "<p>Email: " << email << "</p>";
    } else {
        cout << "<h2>User Input Form</h2>";
        cout << "<form method=\'post\'>";
        cout << "Name: <input type=\'text\' name=\'name\'><br>";
        cout << "Email: <input type=\'text\' name=\'email\'><br>";
        cout << "<input type=\'submit\' value=\'Submit\'>";
        cout << "</form>";
    }

    print_html_footer();
    return 0;
}
