// Java Servlet web application
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Task38_MISTRAL_codestral_latest extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("user_input");
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>Your input: " + userInput + "</h1>");
        out.println("</body></html>");
    }
}