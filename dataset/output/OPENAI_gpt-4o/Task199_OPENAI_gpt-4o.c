#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int hour;
    int minute;
} Clock;

Clock create_clock(int hour, int minute) {
    int totalMinutes = (hour * 60 + minute) % (24 * 60);
    Clock clock = {totalMinutes / 60, totalMinutes % 60};
    return clock;
}

Clock add_minutes(Clock clock, int minutes) {
    return create_clock(clock.hour, clock.minute + minutes);
}

bool are_equal(Clock clock1, Clock clock2) {
    return clock1.hour == clock2.hour && clock1.minute == clock2.minute;
}

void print_clock(Clock clock) {
    printf("%02d:%02d
", clock.hour, clock.minute);
}

int main() {
    Clock clock1 = create_clock(10, 30);
    Clock clock2 = add_minutes(clock1, 35);
    Clock clock3 = create_clock(11, 5);
    print_clock(clock2);  // 11:05
    printf("%d
", are_equal(clock2, clock3));  // 1 (True)
    return 0;
}