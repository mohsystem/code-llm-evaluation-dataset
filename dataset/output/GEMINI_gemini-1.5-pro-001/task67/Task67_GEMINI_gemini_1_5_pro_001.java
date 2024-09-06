import java.sql.*;

public class Task67_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java Task67_GEMINI_gemini_1_5_pro_001 <customerusername>");
            System.exit(1);
        }

        String customerusername = args[0];
        Customer customer = getCustomerInfo(customerusername);

        if (customer != null) {
            System.out.println(customer);
        } else {
            System.out.println("No customer found with username: " + customerusername);
        }
    }

    public static Customer getCustomerInfo(String customerusername) {
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        Customer customer = null;

        try {
            // Connect to database (replace with your database details)
            conn = DriverManager.getConnection("jdbc:sqlite:your_database.db");

            // Prepare SQL query
            String sql = "SELECT * FROM customer WHERE customerusername = ?";
            stmt = conn.prepareStatement(sql);
            stmt.setString(1, customerusername);

            // Execute query
            rs = stmt.executeQuery();

            // Process result set
            if (rs.next()) {
                customer = new Customer();
                customer.setCustomerusername(rs.getString("customerusername"));
                customer.setCustomerfirstname(rs.getString("customerfirstname"));
                // Set other fields as needed
            }
        } catch (SQLException e) {
            System.err.println("SQL Exception: " + e.getMessage());
        } finally {
            // Close resources
            try { if (rs != null) rs.close(); } catch (SQLException e) {}
            try { if (stmt != null) stmt.close(); } catch (SQLException e) {}
            try { if (conn != null) conn.close(); } catch (SQLException e) {}
        }

        return customer;
    }
}

class Customer {
    private String customerusername;
    private String customerfirstname;
    // Add other fields as needed

    // Getters and setters
    public String getCustomerusername() {
        return customerusername;
    }

    public void setCustomerusername(String customerusername) {
        this.customerusername = customerusername;
    }

    public String getCustomerfirstname() {
        return customerfirstname;
    }

    public void setCustomerfirstname(String customerfirstname) {
        this.customerfirstname = customerfirstname;
    }

    // Add other getters and setters

    @Override
    public String toString() {
        return "Customer{" +
                "customerusername='" + customerusername + '\'' +
                ", customerfirstname='" + customerfirstname + '\'' +
                '}';
    }
}