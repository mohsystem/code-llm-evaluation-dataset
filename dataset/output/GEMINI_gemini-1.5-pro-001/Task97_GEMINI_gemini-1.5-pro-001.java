import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;
import org.w3c.dom.Document;
import org.xml.sax.InputSource;

public class XMLParser {

    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Usage: java XMLParser <xml_file> <xpath_query> <id_value>");
            return;
        }

        String xmlFile = args[0];
        String xpathQuery = args[1];
        String idValue = args[2];
        xpathQuery = String.format(xpathQuery, idValue);

        try {
            // Construct and parse the XML file
            DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document doc = builder.parse(new InputSource(xmlFile));

            // Execute the XPath query
            XPath xpath = XPathFactory.newInstance().newXPath();
            String result = (String) xpath.compile(xpathQuery).evaluate(doc, XPathConstants.STRING);

            // Return the result
            System.out.println(result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}