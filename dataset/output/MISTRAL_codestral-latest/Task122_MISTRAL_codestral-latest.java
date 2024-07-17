// Java

import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        signup();
    }

    public static void signup() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter username: ");
        String username = scanner.nextLine();
        System.out.println("Enter password: ");
        String password = scanner.nextLine();
        // In a real-world application, you would hash the password before storing it.
        // For simplicity, we're storing it as is.
        try {
            FileWriter writer = new FileWriter("passwords.txt", true);
            writer.write(username + ":" + password + "
");
            writer.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}