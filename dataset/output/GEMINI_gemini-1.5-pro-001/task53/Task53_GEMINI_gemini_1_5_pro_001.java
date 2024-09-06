import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;

public class Task53_GEMINI_gemini_1_5_pro_001 extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        HttpSession session = request.getSession();

        Integer visits = (Integer) session.getAttribute("visits");
        if (visits == null) {
            visits = 1;
        } else {
            visits++;
        }
        session.setAttribute("visits", visits);

        response.getWriter().println("You have visited this page " + visits + " times.");
    }
}