import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.security.SecureRandom;
import java.util.Base64;

public class UserSettingsServlet extends HttpServlet {
    private static final String CSRF_TOKEN_SESSION_KEY = "csrfToken";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String csrfToken = generateCSRFToken();
        request.getSession().setAttribute(CSRF_TOKEN_SESSION_KEY, csrfToken);

        PrintWriter out = response.getWriter();
        out.println("<form action=\"/updateSettings\" method=\"post\">");
        out.println("<input type=\"hidden\" name=\"csrfToken\" value=\"" + csrfToken + "\">");
        // Add other form fields here
        out.println("<input type=\"submit\" value=\"Update Settings\">");
        out.println("</form>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String requestCsrfToken = request.getParameter("csrfToken");
        HttpSession session = request.getSession(false);

        if (session != null && requestCsrfToken != null && requestCsrfToken.equals(session.getAttribute(CSRF_TOKEN_SESSION_KEY))) {
            // Process the form data and update user settings
            // ...
            response.getWriter().println("Settings updated successfully");
        } else {
            response.sendError(HttpServletResponse.SC_FORBIDDEN, "Invalid CSRF token");
        }
    }

    private String generateCSRFToken() {
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[20];
        random.nextBytes(bytes);
        return Base64.getEncoder().encodeToString(bytes);
    }
}