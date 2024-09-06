import java.util.Random;

public class Task128_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Random random = new Random();

        // Generate a random integer between 1 and 10
        int randomInteger = random.nextInt(10) + 1;
        System.out.println("Random Integer: " + randomInteger);

        // Generate a random floating-point number between 0 and 1
        double randomDouble = random.nextDouble();
        System.out.println("Random Double: " + randomDouble);

        // Generate a random element from an array
        String[] fruits = {"apple", "banana", "cherry"};
        int randomIndex = random.nextInt(fruits.length);
        String randomFruit = fruits[randomIndex];
        System.out.println("Random Fruit: " + randomFruit);
    }
}