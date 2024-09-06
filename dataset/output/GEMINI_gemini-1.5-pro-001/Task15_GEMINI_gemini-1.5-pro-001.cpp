#include <string>
#include <vector>

using namespace std;

vector<string> towerBuilder(int nFloors) {
  vector<string> tower;
  for (int i = 0; i < nFloors; i++) {
    string stars(2 * i + 1, '*');
    string spaces(nFloors - i - 1, ' ');
    tower.push_back(spaces + stars + spaces);
  }
  return tower;
}