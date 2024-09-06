#include <stdio.h>

typedef struct {
    int minutes;
} Clock;

Clock createClock(int hours, int minutes) {
    Clock clock;
    clock.minutes = (hours * 60 + minutes) % (24 * 60);
    return clock;
}

int areClocksEqual(Clock c1, Clock c2) {
    return c1.minutes == c2.minutes;
}

Clock addMinutes(Clock clock, int minutes) {
    Clock newClock = createClock(0, clock.minutes + minutes);
    return newClock;
}

Clock subtractMinutes(Clock clock, int minutes) {
    Clock newClock = createClock(0, clock.minutes - minutes);
    return newClock;
}

void printClock(Clock clock) {
    int hours = clock.minutes / 60;
    int minutes = clock.minutes % 60;
    printf("%02d:%02d\n", hours, minutes);
}