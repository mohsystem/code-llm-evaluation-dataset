#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int hour;
    int minute;
} Clock;

void normalize(Clock *clock) {
    if (clock->minute >= 60) {
        clock->hour += clock->minute / 60;
        clock->minute %= 60;
    }
    while (clock->minute < 0) {
        clock->hour -= 1;
        clock->minute += 60;
    }
    clock->hour = (clock->hour + 24) % 24;
}

Clock createClock(int hour, int minute) {
    Clock clock = {hour, minute};
    normalize(&clock);
    return clock;
}

void addMinutes(Clock *clock, int minutes) {
    clock->minute += minutes;
    normalize(clock);
}

void subtractMinutes(Clock *clock, int minutes) {
    clock->minute -= minutes;
    normalize(clock);
}

bool areEqual(Clock clk1, Clock clk2) {
    return clk1.hour == clk2.hour && clk1.minute == clk2.minute;
}

void printClock(Clock clock) {
    printf("%02d:%02d\n", clock.hour, clock.minute);
}

int main() {
    Clock clock1 = createClock(14, 30);
    Clock clock2 = createClock(14, 30);
    Clock clock3 = createClock(10, 45);

    addMinutes(&clock1, 90);
    subtractMinutes(&clock2, 70);

    printClock(clock1);  // Should print 16:00
    printClock(clock2);  // Should print 13:20
    printClock(clock3);  // Should print 10:45
    printf("%d\n", areEqual(clock1, clock2));  // Should print 0 (false)
    printf("%d\n", areEqual(clock1, createClock(16, 0)));  // Should print 1 (true)

    return 0;
}