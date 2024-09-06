
import java.sql.*;
import java.util.Scanner;

public class Task46_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final String DB_URL = "jdbc:sqlite:users.db";

    public static void createTable() {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {
            String sql = "CREATE TABLE IF NOT EXISTS users " +
                         "(name TEXT, email TEXT PRIMARY KEY, password TEXT)";
            stmt.execute(sql);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void registerUser() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.print("Enter your email: ");
        String email = scanner.nextLine();
        System.out.print("Enter your password: ");
        String password = scanner.nextLine();

        String sql = "INSERT INTO users(name, email, password) VALUES(?,?,?)";

        try (Connection conn = DriverManager.getConnection(DB_URL);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, name);
            pstmt.setString(2, email);
            pstmt.setString(3, password);
            pstmt.executeUpdate();
            System.out.println("Registration successful!");
        } catch (SQLException e) {
            if (e.getMessage().contains("UNIQUE constraint failed")) {
                System.out.println("Email already exists. Registration failed.");
            } else {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        createTable();
        registerUser();
    }
}
