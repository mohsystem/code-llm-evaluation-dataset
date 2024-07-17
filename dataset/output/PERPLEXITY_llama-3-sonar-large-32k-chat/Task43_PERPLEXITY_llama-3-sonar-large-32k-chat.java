import javax.servlet.http.*;
import java.util.*;

public class SessionManager extends HttpServlet {
    private HashMap<String, HttpSession> sessions = new HashMap<>();

    @Override
    public void doGet(HttpServletRequest req, HttpServletResponse res) {
        String action = req.getParameter("action");
        if (action.equals("create")) {
            createSession(req, res);
        } else if (action.equals("terminate")) {
            terminateSession(req, res);
        }
    }

    private void createSession(HttpServletRequest req, HttpServletResponse res) {
        HttpSession session = req.getSession(true);
        sessions.put(session.getId(), session);
        res.setStatus(201);
    }

    private void terminateSession(HttpServletRequest req, HttpServletResponse res) {
        String sessionId = req.getParameter("sessionId");
        if (sessions.containsKey(sessionId)) {
            sessions.remove(sessionId);
            res.setStatus(200);
        } else {
            res.setStatus(404);
        }
    }
}