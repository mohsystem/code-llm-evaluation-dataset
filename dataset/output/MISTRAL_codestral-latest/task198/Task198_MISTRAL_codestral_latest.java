// Java
import java.util.Random;

public class Task198_MISTRAL_codestral_latest {
    private static Random rand = new Random();

    public static int rand7() {
        return rand.nextInt(7) + 1;
    }

    public static int rand10() {
        while (true) {
            int a = rand7();
            int b = rand7();
            int num = (a - 1) * 7 + b;
            if (num <= 40) {
                return 1 + (num - 1) % 10;
            }
        }
    }
}