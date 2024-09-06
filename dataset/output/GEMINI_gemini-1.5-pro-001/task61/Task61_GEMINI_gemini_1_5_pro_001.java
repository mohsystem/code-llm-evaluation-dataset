import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;

public class Task61_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        String xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
        String rootElement = getRootElement(xmlString);
        System.out.println(rootElement);
    }

    public static String getRootElement(String xmlString) {
        try {
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document document = builder.parse(new org.xml.sax.InputSource(new java.io.StringReader(xmlString)));
            return document.getDocumentElement().getNodeName();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }
}