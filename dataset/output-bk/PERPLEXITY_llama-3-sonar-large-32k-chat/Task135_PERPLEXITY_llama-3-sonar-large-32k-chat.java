import java.util.UUID;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class CsrfProtection extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession();
        String token = UUID.randomUUID().toString();
        session.setAttribute("_csrf_token", token);
        resp.getWriter().println("<form action='' method='post'>");
        resp.getWriter().println("<input type='hidden' name='_csrf_token' value='" + token + "'>");
        resp.getWriter().println("<input type='submit' value='Submit'>");
        resp.getWriter().println("</form>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        HttpSession session = req.getSession();
        String token = (String) session.getAttribute("_csrf_token");
        if (!req.getParameter("_csrf_token").equals(token)) {
            resp.setStatus(403);
            resp.getWriter().println("CSRF token missing or invalid");
        } else {
            resp.getWriter().println("Form submitted successfully");
        }
    }
}