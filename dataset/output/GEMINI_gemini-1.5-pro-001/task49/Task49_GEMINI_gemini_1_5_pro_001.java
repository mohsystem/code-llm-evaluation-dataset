import java.sql.*;
import static spark.Spark.*;

public class Task49_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws ClassNotFoundException {
        Class.forName("org.sqlite.JDBC");
        String url = "jdbc:sqlite:users.db";

        try (Connection conn = DriverManager.getConnection(url)) {
            if (conn != null) {
                System.out.println("Connected to the database");

                // Create a table for users if it doesn't exist
                Statement stmt = conn.createStatement();
                stmt.execute("""
                        CREATE TABLE IF NOT EXISTS users (
                            id INTEGER PRIMARY KEY AUTOINCREMENT,
                            name TEXT NOT NULL,
                            email TEXT NOT NULL UNIQUE
                        )
                        """);

                post("/users", (req, res) -> {
                    String name = req.queryParams("name");
                    String email = req.queryParams("email");

                    if (name == null || email == null) {
                        res.status(400);
                        return "Name and email are required";
                    }

                    try (PreparedStatement pstmt = conn.prepareStatement("INSERT INTO users (name, email) VALUES (?, ?)")) {
                        pstmt.setString(1, name);
                        pstmt.setString(2, email);
                        pstmt.executeUpdate();
                        res.status(201);
                        return "User created successfully";
                    } catch (SQLException e) {
                        if (e.getSQLState().equals("23505")) { // Unique constraint violation
                            res.status(400);
                            return "Email already exists";
                        } else {
                            throw new RuntimeException(e);
                        }
                    }
                });
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}