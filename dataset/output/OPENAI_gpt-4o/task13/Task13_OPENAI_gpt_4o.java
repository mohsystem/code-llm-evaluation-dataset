import java.util.Arrays;

public class Task13_OPENAI_gpt_4o {
    public static boolean isValidWalk(char[] walk) {
        if (walk.length != 10) return false;
        int x = 0, y = 0;
        for (char direction : walk) {
            switch (direction) {
                case 'n': y += 1; break;
                case 's': y -= 1; break;
                case 'e': x += 1; break;
                case 'w': x -= 1; break;
            }
        }
        return x == 0 && y == 0;
    }

    public static void main(String[] args) {
        char[] walk = {'n','s','n','s','n','s','n','s','n','s'};
        System.out.println(isValidWalk(walk)); // Output: true
    }
}