
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int minutes;
} Clock;

Clock create_clock(int hours, int minutes) {
    Clock clock;
    clock.minutes = (hours * 60 + minutes) % 1440;
    return clock;
}

void to_string(Clock clock, char* buffer) {
    int hours = clock.minutes / 60;
    int mins = clock.minutes % 60;
    sprintf(buffer, "%02d:%02d", hours, mins);
}

bool equals(Clock clock1, Clock clock2) {
    return clock1.minutes == clock2.minutes;
}

Clock add(Clock clock, int minutes) {
    clock.minutes = (clock.minutes + minutes) % 1440;
    return clock;
}

Clock subtract(Clock clock, int minutes) {
    clock.minutes = (clock.minutes - minutes + 1440) % 1440;
    return clock;
}

int main() {
    Clock clock1 = create_clock(10, 30);
    Clock clock2 = create_clock(10, 30);
    char buffer[6];
    
    to_string(clock1, buffer);
    printf("%s\
", buffer);  // 10:30
    
    printf("%d\
", equals(clock1, clock2));  // 1
    
    clock1 = add(clock1, 30);
    to_string(clock1, buffer);
    printf("%s\
", buffer);  // 11:00
    
    clock1 = subtract(clock1, 60);
    to_string(clock1, buffer);
    printf("%s\
", buffer);  // 10:00
    
    return 0;
}
