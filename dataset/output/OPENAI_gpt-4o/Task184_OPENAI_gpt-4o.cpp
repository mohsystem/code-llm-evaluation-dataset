#include <iostream>
#include <unordered_set>
#include <string>
#include <random>

class Robot {
    private:
        static std::unordered_set<std::string> usedNames;
        static std::mt19937 gen;
        std::string name;

        std::string generateRandomName() {
            std::string result(5, '0');
            std::uniform_int_distribution<> letterDist(0, 25);
            std::uniform_int_distribution<> digitDist(0, 9);
            result[0] = 'A' + letterDist(gen);
            result[1] = 'A' + letterDist(gen);
            result[2] = '0' + digitDist(gen);
            result[3] = '0' + digitDist(gen);
            result[4] = '0' + digitDist(gen);
            return result;
        }

        std::string generateName() {
            std::string newName;
            do {
                newName = generateRandomName();
            } while (usedNames.find(newName) != usedNames.end());
            usedNames.insert(newName);
            return newName;
        }

    public:
        Robot() {
            name = generateName();
        }

        void reset() {
            name = generateName();
        }

        std::string getName() {
            return name;
        }
};

std::unordered_set<std::string> Robot::usedNames;
std::mt19937 Robot::gen(std::random_device{}());

int main() {
    Robot robot;
    std::cout << robot.getName() << std::endl;
    robot.reset();
    std::cout << robot.getName() << std::endl;
    return 0;
}