
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int minutes;
} Clock;

Clock create_clock(int hour, int minute) {
    Clock clock;
    clock.minutes = (hour * 60 + minute) % 1440;
    return clock;
}

void print_clock(Clock clock) {
    int hours = clock.minutes / 60;
    int mins = clock.minutes % 60;
    printf("%02d:%02d\\n", hours, mins);
}

bool clocks_equal(Clock clock1, Clock clock2) {
    return clock1.minutes == clock2.minutes;
}

Clock add_minutes(Clock clock, int minutes) {
    clock.minutes = (clock.minutes + minutes) % 1440;
    return clock;
}

Clock subtract_minutes(Clock clock, int minutes) {
    clock.minutes = (clock.minutes - minutes + 1440) % 1440;
    return clock;
}

int main() {
    Clock clock = create_clock(10, 30);
    print_clock(clock);  // 10:30
    clock = add_minutes(clock, 60);
    print_clock(clock);  // 11:30
    clock = subtract_minutes(clock, 90);
    print_clock(clock);  // 10:00
    printf("%d\\n", clocks_equal(clock, create_clock(10, 0)));  // 1 (true)
    return 0;
}
