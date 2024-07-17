
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class FormServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String name = request.getParameter("name");
        String email = request.getParameter("email");

        out.println("<html><body>");
        out.println("<h2>Submitted Information:</h2>");
        out.println("<p>Name: " + name + "</p>");
        out.println("<p>Email: " + email + "</p>");
        out.println("</body></html>");
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><body>");
        out.println("<h2>User Input Form</h2>");
        out.println("<form method=\'post\'>");
        out.println("Name: <input type=\'text\' name=\'name\'><br>");
        out.println("Email: <input type=\'text\' name=\'email\'><br>");
        out.println("<input type=\'submit\' value=\'Submit\'>");
        out.println("</form>");
        out.println("</body></html>");
    }
}
