import java.io.IOException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Scraper {
    public static void main(String[] args) {
        String url = "https://example.com";
        String dbUrl = "jdbc:sqlite:sample.db";
        Connection conn = null;
        
        try {
            // Connect to the database
            conn = DriverManager.getConnection(dbUrl);
            conn.createStatement().execute("CREATE TABLE IF NOT EXISTS data (info TEXT)");

            // Scrape the data
            Document doc = Jsoup.connect(url).get();
            Elements elements = doc.select("p"); // Example: selecting all <p> elements

            for (Element element : elements) {
                String text = element.text();
                PreparedStatement pstmt = conn.prepareStatement("INSERT INTO data (info) VALUES (?)");
                pstmt.setString(1, text);
                pstmt.executeUpdate();
            }
        } catch (IOException | SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }
}