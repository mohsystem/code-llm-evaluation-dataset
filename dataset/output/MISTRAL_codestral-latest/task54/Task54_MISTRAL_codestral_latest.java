import java.util.Random;

public class Task54_MISTRAL_codestral_latest {
    private static final String CHARACTERS = "0123456789";
    private static final int OTP_LENGTH = 6;

    public static String generateOTP() {
        StringBuilder otp = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < OTP_LENGTH; i++) {
            otp.append(CHARACTERS.charAt(random.nextInt(CHARACTERS.length())));
        }
        return otp.toString();
    }

    public static String login(String username, String password, String otp) {
        // Here you would normally check the username and password against a database
        // For this example, we'll just assume they're correct
        if (username.equals("user") && password.equals("password")) {
            if (otp.equals(generateOTP())) {
                return "Login successful";
            } else {
                return "Invalid OTP";
            }
        } else {
            return "Invalid username or password";
        }
    }

    // Example usage:
    public static void main(String[] args) {
        System.out.println(login("user", "password", generateOTP()));
    }
}