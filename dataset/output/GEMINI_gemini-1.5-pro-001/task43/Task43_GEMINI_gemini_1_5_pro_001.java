import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

public class Task43_GEMINI_gemini_1_5_pro_001 extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        // Create a session
        HttpSession session = request.getSession();

        // Store data in the session
        session.setAttribute("username", "john.doe");

        // Get data from the session
        String username = (String) session.getAttribute("username");

        // Invalidate the session (terminate)
        session.invalidate();

        response.getWriter().println("Session managed. Username: " + username);
    }
}