#include <string.h>
int isValidWalk(char *walk) {
  if (strlen(walk) != 10) {
    return 0;
  }
  int x = 0, y = 0;
  for (int i = 0; i < 10; i++) {
    switch (walk[i]) {
      case 'n':
        y++;
        break;
      case 's':
        y--;
        break;
      case 'e':
        x++;
        break;
      case 'w':
        x--;
        break;
    }
  }
  return x == 0 && y == 0;
}