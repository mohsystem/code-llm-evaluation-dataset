
import java.io.*;
import java.util.Scanner;

public class PasswordChecker {
    public static void main(String[] args) {
        try {
            File file = new File("password.txt");
            Scanner fileScanner = new Scanner(file);
            String storedPassword = fileScanner.nextLine();
            fileScanner.close();

            Scanner inputScanner = new Scanner(System.in);
            System.out.print("Enter password: ");
            String enteredPassword = inputScanner.nextLine();
            inputScanner.close();

            boolean match = true;
            if (storedPassword.length() != enteredPassword.length()) {
                match = false;
            } else {
                for (int i = 0; i < storedPassword.length(); i++) {
                    if (storedPassword.charAt(i) != enteredPassword.charAt(i)) {
                        match = false;
                        break;
                    }
                }
            }

            if (match) {
                System.out.println("Password correct!");
            } else {
                System.out.println("Password incorrect!");
            }
        } catch (FileNotFoundException e) {
            System.out.println("Password file not found.");
        }
    }
}
