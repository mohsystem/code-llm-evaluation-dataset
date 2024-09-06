import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Task184_MISTRAL_codestral_latest {
    private String name;
    private static Set<String> existingNames = new HashSet<>();
    private static final String UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    private static final String DIGITS = "0123456789";
    private static final Random RANDOM = new Random();

    public Task184_MISTRAL_codestral_latest() {
        this.name = generateName();
    }

    private String generateName() {
        String name;
        do {
            name = randomString(UPPERCASE_LETTERS, 2) + randomString(DIGITS, 3);
        } while (existingNames.contains(name));
        existingNames.add(name);
        return name;
    }

    private String randomString(String characters, int length) {
        StringBuilder sb = new StringBuilder(length);
        for (int i = 0; i < length; i++) {
            sb.append(characters.charAt(RANDOM.nextInt(characters.length())));
        }
        return sb.toString();
    }

    // Test
    public static void main(String[] args) {
        Set<String> names = new HashSet<>();
        for (int i = 0; i < 1000; i++) {
            names.add(new Task184_MISTRAL_codestral_latest().name);
        }
        if (names.size() != 1000) {
            throw new AssertionError("Names are not unique");
        }
    }
}