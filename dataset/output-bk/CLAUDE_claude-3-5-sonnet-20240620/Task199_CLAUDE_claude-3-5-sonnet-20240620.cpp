
#include <iostream>
#include <iomanip>

class Clock {
private:
    int minutes;

public:
    Clock(int hours, int minutes) : minutes((hours * 60 + minutes) % 1440) {}

    std::string toString() const {
        int hours = minutes / 60;
        int mins = minutes % 60;
        std::ostringstream oss;
        oss << std::setfill(\'0\') << std::setw(2) << hours << ":"
            << std::setfill(\'0\') << std::setw(2) << mins;
        return oss.str();
    }

    bool operator==(const Clock& other) const {
        return minutes == other.minutes;
    }

    Clock& add(int mins) {
        minutes = (minutes + mins) % 1440;
        return *this;
    }

    Clock& subtract(int mins) {
        minutes = (minutes - mins + 1440) % 1440;
        return *this;
    }
};

int main() {
    Clock clock1(10, 30);
    Clock clock2(10, 30);
    std::cout << clock1.toString() << std::endl;  // 10:30
    std::cout << (clock1 == clock2) << std::endl;  // 1
    clock1.add(30);
    std::cout << clock1.toString() << std::endl;  // 11:00
    clock1.subtract(60);
    std::cout << clock1.toString() << std::endl;  // 10:00
    return 0;
}
