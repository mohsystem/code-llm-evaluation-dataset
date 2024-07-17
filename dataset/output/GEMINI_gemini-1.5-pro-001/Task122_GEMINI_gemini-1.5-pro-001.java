import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class UserSignup {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your username: ");
        String username = scanner.nextLine();
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();
        System.out.print("Confirm your password: ");
        String confirmPassword = scanner.nextLine();
        if (password.equals(confirmPassword)) {
            try (FileWriter fileWriter = new FileWriter("users.txt", true)) {
                fileWriter.write(username + ":" + password + "
");
                System.out.println("Signup successful!");
            } catch (IOException e) {
                System.out.println("An error occurred while saving your information.");
                e.printStackTrace();
            }
        } else {
            System.out.println("Passwords don't match. Please try again.");
        }
    }
}