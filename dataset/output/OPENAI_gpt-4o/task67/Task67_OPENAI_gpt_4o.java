import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Task67_OPENAI_gpt_4o {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task67_OPENAI_gpt_4o <customerusername>");
            System.exit(1);
        }
        String username = args[0];
        try {
            Connection conn = DriverManager.getConnection("jdbc:sqlite:your_database.db");
            String query = "SELECT * FROM customer WHERE username = ?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {
                System.out.println("Customer Info: " + rs.toString());
            }
            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}