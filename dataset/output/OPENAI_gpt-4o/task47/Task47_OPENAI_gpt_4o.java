import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Task47_OPENAI_gpt_4o {
    public static List<String> scrapeData(String url) throws IOException {
        List<String> data = new ArrayList<>();
        Document doc = Jsoup.connect(url).get();
        
        // This example assumes you're scraping list items (li) from the webpage
        Elements items = doc.select("li");
        for (Element item : items) {
            data.add(item.text());
        }
        
        return data;
    }

    public static void storeData(String dbName, List<String> data) throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        Statement stmt = conn.createStatement();
        stmt.executeUpdate("CREATE TABLE IF NOT EXISTS scraped_data (content TEXT)");

        PreparedStatement pstmt = conn.prepareStatement("INSERT INTO scraped_data (content) VALUES (?)");
        for (String item : data) {
            pstmt.setString(1, item);
            pstmt.executeUpdate();
        }
        
        conn.close();
    }

    public static void main(String[] args) throws IOException, SQLException {
        String url = "https://example.com";
        String dbName = "scraped_data.db";
        List<String> data = scrapeData(url);
        storeData(dbName, data);
    }
}