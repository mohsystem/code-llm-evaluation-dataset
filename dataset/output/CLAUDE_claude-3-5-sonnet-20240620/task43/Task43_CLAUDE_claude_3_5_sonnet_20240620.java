
import io.javalin.Javalin;
import io.javalin.http.Context;
import org.mindrot.jbcrypt.BCrypt;

import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

public class Task43_CLAUDE_claude_3_5_sonnet_20240620 {
    private static final Map<String, String> users = new HashMap<>();
    private static final Map<String, Session> sessions = new HashMap<>();
    private static final long SESSION_TIMEOUT = 1800000; // 30 minutes

    public static void main(String[] args) {
        Javalin app = Javalin.create().start(7000);

        app.post("/register", SessionManager::register);
        app.post("/login", SessionManager::login);
        app.post("/logout", SessionManager::logout);
        app.get("/protected", SessionManager::protectedRoute);
    }

    private static void register(Context ctx) {
        String username = ctx.formParam("username");
        String password = ctx.formParam("password");
        if (users.containsKey(username)) {
            ctx.status(400).json(Map.of("error", "Username already exists"));
        } else {
            users.put(username, BCrypt.hashpw(password, BCrypt.gensalt()));
            ctx.status(201).json(Map.of("message", "User registered successfully"));
        }
    }

    private static void login(Context ctx) {
        String username = ctx.formParam("username");
        String password = ctx.formParam("password");
        if (users.containsKey(username) && BCrypt.checkpw(password, users.get(username))) {
            String sessionId = UUID.randomUUID().toString();
            sessions.put(sessionId, new Session(username, System.currentTimeMillis()));
            ctx.cookie("sessionId", sessionId);
            ctx.status(200).json(Map.of("message", "Logged in successfully"));
        } else {
            ctx.status(401).json(Map.of("error", "Invalid credentials"));
        }
    }

    private static void logout(Context ctx) {
        String sessionId = ctx.cookie("sessionId");
        if (sessionId != null) {
            sessions.remove(sessionId);
            ctx.removeCookie("sessionId");
        }
        ctx.status(200).json(Map.of("message", "Logged out successfully"));
    }

    private static void protectedRoute(Context ctx) {
        String sessionId = ctx.cookie("sessionId");
        if (sessionId != null && sessions.containsKey(sessionId)) {
            Session session = sessions.get(sessionId);
            if (System.currentTimeMillis() - session.getLoginTime() > SESSION_TIMEOUT) {
                sessions.remove(sessionId);
                ctx.removeCookie("sessionId");
                ctx.status(401).json(Map.of("error", "Session expired"));
            } else {
                ctx.status(200).json(Map.of("message", "Hello, " + session.getUsername() + "!"));
            }
        } else {
            ctx.status(401).json(Map.of("error", "Unauthorized"));
        }
    }

    private static class Session {
        private final String username;
        private final long loginTime;

        public Session(String username, long loginTime) {
            this.username = username;
            this.loginTime = loginTime;
        }

        public String getUsername() {
            return username;
        }

        public long getLoginTime() {
            return loginTime;
        }
    }
}
