import java.util.Scanner;
import java.util.Random;

public class Task54_OPENAI_gpt_4o {

    public static int generateOTP() {
        Random rand = new Random();
        return 100000 + rand.nextInt(900000);
    }

    public static boolean verifyOTP(int userOTP, int actualOTP) {
        return userOTP == actualOTP;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        
        System.out.print("Enter password: ");
        String password = scanner.nextLine();

        // Simulate verifying username and password
        boolean userAuth = username.equals("user") && password.equals("pass");
        if (userAuth) {
            int otp = generateOTP();
            System.out.println("Your OTP is: " + otp);
            System.out.print("Enter the OTP you received: ");
            int userOTP = scanner.nextInt();
            if (verifyOTP(userOTP, otp)) {
                System.out.println("Login successful!");
            } else {
                System.out.println("Invalid OTP!");
            }
        } else {
            System.out.println("Invalid username or password!");
        }
        
        scanner.close();
    }
}