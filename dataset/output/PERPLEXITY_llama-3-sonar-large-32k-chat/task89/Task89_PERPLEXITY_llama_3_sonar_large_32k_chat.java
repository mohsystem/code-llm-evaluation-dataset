import java.io.*;
import java.util.*;

public class Task89_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        try {
            File file = new File("password.txt");
            Scanner scanner = new Scanner(file);
            String storedPassword = scanner.next();
            scanner.close();
            System.out.print("Enter your password: ");
            Scanner scanner2 = new Scanner(System.in);
            String userPassword = scanner2.next();
            scanner2.close();
            if (storedPassword.length() != userPassword.length()) {
                System.out.println("Password does not match");
            } else {
                boolean match = true;
                for (int i = 0; i < storedPassword.length(); i++) {
                    if (storedPassword.charAt(i) != userPassword.charAt(i)) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    System.out.println("Password matches");
                } else {
                    System.out.println("Password does not match");
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
    }
}