import java.sql.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/your_database_name", "your_username", "your_password");
             Scanner scanner = new Scanner(System.in)) {

            System.out.print("Enter username: ");
            String username = scanner.nextLine();

            String query = "SELECT * FROM users WHERE username = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setString(1, username);
                try (ResultSet resultSet = preparedStatement.executeQuery()) {
                    while (resultSet.next()) {
                        System.out.println("Username: " + resultSet.getString("username"));
                        System.out.println("Email: " + resultSet.getString("email"));
                        // Retrieve other user information as needed
                    }
                }
            }

        } catch (SQLException e) {
            System.err.println("Error connecting to database or executing query: " + e.getMessage());
        }
    }
}