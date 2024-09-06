
#include <iostream>
#include <string>
#include <set>
#include <random>
#include <algorithm>

class Robot {
private:
    static std::set<std::string> used_names;
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dis_letter;
    static std::uniform_int_distribution<> dis_digit;

    std::string name;

    std::string generate_name() {
        std::string new_name;
        do {
            new_name = "";
            for (int i = 0; i < 2; ++i) {
                new_name += 'A' + dis_letter(gen);
            }
            for (int i = 0; i < 3; ++i) {
                new_name += '0' + dis_digit(gen);
            }
        } while (used_names.find(new_name) != used_names.end());
        used_names.insert(new_name);
        return new_name;
    }

public:
    Robot() {
        reset();
    }

    void reset() {
        name = generate_name();
    }

    std::string get_name() const {
        return name;
    }
};

std::set<std::string> Robot::used_names;
std::random_device Robot::rd;
std::mt19937 Robot::gen(Robot::rd());
std::uniform_int_distribution<> Robot::dis_letter(0, 25);
std::uniform_int_distribution<> Robot::dis_digit(0, 9);

int main() {
    Robot robot;
    std::cout << robot.get_name() << std::endl;
    robot.reset();
    std::cout << robot.get_name() << std::endl;
    return 0;
}
