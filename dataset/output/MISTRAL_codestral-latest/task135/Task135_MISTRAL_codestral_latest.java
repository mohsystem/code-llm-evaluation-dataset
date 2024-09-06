import org.apache.commons.lang3.StringUtils;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class Task135_MISTRAL_codestral_latest extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String csrfToken = request.getParameter("csrf_token");
        String sessionToken = (String) request.getSession().getAttribute("csrf_token");

        if (StringUtils.equals(csrfToken, sessionToken)) {
            // Process the request
            // ...
        } else {
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "CSRF token validation failed");
        }
    }
}