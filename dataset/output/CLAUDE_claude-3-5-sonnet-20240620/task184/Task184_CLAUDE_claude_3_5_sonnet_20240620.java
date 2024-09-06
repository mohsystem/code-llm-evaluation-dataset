
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Task184_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String DIGITS = "0123456789";
    private static final Random RANDOM = new Random();
    private static final Set<String> USED_NAMES = new HashSet<>();

    private String name;

    public Task184_CLAUDE_claude_3_5_sonnet_20240620() {
        reset();
    }

    public String getName() {
        return name;
    }

    public void reset() {
        name = generateName();
    }

    private String generateName() {
        String newName;
        do {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 2; i++) {
                sb.append(LETTERS.charAt(RANDOM.nextInt(LETTERS.length())));
            }
            for (int i = 0; i < 3; i++) {
                sb.append(DIGITS.charAt(RANDOM.nextInt(DIGITS.length())));
            }
            newName = sb.toString();
        } while (USED_NAMES.contains(newName));
        USED_NAMES.add(newName);
        return newName;
    }

    public static void main(String[] args) {
        Task184_CLAUDE_claude_3_5_sonnet_20240620 robot = new Task184_CLAUDE_claude_3_5_sonnet_20240620();
        System.out.println(robot.getName());
        robot.reset();
        System.out.println(robot.getName());
    }
}
