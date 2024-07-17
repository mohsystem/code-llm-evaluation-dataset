
import java.util.Random;

public class RandomGenerator {
    public static void main(String[] args) {
        Random random = new Random();
        
        System.out.println("Random Number: " + generateRandomNumber(random));
        System.out.println("Random Token: " + generateRandomToken(random));
    }
    
    public static int generateRandomNumber(Random random) {
        return random.nextInt(100) + 1;
    }
    
    public static String generateRandomToken(Random random) {
        String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        StringBuilder token = new StringBuilder();
        for (int i = 0; i < 8; i++) {
            token.append(characters.charAt(random.nextInt(characters.length())));
        }
        return token.toString();
    }
}
