
import java.util.Arrays;

public class Task15_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String[] towerBuilder(int nFloors) {
        String[] tower = new String[nFloors];
        for (int i = 0; i < nFloors; i++) {
            String spaces = " ".repeat(nFloors - i - 1);
            String stars = "*".repeat(2 * i + 1);
            tower[i] = spaces + stars + spaces;
        }
        return tower;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(towerBuilder(3)));
        System.out.println(Arrays.toString(towerBuilder(6)));
    }
}
