#include <stdio.h>

typedef struct {
    int minutes;
} Clock;

Clock create_clock(int hour, int minute) {
    Clock clock;
    clock.minutes = ((minute + hour * 60) % (24 * 60) + (24 * 60)) % (24 * 60);
    return clock;
}

int get_hour(Clock clock) {
    return clock.minutes / 60;
}

int get_minute(Clock clock) {
    return clock.minutes % 60;
}

Clock add(Clock clock, int minutes) {
    return create_clock(0, (clock.minutes + minutes) % (24 * 60));
}

Clock subtract(Clock clock, int minutes) {
    return add(clock, -minutes);
}

void print_clock(Clock clock) {
    printf("%02d:%02d", get_hour(clock), get_minute(clock));
}

int is_equal(Clock clock1, Clock clock2) {
    return clock1.minutes == clock2.minutes;
}