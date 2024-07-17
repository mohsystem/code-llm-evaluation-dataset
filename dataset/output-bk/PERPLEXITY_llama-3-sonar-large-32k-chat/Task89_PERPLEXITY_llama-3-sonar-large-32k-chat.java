import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter password: ");
        String inputPassword = scanner.nextLine();

        File file = new File("password.txt");
        Scanner fileScanner = new Scanner(file);
        String storedPassword = fileScanner.nextLine();

        boolean isValid = true;
        if (inputPassword.length() != storedPassword.length()) {
            isValid = false;
        } else {
            for (int i = 0; i < inputPassword.length(); i++) {
                if (inputPassword.charAt(i) != storedPassword.charAt(i)) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            System.out.println("Password is valid");
        } else {
            System.out.println("Password is invalid");
        }
    }
}