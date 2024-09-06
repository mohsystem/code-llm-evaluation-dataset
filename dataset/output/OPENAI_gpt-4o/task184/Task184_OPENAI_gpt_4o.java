import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Task184_OPENAI_gpt_4o {
    private static final Set<String> usedNames = new HashSet<>();
    private static final Random random = new Random();
    private String name;

    public Task184_OPENAI_gpt_4o() {
        this.name = generateName();
    }

    public void reset() {
        this.name = generateName();
    }

    private String generateName() {
        String newName;
        do {
            newName = generateRandomName();
        } while (usedNames.contains(newName));
        usedNames.add(newName);
        return newName;
    }

    private String generateRandomName() {
        StringBuilder sb = new StringBuilder();
        sb.append((char) ('A' + random.nextInt(26)));
        sb.append((char) ('A' + random.nextInt(26)));
        sb.append(random.nextInt(10));
        sb.append(random.nextInt(10));
        sb.append(random.nextInt(10));
        return sb.toString();
    }

    public String getName() {
        return name;
    }

    public static void main(String[] args) {
        Task184_OPENAI_gpt_4o robot = new Task184_OPENAI_gpt_4o();
        System.out.println(robot.getName());
        robot.reset();
        System.out.println(robot.getName());
    }
}