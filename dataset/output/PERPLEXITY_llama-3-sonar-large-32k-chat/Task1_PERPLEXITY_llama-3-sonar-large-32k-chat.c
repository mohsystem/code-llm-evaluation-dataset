#include <iostream>

int main() {
    int people[][2] = {{10, 0}, {3, 5}, {5, 8}};
    int remainingPeople = 0;
    for (int i = 0; i < 3; i++) {
        remainingPeople += people[i][0] - people[i][1];
    }
    std::cout << remainingPeople << std::endl;
    return 0;
}