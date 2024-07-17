
import java.net.*;
import java.io.*;

public class DNSServer {
    private static final int PORT = 53;
    private static final int BUFFER_SIZE = 512;

    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket(PORT);
            byte[] receiveData = new byte[BUFFER_SIZE];

            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                socket.receive(receivePacket);

                byte[] dnsQuery = receivePacket.getData();
                int queryLength = receivePacket.getLength();

                // Parse DNS query
                String domainName = parseDNSQuery(dnsQuery, queryLength);

                // Resolve DNS record (simplified)
                String ipAddress = resolveDNS(domainName);

                // Create DNS response
                byte[] dnsResponse = createDNSResponse(dnsQuery, queryLength, ipAddress);

                InetAddress clientAddress = receivePacket.getAddress();
                int clientPort = receivePacket.getPort();

                DatagramPacket sendPacket = new DatagramPacket(dnsResponse, dnsResponse.length, clientAddress, clientPort);
                socket.send(sendPacket);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String parseDNSQuery(byte[] query, int length) {
        StringBuilder domainName = new StringBuilder();
        int pos = 12; // Skip header

        while (pos < length && query[pos] != 0) {
            int labelLength = query[pos++] & 0xFF;
            for (int i = 0; i < labelLength; i++) {
                domainName.append((char) query[pos++]);
            }
            domainName.append(\'.\');
        }

        return domainName.toString();
    }

    private static String resolveDNS(String domainName) {
        // Simplified DNS resolution (replace with actual DNS lookup logic)
        return "192.168.1.1";
    }

    private static byte[] createDNSResponse(byte[] query, int queryLength, String ipAddress) {
        byte[] response = new byte[queryLength + 16];
        System.arraycopy(query, 0, response, 0, queryLength);

        // Set QR bit to 1 (response)
        response[2] |= 0x80;

        // Set Answer count to 1
        response[7] = 1;

        // Add answer section
        int answerOffset = queryLength;
        response[answerOffset++] = (byte) 0xC0; // Pointer to domain name
        response[answerOffset++] = 12; // Offset to domain name in header

        // Type A record
        response[answerOffset++] = 0;
        response[answerOffset++] = 1;

        // Class IN
        response[answerOffset++] = 0;
        response[answerOffset++] = 1;

        // TTL (4 bytes, set to 300 seconds)
        response[answerOffset++] = 0;
        response[answerOffset++] = 0;
        response[answerOffset++] = 1;
        response[answerOffset++] = 44;

        // Data length (4 bytes for IPv4)
        response[answerOffset++] = 0;
        response[answerOffset++] = 4;

        // IP address
        String[] octets = ipAddress.split("\\\\.");
        for (String octet : octets) {
            response[answerOffset++] = (byte) Integer.parseInt(octet);
        }

        return response;
    }
}
