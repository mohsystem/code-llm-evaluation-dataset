import org.w3c.dom.Document;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.*;
import java.io.File;
import java.io.IOException;

public class Task97_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) {
        if (args.length != 3) {
            System.out.println("Usage: java Task97_GEMINI_gemini_1_5_pro_001 <xpath> <xml_file> <id_value>");
            System.exit(1);
        }

        String xpathExpression = args[0];
        String xmlFilePath = args[1];
        String idValue = args[2];

        try {
            File xmlFile = new File(xmlFilePath);
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(xmlFile);
            doc.getDocumentElement().normalize();

            XPathFactory xpathFactory = XPathFactory.newInstance();
            XPath xpath = xpathFactory.newXPath();
            xpathExpression = xpathExpression.replace("{", "").replace("}", "");
            XPathExpression expr = xpath.compile(xpathExpression + "[@id='" + idValue + "']");

            NodeList nodeList = (NodeList) expr.evaluate(doc, XPathConstants.NODESET);
            for (int i = 0; i < nodeList.getLength(); i++) {
                System.out.println(nodeList.item(i).getNodeName() + " " + nodeList.item(i).getAttributes());
            }

        } catch (ParserConfigurationException | SAXException | IOException | XPathExpressionException e) {
            e.printStackTrace();
        }
    }
}