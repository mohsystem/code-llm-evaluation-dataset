#include <iostream>
#include <string>
#include <set>
#include <random>

class Robot {
private:
    std::string name;
    static std::set<std::string> usedNames;

public:
    Robot() {
        this->name = generateName();
    }

    std::string generateName() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(0, 25);
        while (true) {
            std::string name;
            name += 'A' + dist(mt);
            name += 'A' + dist(mt);
            name += std::to_string(mt() % 1000);
            if (usedNames.insert(name).second) {
                return name;
            }
        }
    }

    void reset() {
        this->name = generateName();
    }
};

std::set<std::string> Robot::usedNames;