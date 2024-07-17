import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class XMLParser {
    public static void main(String[] args) {
        try {
            String xmlContent = "<root><child>value</child></root>";
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new java.io.ByteArrayInputStream(xmlContent.getBytes()));
            Element root = doc.getDocumentElement();
            System.out.println("Root element: " + root.getTagName());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}