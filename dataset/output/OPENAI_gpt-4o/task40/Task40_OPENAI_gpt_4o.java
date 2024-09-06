import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/settings")
public class Task40_OPENAI_gpt_4o extends HttpServlet {
    private static final String CSRF_TOKEN_KEY = "csrf_token";

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String csrfToken = "aCSRFtoken";
        session.setAttribute(CSRF_TOKEN_KEY, csrfToken);
        response.setContentType("text/html");
        response.getWriter().write(
            "<form method='POST' action='/settings'>" +
            "<input type='hidden' name='_csrf_token' value='" + csrfToken + "'/>" +
            "<input type='text' name='username' placeholder='Username'/>" +
            "<button type='submit'>Save</button>" +
            "</form>"
        );
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String csrfToken = (String) session.getAttribute(CSRF_TOKEN_KEY);
        session.removeAttribute(CSRF_TOKEN_KEY);
        String requestToken = request.getParameter("_csrf_token");

        if (csrfToken == null || !csrfToken.equals(requestToken)) {
            response.sendError(HttpServletResponse.SC_FORBIDDEN, "CSRF token is missing or incorrect");
            return;
        }

        // Save settings logic here
        response.getWriter().write("Settings updated!");
    }
}