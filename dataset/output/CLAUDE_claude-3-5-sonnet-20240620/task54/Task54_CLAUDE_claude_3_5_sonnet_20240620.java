
import java.util.Random;
import java.util.Scanner;

public class Task54_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String DIGITS = "0123456789";
    private static final int OTP_LENGTH = 6;

    public static String generateOTP() {
        StringBuilder otp = new StringBuilder(OTP_LENGTH);
        Random random = new Random();
        for (int i = 0; i < OTP_LENGTH; i++) {
            otp.append(DIGITS.charAt(random.nextInt(DIGITS.length())));
        }
        return otp.toString();
    }

    public static void sendOTP(String otp) {
        System.out.println("OTP sent: " + otp);
    }

    public static boolean verifyOTP(String userOTP, String generatedOTP) {
        return userOTP.equals(generatedOTP);
    }

    public static void login() {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        if (username.equals("user") && password.equals("password")) {
            String otp = generateOTP();
            sendOTP(otp);

            System.out.print("Enter OTP: ");
            String userOTP = scanner.nextLine();
            if (verifyOTP(userOTP, otp)) {
                System.out.println("Login successful!");
            } else {
                System.out.println("Invalid OTP. Login failed.");
            }
        } else {
            System.out.println("Invalid username or password.");
        }
        
        scanner.close();
    }

    public static void main(String[] args) {
        login();
    }
}
