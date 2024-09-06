
import java.io.IOException;
import java.security.SecureRandom;
import java.util.Base64;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/")
public class Task135_CLAUDE_claude_3_5_sonnet_20240620 extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final String CSRF_TOKEN = "csrfToken";

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String csrfToken = generateCSRFToken(request.getSession());
        response.setContentType("text/html");
        response.getWriter().println("<form method='post'>");
        response.getWriter().println("<input type='hidden' name='" + CSRF_TOKEN + "' value='" + csrfToken + "'>");
        response.getWriter().println("<input type='submit' value='Submit'>");
        response.getWriter().println("</form>");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (isValidCSRFToken(request.getSession(), request.getParameter(CSRF_TOKEN))) {
            response.getWriter().println("Form submitted successfully!");
        } else {
            response.setStatus(HttpServletResponse.SC_FORBIDDEN);
            response.getWriter().println("CSRF token validation failed");
        }
    }

    private String generateCSRFToken(HttpSession session) {
        String token = generateRandomToken();
        session.setAttribute(CSRF_TOKEN, token);
        return token;
    }

    private boolean isValidCSRFToken(HttpSession session, String token) {
        String storedToken = (String) session.getAttribute(CSRF_TOKEN);
        return storedToken != null && storedToken.equals(token);
    }

    private String generateRandomToken() {
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[20];
        random.nextBytes(bytes);
        return Base64.getEncoder().encodeToString(bytes);
    }
}
