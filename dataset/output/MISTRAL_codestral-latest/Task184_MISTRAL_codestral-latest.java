import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Robot {
    private String name;
    private static final String UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String DIGITS = "0123456789";
    private static final int LENGTH = 5;
    private static final Random random = new Random();
    private static final Set<String> existingNames = new HashSet<>();

    public Robot() {
        this.name = generateName();
    }

    private String generateName() {
        String name;
        do {
            StringBuilder sb = new StringBuilder(LENGTH);
            for (int i = 0; i < 2; i++) {
                sb.append(UPPER.charAt(random.nextInt(UPPER.length())));
            }
            for (int i = 0; i < 3; i++) {
                sb.append(DIGITS.charAt(random.nextInt(DIGITS.length())));
            }
            name = sb.toString();
        } while (existingNames.contains(name));
        existingNames.add(name);
        return name;
    }

    public static void main(String[] args) {
        Set<String> robots = new HashSet<>();
        while (robots.size() < 1000) {  // Create 1000 unique robots
            Robot robot = new Robot();
            robots.add(robot.name);
        }
        System.out.println(robots.size() == 1000);  // Should print: true
    }
}