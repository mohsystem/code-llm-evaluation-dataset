#include <iostream>
#include <vector>

using namespace std;

int getNumberOfPeopleOnBus(const vector<pair<int, int>>& busStops) {
    int peopleOnBus = 0;

    for (const auto& stop : busStops) {
        peopleOnBus += stop.first - stop.second;
    }

    return peopleOnBus;
}

int main() {
    // Test cases
    vector<pair<int, int>> busStops1 = {{10, 0}, {3, 5}, {5, 8}};
    vector<pair<int, int>> busStops2 = {{3, 0}, {9, 1}, {4, 10}, {12, 2}, {6, 1}, {7, 10}};
    vector<pair<int, int>> busStops3 = {{3, 0}, {9, 1}, {4, 8}, {12, 2}, {6, 1}, {7, 8}};

    cout << getNumberOfPeopleOnBus(busStops1) << endl; // 5
    cout << getNumberOfPeopleOnBus(busStops2) << endl; // 17
    cout << getNumberOfPeopleOnBus(busStops3) << endl; // 21

    return 0;
}