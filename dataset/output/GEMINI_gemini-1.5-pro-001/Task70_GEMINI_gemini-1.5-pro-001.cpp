#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Error: Please provide the file path as a command-line argument." << endl;
    return 1;
  }

  string filePath = argv[1];
  ifstream file(filePath);

  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      cout << line << endl;
    }
    file.close();
  } else {
    cerr << "Error: Unable to open file: " << filePath << endl;
    return 1;
  }

  return 0;
}