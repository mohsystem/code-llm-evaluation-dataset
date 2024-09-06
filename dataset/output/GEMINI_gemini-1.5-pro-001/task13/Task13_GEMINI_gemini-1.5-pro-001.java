class Solution {
  public static boolean isValidWalk(char[] walk) {
    if (walk.length != 10) {
      return false;
    }
    int x = 0, y = 0;
    for (char direction : walk) {
      switch (direction) {
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
}