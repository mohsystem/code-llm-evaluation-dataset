import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.io.IOException;
import java.sql.*;

public class Task47_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        String url = "https://www.example.com"; // Replace with the target website
        String table_name = "scraped_data";
        String data_selector = "div.example-class"; // Replace with actual CSS selector

        // Database setup
        String dbUrl = "jdbc:sqlite:scraped_data.db";
        try (Connection conn = DriverManager.getConnection(dbUrl);
             Statement stmt = conn.createStatement()) {

            stmt.execute(f"CREATE TABLE IF NOT EXISTS {table_name} (id INTEGER PRIMARY KEY AUTOINCREMENT, data TEXT)");

            // Data scraping and storage
            Document doc = Jsoup.connect(url).get();
            Elements dataElements = doc.select(data_selector);

            PreparedStatement insertStmt = conn.prepareStatement(f"INSERT INTO {table_name} (data) VALUES (?)");
            for (Element element : dataElements) {
                String data = element.text().trim();
                insertStmt.setString(1, data);
                insertStmt.executeUpdate();
            }
            System.out.println("Data scraped and stored successfully!");

        } catch (IOException | SQLException e) {
            e.printStackTrace();
        }
    }
}