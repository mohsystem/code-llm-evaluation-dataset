#include <iostream>
#include <string>
#include <random>
#include <unordered_set>

using namespace std;

class Robot {
private:
    string name;
    static unordered_set<string> usedNames;

    string generateUniqueName() {
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<char> letterDistribution('A', 'Z');
        uniform_int_distribution<char> digitDistribution('0', '9');

        string newName;
        do {
            newName = "";
            for (int i = 0; i < 2; ++i) {
                newName += letterDistribution(generator);
            }
            for (int i = 0; i < 3; ++i) {
                newName += digitDistribution(generator);
            }
        } while (usedNames.find(newName) != usedNames.end());

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

    string getName() const {
        return name;
    }
};

unordered_set<string> Robot::usedNames;