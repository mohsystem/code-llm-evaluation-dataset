
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class TwoFactorAuth {
    private static Map<String, String> users = new HashMap<>();
    private static Map<String, String> otps = new HashMap<>();
    private static Random random = new Random();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Register a user
        System.out.print("Register - Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();
        users.put(username, password);

        // Login
        System.out.print("Login - Enter username: ");
        String loginUsername = scanner.nextLine();
        System.out.print("Enter password: ");
        String loginPassword = scanner.nextLine();

        if (users.containsKey(loginUsername) && users.get(loginUsername).equals(loginPassword)) {
            String otp = generateOTP();
            otps.put(loginUsername, otp);
            System.out.println("OTP sent: " + otp);

            System.out.print("Enter OTP: ");
            String enteredOTP = scanner.nextLine();

            if (otps.get(loginUsername).equals(enteredOTP)) {
                System.out.println("Login successful!");
            } else {
                System.out.println("Invalid OTP. Login failed.");
            }
        } else {
            System.out.println("Invalid username or password.");
        }

        scanner.close();
    }

    private static String generateOTP() {
        return String.format("%06d", random.nextInt(1000000));
    }
}
