import java.sql.*;
import static spark.Spark.*;

public class Main {
    public static void main(String[] args) {
        // In-memory SQLite database
        String url = "jdbc:sqlite::memory:";
        try (Connection conn = DriverManager.getConnection(url)) {
            if (conn != null) {
                // Create the users table
                String sql = "CREATE TABLE IF NOT EXISTS users (
"
                        + " id INTEGER PRIMARY KEY AUTOINCREMENT,
"
                        + " name TEXT NOT NULL,
"
                        + " email TEXT NOT NULL UNIQUE
"
                        + ");";
                try (Statement stmt = conn.createStatement()) {
                    stmt.execute(sql);
                } catch (SQLException e) {
                    System.out.println(e.getMessage());
                }

                post("/users", (req, res) -> {
                    String name = req.queryParams("name");
                    String email = req.queryParams("email");

                    if (name == null || email == null) {
                        res.status(400);
                        return "Name and email are required";
                    }

                    try {
                        // Insert the new user into the database
                        sql = "INSERT INTO users(name, email) VALUES(?,?)";
                        try (PreparedStatement pstmt = conn.prepareStatement(sql)) {
                            pstmt.setString(1, name);
                            pstmt.setString(2, email);
                            pstmt.executeUpdate();
                        } catch (SQLException e) {
                            res.status(400);
                            return "Error: " + e.getMessage();
                        }
                        res.status(201);
                        return "User created successfully";
                    } catch (Exception e) {
                        res.status(500);
                        return "Error: " + e.getMessage();
                    }
                });
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}