import java.sql.*;

public class Task46_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        try {
            Connection conn = DriverManager.getConnection("jdbc:sqlite:users.db");
            Statement stmt = conn.createStatement();
            stmt.execute("CREATE TABLE IF NOT EXISTS users (" +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                    "name TEXT NOT NULL," +
                    "email TEXT NOT NULL UNIQUE," +
                    "password TEXT NOT NULL" +
                    ")");

            String name = System.console().readLine("Enter your name: ");
            String email = System.console().readLine("Enter your email: ");
            String password = System.console().readLine("Enter your password: ");

            PreparedStatement insertStmt = conn.prepareStatement("INSERT INTO users (name, email, password) VALUES (?, ?, ?)");
            insertStmt.setString(1, name);
            insertStmt.setString(2, email);
            insertStmt.setString(3, password);

            try {
                insertStmt.executeUpdate();
                System.out.println("Registration successful!");
            } catch (SQLException e) {
                System.out.println("Error: Email already exists.");
            }

            stmt.close();
            conn.close();
        } catch (SQLException e) {
            System.out.println("Error connecting to database: " + e.getMessage());
        }
    }
}