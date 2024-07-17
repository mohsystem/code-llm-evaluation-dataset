import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter password: ");
        String inputPassword = scanner.nextLine();

        try (BufferedReader br = new BufferedReader(new FileReader("password.txt"))) {
            String storedPassword = br.readLine();
            if (inputPassword.equals(storedPassword)) {
                System.out.println("Password is correct.");
            } else {
                System.out.println("Password is incorrect.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file.");
        }
    }
}