import org.apache.xmlrpc.webserver.WebServer;
import org.apache.xmlrpc.server.XmlRpcServer;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import java.util.Vector;
import java.util.Hashtable;

public class Server {
    public static void main(String[] args) throws Exception {
        // Create server
        WebServer webServer = new WebServer(8000);
        XmlRpcServer xmlRpcServer = webServer.getXmlRpcServer();

        // Set up handler
        PropertyHandlerMapping phm = new PropertyHandlerMapping();
        phm.addHandler("sample", MyHandler.class);
        xmlRpcServer.setHandlerMapping(phm);

        // Start server
        webServer.start();
    }

    public static class MyHandler {
        public String sayHello(String name) {
            return "Hello, " + name + "!";
        }

        public Vector getNumbers() {
            Vector<Integer> numbers = new Vector<>();
            numbers.add(1);
            numbers.add(2);
            numbers.add(3);
            return numbers;
        }

        public Hashtable getData() {
            Hashtable<String, String> data = new Hashtable<>();
            data.put("name", "John Doe");
            data.put("age", "30");
            return data;
        }
    }
}