import java.util.HashSet;
import java.util.Random;
import java.util.Set;

class Robot {
    private static final Set<String> usedNames = new HashSet<>();
    private String name;
    private static final Random random = new Random();

    public Robot() {
        reset();
    }

    public void reset() {
        this.name = generateUniqueName();
    }

    private String generateUniqueName() {
        while (true) {
            String name = generateRandomName();
            if (!usedNames.contains(name)) {
                usedNames.add(name);
                return name;
            }
        }
    }

    private String generateRandomName() {
        char[] letters = new char[2];
        for (int i = 0; i < 2; i++) {
            letters[i] = (char) ('A' + random.nextInt(26));
        }
        String lettersPart = new String(letters);
        int numberPart = random.nextInt(1000);
        return lettersPart + String.format("%03d", numberPart);
    }

    public String getName() {
        return name;
    }

    public static void main(String[] args) {
        Robot r1 = new Robot();
        System.out.println(r1.getName());
        r1.reset();
        System.out.println(r1.getName());
    }
}