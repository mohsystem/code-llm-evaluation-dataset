import java.util.Random;
import java.util.Scanner;

public class Task54_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static String generateOTP() {
        Random rand = new Random();
        return String.valueOf(rand.nextInt(900000) + 100000);
    }

    public static String authenticate(String username, String password, String otp) {
        if (username.equals("admin") && password.equals("password") && otp.equals(generateOTP())) {
            return "Authentication successful";
        } else {
            return "Authentication failed";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.next();
        System.out.print("Enter password: ");
        String password = scanner.next();
        System.out.print("Enter OTP: ");
        String otp = scanner.next();
        System.out.println(authenticate(username, password, otp));
    }
}