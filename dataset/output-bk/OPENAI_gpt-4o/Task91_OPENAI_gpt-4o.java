import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.ByteBuffer;

public class UDPSocket {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket(5353, InetAddress.getByName("0.0.0.0"));
        byte[] buffer = new byte[512];

        while (true) {
            DatagramPacket request = new DatagramPacket(buffer, buffer.length);
            socket.receive(request);
            InetAddress clientAddress = request.getAddress();
            int clientPort = request.getPort();

            ByteBuffer requestBuffer = ByteBuffer.wrap(request.getData());
            // Parse DNS request
            byte[] header = new byte[12];
            requestBuffer.get(header);
            int questionCount = requestBuffer.getShort(4);
            String queryName = parseQueryName(requestBuffer);
            short queryType = requestBuffer.getShort();
            short queryClass = requestBuffer.getShort();

            // Placeholder for resolving DNS (currently echoing the same name back)
            ByteBuffer responseBuffer = ByteBuffer.allocate(512);
            responseBuffer.put(header);
            responseBuffer.putShort(6, (short) 1); // Answer count

            responseBuffer.put(request.getData(), 12, queryName.length() + 2 + 4); // Query section

            // Answer section
            responseBuffer.put(requestBuffer.array(), 12, queryName.length() + 2); // Name
            responseBuffer.putShort(queryType);
            responseBuffer.putShort(queryClass);
            responseBuffer.putInt(120); // TTL
            responseBuffer.putShort((short) 4); // Data length
            responseBuffer.put(InetAddress.getByName("127.0.0.1").getAddress()); // A Record

            DatagramPacket response = new DatagramPacket(responseBuffer.array(), responseBuffer.position(), clientAddress, clientPort);
            socket.send(response);
        }
    }

    private static String parseQueryName(ByteBuffer buffer) {
        StringBuilder name = new StringBuilder();
        int length;
        while ((length = buffer.get()) > 0) {
            byte[] section = new byte[length];
            buffer.get(section);
            for (byte b : section) {
                name.append((char) b);
            }
            name.append('.');
        }
        return name.toString();
    }
}