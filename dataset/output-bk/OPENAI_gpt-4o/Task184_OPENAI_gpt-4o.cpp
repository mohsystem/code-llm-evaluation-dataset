#include <iostream>
#include <string>
#include <set>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>

class Robot {
private:
    std::string name;
    static std::set<std::string> usedNames;

    std::string generateRandomName() {
        std::string letters;
        for (int i = 0; i < 2; ++i) {
            letters += ('A' + std::rand() % 26);
        }
        int numbers = std::rand() % 1000;
        std::ostringstream oss;
        oss << letters << std::setw(3) << std::setfill('0') << numbers;
        return oss.str();
    }

    std::string generateUniqueName() {
        std::string name;
        do {
            name = generateRandomName();
        } while (usedNames.find(name) != usedNames.end());
        usedNames.insert(name);
        return name;
    }

public:
    Robot() {
        std::srand(std::time(0));
        reset();
    }

    void reset() {
        name = generateUniqueName();
    }

    std::string getName() const {
        return name;
    }
};

std::set<std::string> Robot::usedNames;

int main() {
    Robot r1;
    std::cout << r1.getName() << std::endl;
    r1.reset();
    std::cout << r1.getName() << std::endl;
    return 0;
}