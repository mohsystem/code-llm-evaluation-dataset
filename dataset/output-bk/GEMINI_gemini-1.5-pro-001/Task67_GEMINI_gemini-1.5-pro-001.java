import java.sql.*;

public class GetCustomerInfo {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java GetCustomerInfo <customerusername>");
            return;
        }

        String customerUsername = args[0];
        String jdbcUrl = "jdbc:mysql://localhost:3306/your_database_name";
        String dbUser = "your_username";
        String dbPassword = "your_password";

        try (Connection connection = DriverManager.getConnection(jdbcUrl, dbUser, dbPassword)) {
            String sql = "SELECT * FROM customer WHERE customerusername = ?";
            PreparedStatement statement = connection.prepareStatement(sql);
            statement.setString(1, customerUsername);
            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                // Assuming customer table has columns: customerusername, firstname, lastname, email
                String username = resultSet.getString("customerusername");
                String firstName = resultSet.getString("firstname");
                String lastName = resultSet.getString("lastname");
                String email = resultSet.getString("email");

                System.out.println("Customer Information:");
                System.out.println("Username: " + username);
                System.out.println("First Name: " + firstName);
                System.out.println("Last Name: " + lastName);
                System.out.println("Email: " + email);
            } else {
                System.out.println("Customer not found.");
            }
        } catch (SQLException e) {
            System.out.println("Error connecting to database: " + e.getMessage());
        }
    }
}