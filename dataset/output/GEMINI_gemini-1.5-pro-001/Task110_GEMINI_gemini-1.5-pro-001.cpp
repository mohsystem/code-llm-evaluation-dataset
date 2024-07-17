#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string url;

    cout << "Enter a URL to validate: ";
    getline(cin, url);

    // Regular expression for URL validation
    regex urlRegex("^(http|https)://([a-z0-9]+(-[a-z0-9]+)*\\.)+[a-z]{2,6}(:[0-9]+)?(/.*)?$");

    if (regex_match(url, urlRegex)) {
        cout << url << " is a valid URL." << endl;
    } else {
        cout << url << " is not a valid URL." << endl;
    }

    return 0;
}