#include <stdio.h>

typedef struct {
    int minutes;
} Clock;

Clock create_clock(int hour, int minute) {
    Clock c;
    c.minutes = (minute + hour * 60) % (24 * 60);
    if (c.minutes < 0) {
        c.minutes += 24 * 60;
    }
    return c;
}

void print_clock(Clock c) {
    printf("%02d:%02d", c.minutes / 60, c.minutes % 60);
}

int are_equal(Clock c1, Clock c2) {
    return c1.minutes == c2.minutes;
}

Clock add_minutes(Clock c, int minutes) {
    return create_clock(0, c.minutes + minutes);
}

Clock subtract_minutes(Clock c, int minutes) {
    return create_clock(0, c.minutes - minutes);
}