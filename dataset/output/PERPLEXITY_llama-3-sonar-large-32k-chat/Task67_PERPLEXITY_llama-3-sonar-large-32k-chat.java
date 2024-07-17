import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class CustomerInfo {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java CustomerInfo <customerusername>");
            return;
        }
        String customerUsername = args[0];
        String url = "jdbc:mysql://localhost:3306/mydb";
        String username = "root";
        String password = "password";
        try {
            Connection conn = DriverManager.getConnection(url, username, password);
            PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM customer WHERE username = ?");
            pstmt.setString(1, customerUsername);
            ResultSet rs = pstmt.executeQuery();
            if (rs.next()) {
                Customer customer = new Customer(rs.getString("username"), rs.getString("name"), rs.getString("email"));
                System.out.println(customer);
            } else {
                System.out.println("Customer not found");
            }
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

class Customer {
    private String username;
    private String name;
    private String email;

    public Customer(String username, String name, String email) {
        this.username = username;
        this.name = name;
        this.email = email;
    }

    @Override
    public String toString() {
        return "Customer{" +
                "username='" + username + '\'' +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}