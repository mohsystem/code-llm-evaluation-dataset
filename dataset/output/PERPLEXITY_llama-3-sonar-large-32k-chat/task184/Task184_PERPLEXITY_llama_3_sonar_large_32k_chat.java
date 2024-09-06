import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class Task184_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private String name;
    private static Set<String> usedNames = new HashSet<>();

    public Task184_PERPLEXITY_llama_3_sonar_large_32k_chat() {
        this.name = generateName();
    }

    private String generateName() {
        Random random = new Random();
        while (true) {
            String name = String.format("%c%c%03d", 
                    (char) ('A' + random.nextInt(26)), 
                    (char) ('A' + random.nextInt(26)), 
                    random.nextInt(1000));
            if (usedNames.add(name)) {
                return name;
            }
        }
    }

    public void reset() {
        this.name = generateName();
    }
}