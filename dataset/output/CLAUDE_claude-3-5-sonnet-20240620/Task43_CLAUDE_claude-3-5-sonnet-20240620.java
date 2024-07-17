
import java.io.*;
import java.net.*;
import java.security.*;
import java.util.*;
import java.util.concurrent.*;

class Session {
    String id;
    String username;
    long creationTime;
    long lastAccessTime;

    public Session(String username) {
        this.id = generateSessionId();
        this.username = username;
        this.creationTime = System.currentTimeMillis();
        this.lastAccessTime = this.creationTime;
    }

    private String generateSessionId() {
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[16];
        random.nextBytes(bytes);
        return Base64.getEncoder().encodeToString(bytes);
    }
}

class SessionManager {
    private Map<String, Session> sessions = new ConcurrentHashMap<>();
    private static final long SESSION_TIMEOUT = 30 * 60 * 1000; // 30 minutes

    public String createSession(String username) {
        Session session = new Session(username);
        sessions.put(session.id, session);
        return session.id;
    }

    public boolean validateSession(String sessionId) {
        Session session = sessions.get(sessionId);
        if (session != null) {
            long currentTime = System.currentTimeMillis();
            if (currentTime - session.lastAccessTime <= SESSION_TIMEOUT) {
                session.lastAccessTime = currentTime;
                return true;
            } else {
                terminateSession(sessionId);
            }
        }
        return false;
    }

    public void terminateSession(String sessionId) {
        sessions.remove(sessionId);
    }
}

public class SecureSessionManager {
    public static void main(String[] args) throws IOException {
        SessionManager sessionManager = new SessionManager();
        ServerSocket serverSocket = new ServerSocket(8080);
        System.out.println("Server started on port 8080");

        while (true) {
            try (Socket clientSocket = serverSocket.accept();
                 PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                 BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()))) {

                String request = in.readLine();
                String[] parts = request.split(" ");
                String action = parts[0];

                switch (action) {
                    case "LOGIN":
                        String username = parts[1];
                        String sessionId = sessionManager.createSession(username);
                        out.println("Session created: " + sessionId);
                        break;
                    case "VALIDATE":
                        sessionId = parts[1];
                        boolean isValid = sessionManager.validateSession(sessionId);
                        out.println("Session valid: " + isValid);
                        break;
                    case "LOGOUT":
                        sessionId = parts[1];
                        sessionManager.terminateSession(sessionId);
                        out.println("Session terminated");
                        break;
                    default:
                        out.println("Invalid action");
                }
            } catch (IOException e) {
                System.out.println("Error handling client request: " + e.getMessage());
            }
        }
    }
}
