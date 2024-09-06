import java.util.Random;

public class Task128_PERPLEXITY_llama_3_sonar_large_32k_chat {
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