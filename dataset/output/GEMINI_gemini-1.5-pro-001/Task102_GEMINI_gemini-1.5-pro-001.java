import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

public class UpdatePassword {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter username: ");
        String username = scanner.nextLine();
        System.out.print("Enter new password: ");
        String newPassword = scanner.nextLine();

        try {
            String hashedPassword = hashPassword(newPassword);
            updatePasswordInDatabase(username, hashedPassword);
            System.out.println("Password updated successfully.");
        } catch (NoSuchAlgorithmException | SQLException e) {
            System.err.println("Error updating password: " + e.getMessage());
        }
    }

    private static String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        md.update(password.getBytes());
        byte[] byteData = md.digest();
        StringBuilder sb = new StringBuilder();
        for (byte byteDatum : byteData) {
            sb.append(Integer.toString((byteDatum & 0xff) + 0x100, 16).substring(1));
        }
        return sb.toString();
    }

    private static void updatePasswordInDatabase(String username, String hashedPassword) throws SQLException {
        String dbUrl = "jdbc:mysql://localhost:3306/your_database_name";
        String dbUser = "your_database_user";
        String dbPassword = "your_database_password";

        try (Connection connection = DriverManager.getConnection(dbUrl, dbUser, dbPassword);
             PreparedStatement preparedStatement = connection.prepareStatement(
                     "UPDATE users SET password = ? WHERE username = ?")) {

            preparedStatement.setString(1, hashedPassword);
            preparedStatement.setString(2, username);
            preparedStatement.executeUpdate();
        }
    }
}