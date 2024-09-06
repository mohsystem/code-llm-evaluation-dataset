import java.util.Random;

public class Task198_PERPLEXITY_llama_3_sonar_large_32k_chat {
    private static Random random = new Random();

    private static int rand7() {
        return random.nextInt(7) + 1;
    }

    private static int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) {
                return num % 10 + 1;
            }
        }
    }

    public static void main(String[] args) {
        int n = 1;  // change this to test with different inputs
        for (int i = 0; i < n; i++) {
            System.out.print(rand10() + " ");
        }
    }
}