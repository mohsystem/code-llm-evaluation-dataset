// Java
import java.util.Random;

public class TwoFactorAuthentication {
    public static void main(String[] args) {
        String userInput = "user_input"; // replace with actual user input
        String password = "password"; // replace with actual password

        if (authenticate(userInput, password)) {
            int otp = generateOTP();
            System.out.println("Your One Time Password is: " + otp);
            // Send OTP to user's registered email or phone number
            // Prompt user to enter OTP
            // Verify OTP
        } else {
            System.out.println("Authentication failed.");
        }
    }

    public static boolean authenticate(String userInput, String password) {
        // Implement your authentication logic here
        // This is a placeholder, replace with your actual logic
        return userInput.equals("username") && password.equals("password");
    }

    public static int generateOTP() {
        Random random = new Random();
        return 100000 + random.nextInt(900000);
    }
}