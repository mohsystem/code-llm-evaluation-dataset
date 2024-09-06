// Java code:

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Task89_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String userPassword = scanner.nextLine();

        try {
            BufferedReader reader = new BufferedReader(new FileReader("password.txt"));
            String storedPassword = reader.readLine();

            if (userPassword.equals(storedPassword)) {
                System.out.println("Password is correct.");
            } else {
                System.out.println("Password is incorrect.");
            }

            reader.close();
        } catch (IOException e) {
            System.out.println("Error reading the file.");
        }
    }
}