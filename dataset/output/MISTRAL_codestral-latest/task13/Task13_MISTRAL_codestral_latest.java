public class Task13_MISTRAL_codestral_latest {
    public static boolean isValidWalk(char[] walk) {
        if (walk.length != 10) {
            return false;
        }
        int x = 0, y = 0;
        for (char direction : walk) {
            if (direction == 'n') {
                y++;
            } else if (direction == 's') {
                y--;
            } else if (direction == 'e') {
                x++;
            } else if (direction == 'w') {
                x--;
            }
        }
        return x == 0 && y == 0;
    }
}