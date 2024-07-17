// Main.java

import java.io.*;
import java.util.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Main extends HttpServlet {

    private Map<String, HttpSession> sessions = Collections.synchronizedMap(new HashMap<>());

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession();
        String sessionId = session.getId();
        sessions.put(sessionId, session);
        resp.getWriter().write("Session created: " + sessionId);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String sessionId = req.getParameter("sessionId");
        HttpSession session = sessions.get(sessionId);
        if (session != null) {
            session.invalidate();
            sessions.remove(sessionId);
            resp.getWriter().write("Session terminated: " + sessionId);
        } else {
            resp.getWriter().write("Session not found: " + sessionId);
        }
    }
}