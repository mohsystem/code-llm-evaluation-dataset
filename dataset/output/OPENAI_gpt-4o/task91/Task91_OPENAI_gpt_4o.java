// Java code for UDP DNS resolver (simplified)

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Task91_OPENAI_gpt_4o {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket(5353, InetAddress.getByName("127.0.0.1"));
        
        byte[] buffer = new byte[512];
        
        while (true) {
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);
            
            // Echoing back the data for simplicity
            socket.send(new DatagramPacket(packet.getData(), packet.getLength(), packet.getAddress(), packet.getPort()));
        }
    }
}