import java.util.Scanner;

public class Task136_OPENAI_gpt_4o {
    public static boolean authenticate(String username, String password) {
        String storedUsername = "user";
        String storedPassword = "pass";
        return username.equals(storedUsername) && password.equals(storedPassword);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        if (authenticate(username, password)) {
            System.out.println("Access granted");
        } else {
            System.out.println("Access denied");
        }

        scanner.close();
    }
}