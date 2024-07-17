#include <iostream>
#include <string>
#include <set>
#include <ctime>
#include <cstdlib>

class Robot {
private:
    std::string name;
    static std::set<std::string> usedNames;

public:
    Robot() {
        this->name = generateName();
    }

    std::string generateName() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        while (true) {
            std::string name;
            name += 'A' + std::rand() % 26;
            name += 'A' + std::rand() % 26;
            name += std::to_string(std::rand() % 900 + 100);
            if (usedNames.find(name) == usedNames.end()) {
                usedNames.insert(name);
                return name;
            }
        }
    }

    void reset() {
        this->name = generateName();
    }

    std::string getName() {
        return this->name;
    }
};

std::set<std::string> Robot::usedNames;

int main() {
    Robot robot;
    std::cout << robot.getName() << std::endl;
    robot.reset();
    std::cout << robot.getName() << std::endl;
    return 0;
}