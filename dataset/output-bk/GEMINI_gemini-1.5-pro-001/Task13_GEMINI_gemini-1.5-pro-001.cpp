#include <string>

using namespace std;

bool isValid(string walk) {
  if (walk.length() != 10) {
    return false;
  }
  int x = 0;
  int y = 0;
  for (char c : walk) {
    if (c == 'n') {
      y++;
    } else if (c == 's') {
      y--;
    } else if (c == 'e') {
      x++;
    } else if (c == 'w') {
      x--;
    }
  }
  return x == 0 && y == 0;
}