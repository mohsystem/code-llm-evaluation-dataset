#include <iostream>
#include <set>
#include <string>
#include <random>
#include <chrono>

class Robot {
private:
    std::string name;
    static std::set<std::string> existingNames;
    static const std::string UPPERCASE_LETTERS;
    static const std::string DIGITS;
    static std::mt19937 RANDOM;

    std::string generateName() {
        std::string name;
        do {
            name = randomString(UPPERCASE_LETTERS, 2) + randomString(DIGITS, 3);
        } while (existingNames.find(name) != existingNames.end());
        existingNames.insert(name);
        return name;
    }

    std::string randomString(const std::string& characters, int length) {
        std::uniform_int_distribution<int> dist(0, characters.size() - 1);
        std::string result;
        for (int i = 0; i < length; i++) {
            result += characters[dist(RANDOM)];
        }
        return result;
    }

public:
    Robot() {
        this->name = generateName();
    }
};

std::set<std::string> Robot::existingNames;
const std::string Robot::UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string Robot::DIGITS = "0123456789";
std::mt19937 Robot::RANDOM(std::chrono::system_clock::now().time_since_epoch().count());

// Test
int main() {
    std::set<std::string> names;
    for (int i = 0; i < 1000; i++) {
        names.insert(Robot().name);
    }
    if (names.size() != 1000) {
        throw std::runtime_error("Names are not unique");
    }
    return 0;
}