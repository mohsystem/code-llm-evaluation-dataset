#include <iostream>
#include <string>
#include <random>
#include <unordered_set>

class Robot {
private:
    std::string name;
    static std::unordered_set<std::string> usedNames;
    static std::random_device rd;
    static std::mt19937 generator;

    std::string generateUniqueName() {
        std::uniform_int_distribution<> letterDist(0, 25);
        std::uniform_int_distribution<> digitDist(0, 9);
        std::string newName;

        do {
            newName = "";
            for (int i = 0; i < 2; ++i) {
                newName += 'A' + letterDist(generator);
            }
            for (int i = 0; i < 3; ++i) {
                newName += '0' + digitDist(generator);
            }
        } while (usedNames.count(newName));

        usedNames.insert(newName);
        return newName;
    }

public:
    Robot() {
        name = generateUniqueName();
    }

    void reset() {
        usedNames.erase(name);
        name = generateUniqueName();
    }

    std::string getName() const {
        return name;
    }
};

std::unordered_set<std::string> Robot::usedNames;
std::random_device Robot::rd;
std::mt19937 Robot::generator(Robot::rd());