import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.UUID;

public class UpdateUserSettingsServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String csrfToken = UUID.randomUUID().toString();
        req.getSession().setAttribute("csrfToken", csrfToken);
        resp.getWriter().write("<html><body><form action=\"/update\" method=\"post\">"
                + "<input type=\"hidden\" name=\"csrfToken\" value=\"" + csrfToken + "\">"
                + "Username: <input type=\"text\" name=\"username\"><br>"
                + "Email: <input type=\"email\" name=\"email\"><br>"
                + "<input type=\"submit\" value=\"Update\">"
                + "</form></body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String csrfToken = (String) req.getSession().getAttribute("csrfToken");
        String tokenFromRequest = req.getParameter("csrfToken");
        if (csrfToken != null && csrfToken.equals(tokenFromRequest)) {
            // Update user settings
            String username = req.getParameter("username");
            String email = req.getParameter("email");
            // Update user settings logic here
            resp.getWriter().write("User settings updated successfully!");
        } else {
            resp.setStatus(403);
            resp.getWriter().write("CSRF token is invalid!");
        }
    }
}