// Java Servlet example
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.security.SecureRandom;
import java.util.Base64;

public class CSRFProtectionServlet extends HttpServlet {
    private static final SecureRandom secureRandom = new SecureRandom();
    private static final Base64.Encoder base64Encoder = Base64.getUrlEncoder();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) {
        String token = (String) request.getSession().getAttribute("_csrf_token");
        if (token == null || !token.equals(request.getParameter("_csrf_token"))) {
            response.setStatus(HttpServletResponse.SC_FORBIDDEN);
            return;
        }
        // Process the funds transfer
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) {
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("_csrf_token") == null) {
            byte[] randomBytes = new byte[24];
            secureRandom.nextBytes(randomBytes);
            String token = base64Encoder.encodeToString(randomBytes);
            session.setAttribute("_csrf_token", token);
        }
        // Render the form with the CSRF token
    }
}