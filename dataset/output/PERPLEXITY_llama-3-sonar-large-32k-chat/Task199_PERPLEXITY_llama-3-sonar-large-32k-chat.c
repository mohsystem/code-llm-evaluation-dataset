#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
} Clock;

void addMinutes(Clock* clock, int minutes) {
    clock->minutes += minutes;
    clock->hours += clock->minutes / 60;
    clock->hours %= 24;
    clock->minutes %= 60;
}

void subtractMinutes(Clock* clock, int minutes) {
    clock->minutes -= minutes;
    if (clock->minutes < 0) {
        clock->hours -= 1;
        clock->minutes += 60;
    }
    clock->hours %= 24;
    clock->minutes %= 60;
}

int isEqual(const Clock* clock1, const Clock* clock2) {
    return clock1->hours == clock2->hours && clock1->minutes == clock2->minutes;
}

int main() {
    Clock clock1 = {10, 30};
    Clock clock2 = {10, 30};
    printf("%d\n", isEqual(&clock1, &clock2));  // 1 (true)

    addMinutes(&clock1, 30);
    printf("%d %d\n", clock1.hours, clock1.minutes);  // 11 0

    subtractMinutes(&clock1, 60);
    printf("%d %d\n", clock1.hours, clock1.minutes);  // 10 0

    return 0;
}