import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Task37_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String url = "jdbc:sqlite:example.db"; // Change to your actual database
        String username = System.console().readLine("Enter username: ");

        try (Connection conn = DriverManager.getConnection(url)) {
            String sql = "SELECT * FROM users WHERE username = ?";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();

            while (rs.next()) {
                System.out.println("User: " + rs.getString("username") + " - Info: " + rs.getString("info"));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}