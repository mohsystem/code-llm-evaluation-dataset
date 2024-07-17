
import java.sql.*;

public class CustomerInfo {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Please provide a customer username.");
            return;
        }

        String customerUsername = args[0];
        String url = "jdbc:mysql://localhost:3306/your_database";
        String user = "your_username";
        String password = "your_password";

        try (Connection conn = DriverManager.getConnection(url, user, password);
             PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM customer WHERE customerusername = ?")) {

            pstmt.setString(1, customerUsername);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                System.out.println("Customer ID: " + rs.getInt("customerid"));
                System.out.println("Name: " + rs.getString("name"));
                System.out.println("Email: " + rs.getString("email"));
                System.out.println("Phone: " + rs.getString("phone"));
            } else {
                System.out.println("Customer not found.");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
