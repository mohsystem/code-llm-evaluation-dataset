import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet("/settings")
public class SettingsServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Check if the user is already logged in
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("user") == null) {
            response.sendRedirect("login"); // Redirect to login page if not
            return;
        }

        // Render the settings form with a CSRF token
        String csrfToken = generateCSRFToken(session);
        request.setAttribute("csrfToken", csrfToken);
        request.getRequestDispatcher("/WEB-INF/settings.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Check if the user is already logged in
        HttpSession session = request.getSession(false);
        if (session == null || session.getAttribute("user") == null) {
            response.sendRedirect("login"); 
            return;
        }

        // Verify CSRF token
        String requestToken = request.getParameter("csrfToken");
        String sessionToken = (String) session.getAttribute("csrfToken");
        if (!verifyCSRFToken(requestToken, sessionToken)) {
            response.sendError(HttpServletResponse.SC_FORBIDDEN, "Invalid CSRF token");
            return;
        }

        // Update user settings logic here (e.g., database update)
        // ...

        response.sendRedirect("success"); // Redirect to a success page
    }

    // CSRF token generation and verification methods
    private String generateCSRFToken(HttpSession session) {
        String csrfToken = // Generate a secure random token
        session.setAttribute("csrfToken", csrfToken);
        return csrfToken;
    }

    private boolean verifyCSRFToken(String requestToken, String sessionToken) {
        return requestToken != null && sessionToken != null && requestToken.equals(sessionToken);
    }
}