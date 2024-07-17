#include <iostream>
#include <iomanip>

class Clock {
private:
    int minutes;

public:
    Clock(int hours, int minutes) {
        this->minutes = (hours * 60 + minutes) % (24 * 60);
    }

    bool operator==(const Clock& other) const {
        return this->minutes == other.minutes;
    }

    Clock operator+(int minutes) const {
        return Clock(0, this->minutes + minutes);
    }

    Clock operator-(int minutes) const {
        return Clock(0, this->minutes - minutes);
    }

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock) {
        int hours = clock.minutes / 60;
        int minutes = clock.minutes % 60;
        os << std::setfill('0') << std::setw(2) << hours << ":" << std::setw(2) << minutes;
        return os;
    }
};