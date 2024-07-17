#include <iostream>
#include <string>

using namespace std;

int main() {
  string userInput;

  cout << "Enter some text: ";
  getline(cin, userInput);

  cout << "<!DOCTYPE html>
";
  cout << "<html>
";
  cout << "<head><title>User Input</title></head>
";
  cout << "<body>
";
  cout << "<h1>You entered: " << userInput << "</h1>
";
  cout << "</body>
";
  cout << "</html>
";

  return 0;
}