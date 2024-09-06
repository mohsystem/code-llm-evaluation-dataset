#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool isValidUrl(const string& url) {
  regex urlRegex(
      R"(^(?:http|ftp)s?://(?:(?:[A-Z0-9](?:[A-Z0-9-]{0,61}[A-Z0-9])?\.)+(?:[A-Z]{2,6}\.?|[A-Z0-9-]{2,}\.?)|localhost|\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})(?::\d+)?(?:/?|[/?]\S+)$)",
      regex_constants::icase);
  return regex_match(url, urlRegex);
}

int main() {
  string url;
  cout << "Enter a URL: ";
  getline(cin, url);

  if (isValidUrl(url)) {
    cout << "Valid URL" << endl;
  } else {
    cout << "Invalid URL" << endl;
  }

  return 0;
}