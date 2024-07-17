import java.util.Random;
import java.util.Scanner;

public class TwoFactorAuth {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter username: ");
        String username = scanner.nextLine();

        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        // Simulated user authentication
        if (authenticate(username, password)) {
            int otp = generateOTP();
            System.out.println("One-Time Password: " + otp);

            System.out.print("Enter OTP: ");
            int enteredOtp = scanner.nextInt();

            if (enteredOtp == otp) {
                System.out.println("Two-factor authentication successful. Access granted!");
            } else {
                System.out.println("Incorrect OTP. Access denied!");
            }
        } else {
            System.out.println("Invalid username or password. Access denied!");
        }
    }

    // Simulated authentication function (replace with actual database check)
    private static boolean authenticate(String username, String password) {
        return username.equals("user") && password.equals("password");
    }

    // Generate a random 6-digit OTP
    private static int generateOTP() {
        Random random = new Random();
        return 100000 + random.nextInt(900000);
    }
}