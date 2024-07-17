import java.net.*;
import java.io.*;
import java.sql.*;
import com.sun.net.httpserver.*;

public class Server {
    public static void main(String[] args) throws Exception {
        HttpServer server = HttpServer.create(new InetSocketAddress(8080), 0);
        server.createContext("/store", new StoreHandler());
        server.setExecutor(null);
        server.start();
    }
}

class StoreHandler implements HttpHandler {
    @Override
    public void handle(HttpExchange t) throws IOException {
        if ("POST".equals(t.getRequestMethod())) {
            InputStream is = t.getRequestBody();
            StringBuilder sb = new StringBuilder();
            int i;
            while ((i = is.read()) != -1) {
                sb.append((char) i);
            }
            String data = sb.toString();
            storeData(data);
            String response = "Data stored successfully";
            t.sendResponseHeaders(200, response.getBytes().length);
            OutputStream os = t.getResponseBody();
            os.write(response.getBytes());
            os.close();
        }
    }

    private void storeData(String data) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:userdata.db")) {
            Statement stmt = conn.createStatement();
            stmt.executeUpdate("CREATE TABLE IF NOT EXISTS Users (data TEXT)");
            PreparedStatement pstmt = conn.prepareStatement("INSERT INTO Users (data) VALUES (?)");
            pstmt.setString(1, data);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}