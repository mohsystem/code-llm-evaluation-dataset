// C++
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generate_random_string(int length) {
    std::string str;
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        str += characters[rand() % characters.length()];
    }
    return str;
}

int main() {
    srand(time(0));
    std::string randomString = generate_random_string(10);
    std::ofstream tempFile;
    tempFile.open("temp.txt");
    tempFile << randomString;
    tempFile.close();
    std::cout << "temp.txt" << std::endl;
    return 0;
}