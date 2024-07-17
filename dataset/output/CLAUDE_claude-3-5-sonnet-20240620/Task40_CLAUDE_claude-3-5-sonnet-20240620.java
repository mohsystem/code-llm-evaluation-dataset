
import java.io.IOException;
import java.security.SecureRandom;
import java.util.Base64;
import java.util.HashMap;
import java.util.Map;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/settings")
public class UserSettingsServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    private static final SecureRandom RANDOM = new SecureRandom();
    private static final Base64.Encoder ENCODER = Base64.getUrlEncoder();

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String csrfToken = generateCSRFToken();
        session.setAttribute("csrfToken", csrfToken);

        response.setContentType("text/html");
        response.getWriter().println("<html><body>");
        response.getWriter().println("<h1>User Settings</h1>");
        response.getWriter().println("<form method=\'post\' action=\'settings\'>");
        response.getWriter().println("<input type=\'hidden\' name=\'csrf_token\' value=\'" + csrfToken + "\'>");
        response.getWriter().println("Name: <input type=\'text\' name=\'name\'><br>");
        response.getWriter().println("Email: <input type=\'email\' name=\'email\'><br>");
        response.getWriter().println("<input type=\'submit\' value=\'Update\'>");
        response.getWriter().println("</form>");
        response.getWriter().println("</body></html>");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String sessionToken = (String) session.getAttribute("csrfToken");
        String requestToken = request.getParameter("csrf_token");

        if (sessionToken == null || !sessionToken.equals(requestToken)) {
            response.sendError(HttpServletResponse.SC_FORBIDDEN, "Invalid CSRF Token");
            return;
        }

        String name = request.getParameter("name");
        String email = request.getParameter("email");

        // Update user settings in database (not implemented in this example)
        // updateUserSettings(name, email);

        response.setContentType("text/html");
        response.getWriter().println("<html><body>");
        response.getWriter().println("<h1>Settings Updated</h1>");
        response.getWriter().println("<p>Name: " + name + "</p>");
        response.getWriter().println("<p>Email: " + email + "</p>");
        response.getWriter().println("</body></html>");
    }

    private String generateCSRFToken() {
        byte[] buffer = new byte[16];
        RANDOM.nextBytes(buffer);
        return ENCODER.encodeToString(buffer);
    }
}
