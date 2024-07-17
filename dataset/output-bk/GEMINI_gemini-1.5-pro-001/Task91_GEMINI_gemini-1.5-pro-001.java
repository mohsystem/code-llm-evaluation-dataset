import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.HashMap;
import java.util.Map;

public class DNSServer {

    private static final int DNS_PORT = 53;
    private static final int MAX_PACKET_SIZE = 512;

    private static Map<String, String> dnsRecords;

    public static void main(String[] args) throws IOException {
        // Initialize DNS records
        initDNSRecords();

        // Create a DatagramSocket to listen on the specified port
        DatagramSocket socket = new DatagramSocket(DNS_PORT);
        System.out.println("DNS Server started on port " + DNS_PORT);

        while (true) {
            // Create a DatagramPacket to receive the incoming request
            byte[] receiveData = new byte[MAX_PACKET_SIZE];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);

            // Process the DNS request
            processDNSRequest(socket, receivePacket);
        }
    }

    private static void initDNSRecords() {
        dnsRecords = new HashMap<>();
        dnsRecords.put("google.com", "172.217.160.142");
        dnsRecords.put("facebook.com", "157.240.195.35");
        // Add more DNS records as needed
    }

    private static void processDNSRequest(DatagramSocket socket, DatagramPacket receivePacket) throws IOException {
        // Parse the DNS request
        String domainName = parseDNSRequest(receivePacket.getData());

        // Resolve the DNS record
        String ipAddress = resolveDNSRecord(domainName);

        // Create the DNS response
        byte[] responseData = createDNSResponse(receivePacket.getData(), ipAddress);

        // Send the DNS response back to the client
        InetAddress clientAddress = receivePacket.getAddress();
        int clientPort = receivePacket.getPort();
        DatagramPacket sendPacket = new DatagramPacket(responseData, responseData.length, clientAddress, clientPort);
        socket.send(sendPacket);
    }

    private static String parseDNSRequest(byte[] data) {
        // Implement DNS request parsing logic here
        // Extract the domain name from the DNS request data
        // ...
        return "";
    }

    private static String resolveDNSRecord(String domainName) {
        // Resolve the IP address for the given domain name
        return dnsRecords.getOrDefault(domainName, "");
    }

    private static byte[] createDNSResponse(byte[] requestData, String ipAddress) {
        // Implement DNS response creation logic here
        // Construct the DNS response packet using the request data and resolved IP address
        // ...
        return new byte[0];
    }
}