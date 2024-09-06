
import com.sun.net.httpserver.HttpServer;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Scanner;

public class Task49_CLAUDE_claude_3_5_sonnet_20240620 {
    public static void main(String[] args) throws IOException {
        HttpServer server = HttpServer.create(new InetSocketAddress(8000), 0);
        server.createContext("/api/users", new UserHandler());
        server.setExecutor(null);
        server.start();
        System.out.println("Server started on port 8000");
    }

    static class UserHandler implements HttpHandler {
        @Override
        public void handle(HttpExchange exchange) throws IOException {
            if ("POST".equals(exchange.getRequestMethod())) {
                try {
                    Scanner scanner = new Scanner(exchange.getRequestBody()).useDelimiter("\\\\A");
                    String requestBody = scanner.hasNext() ? scanner.next() : "";
                    scanner.close();

                    String[] parts = requestBody.split("&");
                    String name = parts[0].split("=")[1];
                    String email = parts[1].split("=")[1];

                    Connection conn = DriverManager.getConnection("jdbc:sqlite:users.db");
                    PreparedStatement stmt = conn.prepareStatement(
                        "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT)");
                    stmt.executeUpdate();

                    stmt = conn.prepareStatement("INSERT INTO users (name, email) VALUES (?, ?)");
                    stmt.setString(1, name);
                    stmt.setString(2, email);
                    stmt.executeUpdate();

                    conn.close();

                    String response = "User created successfully";
                    exchange.sendResponseHeaders(201, response.length());
                    OutputStream os = exchange.getResponseBody();
                    os.write(response.getBytes());
                    os.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                    String response = "Error creating user";
                    exchange.sendResponseHeaders(500, response.length());
                    OutputStream os = exchange.getResponseBody();
                    os.write(response.getBytes());
                    os.close();
                }
            } else {
                String response = "Method not allowed";
                exchange.sendResponseHeaders(405, response.length());
                OutputStream os = exchange.getResponseBody();
                os.write(response.getBytes());
                os.close();
            }
        }
    }
}
