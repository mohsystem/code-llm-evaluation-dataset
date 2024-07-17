
import java.sql.*;
import java.util.Scanner;

public class UserInfoQuery {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/your_database";
        String user = "your_username";
        String password = "your_password";

        try (Scanner scanner = new Scanner(System.in);
             Connection conn = DriverManager.getConnection(url, user, password)) {

            System.out.print("Enter username: ");
            String username = scanner.nextLine();

            String query = "SELECT * FROM users WHERE username = ?";
            try (PreparedStatement pstmt = conn.prepareStatement(query)) {
                pstmt.setString(1, username);
                try (ResultSet rs = pstmt.executeQuery()) {
                    if (rs.next()) {
                        System.out.println("User ID: " + rs.getInt("id"));
                        System.out.println("Username: " + rs.getString("username"));
                        System.out.println("Email: " + rs.getString("email"));
                    } else {
                        System.out.println("User not found.");
                    }
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
