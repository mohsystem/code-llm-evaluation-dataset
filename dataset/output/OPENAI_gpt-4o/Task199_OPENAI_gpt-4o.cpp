#include <iostream>
#include <iomanip>

class Clock {
private:
    int hour;
    int minute;

public:
    Clock(int h, int m) {
        int totalMinutes = (h * 60 + m) % (24 * 60);
        hour = totalMinutes / 60;
        minute = totalMinutes % 60;
    }

    Clock addMinutes(int minutes) const {
        return Clock(hour, minute + minutes);
    }

    bool operator==(const Clock& other) const {
        return hour == other.hour && minute == other.minute;
    }

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock) {
        os << std::setw(2) << std::setfill('0') << clock.hour << ":"
           << std::setw(2) << std::setfill('0') << clock.minute;
        return os;
    }
};

int main() {
    Clock clock1(10, 30);
    Clock clock2 = clock1.addMinutes(35);
    Clock clock3(11, 5);
    std::cout << clock2 << std::endl;  // 11:05
    std::cout << (clock2 == clock3) << std::endl;  // 1 (True)
    return 0;
}