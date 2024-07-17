import java.util.Random;

public class Main {
    public static void main(String[] args) {
        String lettersAndDigits = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        StringBuilder token = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            token.append(lettersAndDigits.charAt(random.nextInt(lettersAndDigits.length())));
        }
        System.out.println("Random token is " + token.toString());
    }
}