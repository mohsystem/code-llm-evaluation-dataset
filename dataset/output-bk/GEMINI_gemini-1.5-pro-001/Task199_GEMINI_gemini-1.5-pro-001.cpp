#include <iostream>
#include <iomanip>

class Clock {
private:
    int minutes;

public:
    Clock(int hour = 0, int minute = 0) : minutes(((minute + hour * 60) % (24 * 60) + (24 * 60)) % (24 * 60)) {}

    int getHour() const {
        return minutes / 60;
    }

    int getMinute() const {
        return minutes % 60;
    }

    Clock add(int minutes) const {
        return Clock(0, (this->minutes + minutes) % (24 * 60));
    }

    Clock subtract(int minutes) const {
        return add(-minutes);
    }

    friend std::ostream& operator<<(std::ostream& os, const Clock& clock);

    bool operator==(const Clock& other) const {
        return minutes == other.minutes;
    }
};

std::ostream& operator<<(std::ostream& os, const Clock& clock) {
    os << std::setfill('0') << std::setw(2) << clock.getHour() << ":"
       << std::setfill('0') << std::setw(2) << clock.getMinute();
    return os;
}