// Java code to accept username and password, hash the password, and update the database

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.Scanner;

public class Task102_OPENAI_gpt_4o {
    private static String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] hashedBytes = md.digest(password.getBytes());
        StringBuilder sb = new StringBuilder();
        for (byte b : hashedBytes) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    private static void updatePassword(String username, String password) throws NoSuchAlgorithmException, SQLException {
        String hashedPassword = hashPassword(password);
        Connection conn = DriverManager.getConnection("jdbc:sqlite:users.db");
        Statement stmt = conn.createStatement();
        stmt.executeUpdate("CREATE TABLE IF NOT EXISTS users (username TEXT, password TEXT)");
        String sql = "UPDATE users SET password = ? WHERE username = ?";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        pstmt.setString(1, hashedPassword);
        pstmt.setString(2, username);
        pstmt.executeUpdate();
        conn.close();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException, SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter new password: ");
        String password = scanner.nextLine();
        updatePassword(username, password);
    }
}