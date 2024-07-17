public class Main {
    public static boolean isValidWalk(String[] walk) {
        int x = 0, y = 0;
        for (String dir : walk) {
            if (dir.equals("n")) y++;
            if (dir.equals("s")) y--;
            if (dir.equals("e")) x++;
            if (dir.equals("w")) x--;
        }
        return x == 0 && y == 0 && walk.length == 10;
    }

    public static void main(String[] args) {
        String[] walk = {"n", "s", "e", "w", "n", "s", "e", "w", "n", "s"};
        System.out.println(isValidWalk(walk));
    }
}