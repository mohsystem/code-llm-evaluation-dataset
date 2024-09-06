import java.util.HashMap;
import java.util.Map;

import org.apache.xmlrpc.webserver.WebServer;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.XmlRpcException;

public class Task111_GEMINI_gemini_1_5_pro_001 {
    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.out.println("Usage: Task111_GEMINI_gemini_1_5_pro_001 <port>");
            System.exit(1);
        }

        int port = Integer.parseInt(args[0]);
        WebServer webServer = new WebServer(port);

        PropertyHandlerMapping phm = new PropertyHandlerMapping();
        phm.addHandler("sample", MyCalculator.class);
        webServer.getXmlRpcServer().setHandlerMapping(phm);

        webServer.start();

        System.out.println("Started XML-RPC server on port " + port);
    }

    public static class MyCalculator {
        public int add(int x, int y) {
            return x + y;
        }

        public int subtract(int x, int y) {
            return x - y;
        }

        public int multiply(int x, int y) {
            return x * y;
        }

        public double divide(double x, double y) {
            if (y == 0) {
                throw new XmlRpcException("Divide by zero error");
            }
            return x / y;
        }

        public String echo(String message) {
            return "Echo: " + message;
        }
    }
}