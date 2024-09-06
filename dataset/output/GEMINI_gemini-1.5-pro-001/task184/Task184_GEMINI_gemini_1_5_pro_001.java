import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Task184_GEMINI_gemini_1_5_pro_001 {
    private static final Set<String> usedNames = new HashSet<>();
    private static final Random random = new Random();
    private String name;

    public Task184_GEMINI_gemini_1_5_pro_001() {
        this.name = generateUniqueName();
    }

    private String generateUniqueName() {
        String newName;
        do {
            newName = generateRandomName();
        } while (usedNames.contains(newName));
        usedNames.add(newName);
        return newName;
    }

    private String generateRandomName() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 2; i++) {
            sb.append((char) (random.nextInt(26) + 'A'));
        }
        for (int i = 0; i < 3; i++) {
            sb.append(random.nextInt(10));
        }
        return sb.toString();
    }

    public void reset() {
        usedNames.remove(this.name);
        this.name = generateUniqueName();
    }

    public String getName() {
        return this.name;
    }
}