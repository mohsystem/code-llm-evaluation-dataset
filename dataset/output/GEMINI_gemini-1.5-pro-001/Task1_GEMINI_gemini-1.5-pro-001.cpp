#include <iostream>
#include <vector>

using namespace std;

int peopleOnBus(vector<vector<int>> busStops) {
    int peopleOnBus = 0;
    for (int i = 0; i < busStops.size(); i++) {
        peopleOnBus += busStops[i][0] - busStops[i][1];
    }
    return peopleOnBus;
}

int main() {
    vector<vector<int>> busStops = {{10, 0}, {3, 5}, {5, 8}};
    cout << peopleOnBus(busStops) << endl;
    return 0;
}