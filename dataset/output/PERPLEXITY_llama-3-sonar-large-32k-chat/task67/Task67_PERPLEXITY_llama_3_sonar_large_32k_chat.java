import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Task67_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task67_PERPLEXITY_llama_3_sonar_large_32k_chat <customer_username>");
            System.exit(1);
        }
        String username = args[0];
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/your_database", "your_username", "your_password");
            PreparedStatement stmt = conn.prepareStatement("SELECT * FROM customer WHERE customerusername = ?");
            stmt.setString(1, username);
            ResultSet result = stmt.executeQuery();
            if (result.next()) {
                System.out.println(result.getString(1) + " " + result.getString(2) + " ...");
            } else {
                System.out.println("Customer not found");
            }
            conn.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}