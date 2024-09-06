import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.DocumentBuilder;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

public class Task61_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) throws Exception {
        String xmlString = "<root><person><name>John</name><age>30</age></person></root>";
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = factory.newDocumentBuilder();
        Document doc = builder.parse(new javax.xml.transform.stream.StreamSource(new java.io.StringReader(xmlString)));
        Element root = doc.getDocumentElement();
        System.out.println(root.getTagName(root));
    }

    public static String rootTagName(Element root) {
        return root.getTagName();
    }
}