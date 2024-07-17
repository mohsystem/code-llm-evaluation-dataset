import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class WebScraper {
    public static void main(String[] args) throws IOException, SQLException {
        String url = "https://www.example.com";
        Document doc = Jsoup.connect(url).get();

        String dbUrl = "jdbc:mysql://localhost:3306/mydb";
        String username = "root";
        String password = "password";

        Connection conn = DriverManager.getConnection(dbUrl, username, password);

        Elements elements = doc.select("div.data");
        for (Element element : elements) {
            String data = element.text();
            PreparedStatement pstmt = conn.prepareStatement("INSERT INTO mytable (data) VALUES (?)");
            pstmt.setString(1, data);
            pstmt.executeUpdate();
        }

        conn.close();
    }
}