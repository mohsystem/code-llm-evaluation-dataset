#include <iostream>
#include <set>
#include <string>
#include <random>
#include <ctime>

class Robot {
private:
    std::string name;
    static const std::string UPPER;
    static const std::string DIGITS;
    static const int LENGTH = 5;
    static std::mt19937 random;
    static std::set<std::string> existingNames;

    std::string generateName() {
        std::string name;
        do {
            name.clear();
            for (int i = 0; i < 2; i++) {
                name += UPPER[random() % UPPER.length()];
            }
            for (int i = 0; i < 3; i++) {
                name += DIGITS[random() % DIGITS.length()];
            }
        } while (existingNames.find(name) != existingNames.end());
        existingNames.insert(name);
        return name;
    }

public:
    Robot() {
        this->name = generateName();
    }
};

const std::string Robot::UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string Robot::DIGITS = "0123456789";
std::mt19937 Robot::random(time(0));
std::set<std::string> Robot::existingNames;

int main() {
    std::set<std::string> robots;
    while (robots.size() < 1000) {  // Create 1000 unique robots
        Robot robot;
        robots.insert(robot.name);
    }
    std::cout << (robots.size() == 1000) << std::endl;  // Should print: 1
    return 0;
}