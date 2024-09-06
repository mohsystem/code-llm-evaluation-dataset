import org.apache.xmlrpc.WebServer;
import org.apache.xmlrpc.XmlRpcException;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.server.XmlRpcServer;

public class Task111_OPENAI_gpt_4o {
    public Integer add(int x, int y) {
        return x + y;
    }
    
    public Integer subtract(int x, int y) {
        return x - y;
    }
    
    public static void main(String[] args) throws Exception {
        WebServer server = new WebServer(8000);
        XmlRpcServer xmlRpcServer = server.getXmlRpcServer();
        PropertyHandlerMapping phm = new PropertyHandlerMapping();
        
        phm.addHandler("Sample", Task111_OPENAI_gpt_4o.class);
        xmlRpcServer.setHandlerMapping(phm);
        
        server.start();
        System.out.println("Server started on port 8000...");
    }
}