#include <string>
#include <vector>

using namespace std;

vector<string> towerBuilder(int nFloors) {
  vector<string> tower;

  for (int i = 0; i < nFloors; i++) {
    int stars = 2 * i + 1;
    int spaces = nFloors - i - 1;

    tower.push_back(string(spaces, ' ') + string(stars, '*') + string(spaces, ' '));
  }

  return tower;
}