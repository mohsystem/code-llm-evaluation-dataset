import java.nio.file.*;
import java.io.*;
import java.util.Scanner;

public class PasswordCheck {
    public static void main(String[] args) throws IOException {
        Path filePath = Paths.get("password.txt");
        String storedPassword = new String(Files.readAllBytes(filePath)).trim();
        
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String enteredPassword = scanner.nextLine();
        
        boolean isMatch = storedPassword.length() == enteredPassword.length();
        
        for(int i = 0; i < storedPassword.length() && isMatch; i++) {
            isMatch &= storedPassword.charAt(i) == enteredPassword.charAt(i);
        }

        if(isMatch) {
            System.out.println("Password match");
        } else {
            System.out.println("Password does not match");
        }
    }
}