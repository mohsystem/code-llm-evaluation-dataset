// Java code using java.sql for database operations and java.security for password hashing
import java.sql.*;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class Task102_MISTRAL_codestral_latest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your username: ");
        String username = scanner.nextLine();
        System.out.println("Enter your new password: ");
        String newPassword = scanner.nextLine();

        try {
            updatePassword(username, newPassword);
        } catch (SQLException | NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
    }

    private static void updatePassword(String username, String newPassword) throws SQLException, NoSuchAlgorithmException {
        // Connect to the SQLite database
        Connection conn = DriverManager.getConnection("jdbc:sqlite:user_database.db");

        // Hash the new password
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hash = md.digest(newPassword.getBytes());
        StringBuffer sb = new StringBuffer();
        for (byte b : hash) {
            sb.append(String.format("%02x", b));
        }
        String hashedPassword = sb.toString();

        // Update the password in the database
        PreparedStatement pstmt = conn.prepareStatement("UPDATE users SET password = ? WHERE username = ?");
        pstmt.setString(1, hashedPassword);
        pstmt.setString(2, username);
        pstmt.executeUpdate();

        conn.close();
    }
}