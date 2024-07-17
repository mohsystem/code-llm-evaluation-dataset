import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class DisplayInputServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String userInput = request.getParameter("userInput");
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>You entered: " + userInput + "</h1>");
        out.println("</body></html>");
    }
}