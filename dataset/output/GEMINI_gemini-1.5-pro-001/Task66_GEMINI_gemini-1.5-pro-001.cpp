#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <memory>

using namespace std;

int main() {
  string command;
  cout << "Enter a bash command: ";
  getline(cin, command);

  try {
    // Execute the command and capture output
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
      throw runtime_error("popen() failed!");
    }
    char buffer[128];
    string result;
    while (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
      result += buffer;
    }

    cout << result;

  } catch (const runtime_error& e) {
    cerr << "Error executing command: " << e.what() << endl;
    return 1; // Indicate an error occurred
  }

  return 0; // Indicate successful execution
}