import java.net.*;
import java.io.*;
import org.apache.xmlrpc.*;

public class JavaServer {
    public int add(int x, int y) {
        return x + y;
    }
    
    public static void main(String[] args) {
        try {
            WebServer server = new WebServer(8080);
            server.addHandler("sample", new JavaServer());
            server.start();
            System.out.println("Java XML-RPC server running on port 8080...");
        } catch (Exception e) {
            System.err.println("JavaServer: " + e);
        }
    }
}