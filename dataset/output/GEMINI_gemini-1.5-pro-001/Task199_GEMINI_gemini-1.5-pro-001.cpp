#include <iostream>
#include <iomanip>

class Clock {
private:
    int minutes;

public:
    Clock(int hour = 0, int minute = 0) : minutes((minute + hour * 60) % (24 * 60)) {
        if (minutes < 0) {
            minutes += 24 * 60;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Clock& c) {
        os << std::setw(2) << std::setfill('0') << c.minutes / 60 << ":"
           << std::setw(2) << std::setfill('0') << c.minutes % 60;
        return os;
    }

    bool operator==(const Clock& other) const {
        return minutes == other.minutes;
    }

    Clock operator+(int addedMinutes) const {
        return Clock(0, minutes + addedMinutes);
    }

    Clock operator-(int subtractedMinutes) const {
        return Clock(0, minutes - subtractedMinutes);
    }
};