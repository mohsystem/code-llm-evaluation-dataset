// Java code using Servlet and HttpSession
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.UUID;

public class Task135_PERPLEXITY_llama_3_sonar_large_32k_chat extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession();
        String token = UUID.randomUUID().toString();
        session.setAttribute("_csrf_token", token);
        resp.getWriter().write("<form action=\"\" method=\"post\"><input type=\"hidden\" name=\"_csrf_token\" value=\"" + token + "\"><input type=\"submit\" value=\"Submit\"></form>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession();
        String token = (String) session.getAttribute("_csrf_token");
        if (!token.equals(req.getParameter("_csrf_token"))) {
            resp.setStatus(403);
            resp.getWriter().write("CSRF token missing or invalid");
        } else {
            resp.getWriter().write("Form submitted successfully");
        }
    }
}