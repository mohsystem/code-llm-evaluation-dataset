
import java.sql.*;

public class Task67_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task67_CLAUDE_claude_3_5_sonnet_20240620 <customerusername>");
            System.exit(1);
        }

        String username = args[0];
        Task67_CLAUDE_claude_3_5_sonnet_20240620 customerInfo = getCustomerInfo(username);

        if (customerInfo != null) {
            System.out.println("Customer Information:");
            System.out.println("ID: " + customerInfo.id);
            System.out.println("Username: " + customerInfo.username);
            System.out.println("Name: " + customerInfo.name);
            System.out.println("Email: " + customerInfo.email);
            System.out.println("Phone: " + customerInfo.phone);
        } else {
            System.out.println("Customer not found.");
        }
    }

    private static Task67_CLAUDE_claude_3_5_sonnet_20240620 getCustomerInfo(String username) {
        String url = "jdbc:sqlite:customer_database.db";
        String sql = "SELECT * FROM customer WHERE customerusername = ?";

        try (Connection conn = DriverManager.getConnection(url);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                Task67_CLAUDE_claude_3_5_sonnet_20240620 customer = new Task67_CLAUDE_claude_3_5_sonnet_20240620();
                customer.id = rs.getInt("id");
                customer.username = rs.getString("customerusername");
                customer.name = rs.getString("name");
                customer.email = rs.getString("email");
                customer.phone = rs.getString("phone");
                return customer;
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return null;
    }

    private int id;
    private String username;
    private String name;
    private String email;
    private String phone;
}
