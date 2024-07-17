import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // User Initialization
        String username = "user";
        String password = "password";

        System.out.println("Enter username:");
        String inputUsername = scanner.nextLine();
        System.out.println("Enter password:");
        String inputPassword = scanner.nextLine();

        if (inputUsername.equals(username) && inputPassword.equals(password)) {
            // Generate OTP
            Random random = new Random();
            int otp = random.nextInt(999999);
            System.out.println("Generated OTP: " + String.format("%06d", otp));
            System.out.println("Enter OTP:");
            int inputOTP = scanner.nextInt();

            if (inputOTP == otp) {
                System.out.println("Login Successful");
            } else {
                System.out.println("Invalid OTP");
            }
        } else {
            System.out.println("Invalid username or password");
        }
    }
}