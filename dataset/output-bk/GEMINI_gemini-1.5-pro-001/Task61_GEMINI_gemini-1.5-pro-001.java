import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.IOException;
import java.io.StringReader;

public class ExtractXmlRoot {

    public static void main(String[] args) {
        String xmlString = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
        try {
            String rootElement = getRootElement(xmlString);
            System.out.println(rootElement);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static String getRootElement(String xmlString) throws Exception {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        InputSource is = new InputSource(new StringReader(xmlString));
        Document doc = builder.parse(is);
        Element rootElement = doc.getDocumentElement();
        return rootElement.getNodeName();
    }
}