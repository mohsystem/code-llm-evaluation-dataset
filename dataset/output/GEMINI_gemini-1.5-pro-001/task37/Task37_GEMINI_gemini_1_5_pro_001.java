import java.sql.*;

public class Task37_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try {
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection("jdbc:sqlite:your_database.db");
            stmt = conn.createStatement();

            String username = System.console().readLine("Enter username: ");
            String sql = "SELECT * FROM users WHERE username='" + username + "'";
            rs = stmt.executeQuery(sql);

            if (rs.next()) {
                System.out.println(rs.getString("username") + " " + rs.getString("email")); 
            } else {
                System.out.println("User not found.");
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                if (rs != null) rs.close();
                if (stmt != null) stmt.close();
                if (conn != null) conn.close();
            } catch (SQLException e) {
                System.err.println(e.getMessage());
            }
        }
    }
}