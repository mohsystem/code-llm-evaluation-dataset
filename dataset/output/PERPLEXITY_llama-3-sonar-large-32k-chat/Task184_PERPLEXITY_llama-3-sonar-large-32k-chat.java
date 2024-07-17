import java.util.HashSet;
import java.util.Random;
import java.util.Set;

class Robot {
    private String name;
    private static Set<String> usedNames = new HashSet<>();

    public Robot() {
        this.name = generateName();
    }

    private String generateName() {
        Random random = new Random();
        while (true) {
            String name = String.format("%c%c%03d",
                    (char) ('A' + random.nextInt(26)),
                    (char) ('A' + random.nextInt(26)),
                    random.nextInt(900) + 100);
            if (!usedNames.contains(name)) {
                usedNames.add(name);
                return name;
            }
        }
    }

    public void reset() {
        this.name = generateName();
    }

    public String getName() {
        return this.name;
    }

    public static void main(String[] args) {
        Robot robot = new Robot();
        System.out.println(robot.getName());
        robot.reset();
        System.out.println(robot.getName());
    }
}