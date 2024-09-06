import java.util.Scanner;

public class Task51_OPENAI_gpt_4o {

    public static String encrypt(String text) {
        StringBuilder result = new StringBuilder();
        
        for (char ch : text.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                result.append((char) ((ch + 1 - 'A') % 26 + 'A'));
            } else if (Character.isLowerCase(ch)) {
                result.append((char) ((ch + 1 - 'a') % 26 + 'a'));
            } else {
                result.append(ch);
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        String inputText = "HelloWorld";
        String encryptedText = encrypt(inputText);
        System.out.println(encryptedText);
    }
}