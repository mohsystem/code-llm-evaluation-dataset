
import java.net.*;
import java.io.*;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.List;

public class Task91_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final int PORT = 53;
    private static final String SERVER_IP = "127.0.0.1";

    public static void main(String[] args) throws IOException {
        DatagramSocket socket = new DatagramSocket(PORT, InetAddress.getByName(SERVER_IP));
        byte[] receiveData = new byte[512];

        System.out.println("DNS server listening on " + SERVER_IP + ":" + PORT);

        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);

            byte[] data = receivePacket.getData();
            InetAddress clientAddress = receivePacket.getAddress();
            int clientPort = receivePacket.getPort();

            DNSMessage query = parseDNSQuery(data);
            System.out.println("Received DNS query for " + query.domain);

            List<String> answers = resolveDNS(query.domain, query.qtype);
            byte[] response = createDNSResponse(query, answers);

            DatagramPacket sendPacket = new DatagramPacket(response, response.length, clientAddress, clientPort);
            socket.send(sendPacket);
            System.out.println("Sent DNS response to " + clientAddress.getHostAddress() + ":" + clientPort);
        }
    }

    private static DNSMessage parseDNSQuery(byte[] data) {
        ByteBuffer buffer = ByteBuffer.wrap(data);
        short id = buffer.getShort();
        buffer.getShort(); // flags
        short qdcount = buffer.getShort();

        StringBuilder domain = new StringBuilder();
        int length;
        while ((length = buffer.get()) > 0) {
            byte[] label = new byte[length];
            buffer.get(label);
            domain.append(new String(label)).append(".");
        }
        domain.setLength(domain.length() - 1);

        short qtype = buffer.getShort();
        short qclass = buffer.getShort();

        return new DNSMessage(id, domain.toString(), qtype, qclass);
    }

    private static List<String> resolveDNS(String domain, short qtype) {
        // Implement DNS resolution logic here
        List<String> answers = new ArrayList<>();
        answers.add("93.184.216.34"); // Example IP for example.com
        return answers;
    }

    private static byte[] createDNSResponse(DNSMessage query, List<String> answers) {
        ByteBuffer response = ByteBuffer.allocate(512);
        response.putShort(query.id);
        response.putShort((short) 0x8180); // Flags
        response.putShort((short) 1); // QDCOUNT
        response.putShort((short) answers.size()); // ANCOUNT
        response.putShort((short) 0); // NSCOUNT
        response.putShort((short) 0); // ARCOUNT

        // Question section
        for (String label : query.domain.split("\\\\.")) {
            response.put((byte) label.length());
            response.put(label.getBytes());
        }
        response.put((byte) 0);
        response.putShort(query.qtype);
        response.putShort(query.qclass);

        // Answer section
        for (String answer : answers) {
            response.putShort((short) 0xc00c); // Pointer to domain name
            response.putShort(query.qtype);
            response.putShort(query.qclass);
            response.putInt(300); // TTL
            response.putShort((short) answer.length());
            response.put(answer.getBytes());
        }

        byte[] result = new byte[response.position()];
        response.flip();
        response.get(result);
        return result;
    }

    private static class DNSMessage {
        short id;
        String domain;
        short qtype;
        short qclass;

        DNSMessage(short id, String domain, short qtype, short qclass) {
            this.id = id;
            this.domain = domain;
            this.qtype = qtype;
            this.qclass = qclass;
        }
    }
}
