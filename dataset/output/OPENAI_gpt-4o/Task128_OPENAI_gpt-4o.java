import java.util.Random;

public class RandomNumberGenerator {
    public static void main(String[] args) {
        System.out.println("Java random number: " + generateRandomNumber());
    }

    public static int generateRandomNumber() {
        Random rand = new Random();
        return rand.nextInt(100) + 1;
    }
}