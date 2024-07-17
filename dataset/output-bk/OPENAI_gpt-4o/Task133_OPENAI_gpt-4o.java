import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class PasswordReset {
    public static String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hash = md.digest(password.getBytes());
        StringBuilder hexString = new StringBuilder();
        for (byte b : hash) {
            hexString.append(String.format("%02x", b));
        }
        return hexString.toString();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.println("Java: Enter your current password:");
            String currentPassword = scanner.nextLine();
            String hashedPassword = hashPassword(currentPassword);
            
            System.out.println("Java: Enter new password:");
            String newPassword = scanner.nextLine();
            String hashedNewPassword = hashPassword(newPassword);
            
            System.out.println("Java: Password has been reset!");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } finally {
            scanner.close();
        }
    }
}