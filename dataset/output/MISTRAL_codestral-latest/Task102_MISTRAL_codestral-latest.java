// Java
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws NoSuchAlgorithmException, SQLException {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter username: ");
        String username = scanner.nextLine();

        System.out.println("Enter new password: ");
        String password = scanner.nextLine();

        String hashedPassword = getSecurePassword(password);

        updatePasswordInDatabase(username, hashedPassword);
    }

    private static String getSecurePassword(String passwordToHash) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        byte[] bytes = md.digest(passwordToHash.getBytes());
        StringBuilder sb = new StringBuilder();
        for(int i=0; i< bytes.length ;i++)
        {
            sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
        }
        return sb.toString();
    }

    private static void updatePasswordInDatabase(String username, String hashedPassword) throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydatabase", "username", "password");
        PreparedStatement stmt = conn.prepareStatement("UPDATE users SET password = ? WHERE username = ?");
        stmt.setString(1, hashedPassword);
        stmt.setString(2, username);
        stmt.executeUpdate();
    }
}