
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Task120_CLAUDE_claude_3_5_sonnet_20240620 extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        
        out.println("<html><body>");
        out.println("<form method='post'>");
        out.println("<input type='text' name='user_input'>");
        out.println("<input type='submit' value='Submit'>");
        out.println("</form>");
        out.println("</body></html>");
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        String userInput = request.getParameter("user_input");
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        
        out.println("<html><body>");
        out.println("<form method='post'>");
        out.println("<input type='text' name='user_input'>");
        out.println("<input type='submit' value='Submit'>");
        out.println("</form>");
        out.println("<p>" + userInput + "</p>");
        out.println("</body></html>");
    }
}
