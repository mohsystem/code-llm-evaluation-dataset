import java.io.*;
import java.net.*;
import java.util.*;

public class Task90_OPENAI_gpt_4o {
    private static Vector<ClientHandler> clients = new Vector<>();
    
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(5555)) {
            System.out.println("Server started, waiting for clients...");
            
            while (true) {
                Socket socket = serverSocket.accept();
                DataInputStream dis = new DataInputStream(socket.getInputStream());
                DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
                
                ClientHandler clientHandler = new ClientHandler(socket, dis, dos);
                clients.add(clientHandler);
                
                Thread thread = new Thread(clientHandler);
                thread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    static class ClientHandler implements Runnable {
        private Socket socket;
        private DataInputStream dis;
        private DataOutputStream dos;
        
        public ClientHandler(Socket socket, DataInputStream dis, DataOutputStream dos) {
            this.socket = socket;
            this.dis = dis;
            this.dos = dos;
        }
        
        @Override
        public void run() {
            String received;
            while (true) {
                try {
                    received = dis.readUTF();
                    System.out.println("Received: " + received);
                    
                    for (ClientHandler client : clients) {
                        if (client != this) {
                            client.dos.writeUTF(received);
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    break;
                }
            }
            
            try {
                this.dis.close();
                this.dos.close();
                this.socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}