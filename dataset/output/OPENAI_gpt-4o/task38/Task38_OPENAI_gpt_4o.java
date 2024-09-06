import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Task38_OPENAI_gpt_4o extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response)
                        throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<form method='POST'>");
        out.println("<input type='text' name='user_input'/>");
        out.println("<input type='submit' value='Submit'/>");
        out.println("</form>");
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response)
                         throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String userInput = request.getParameter("user_input");
        out.println("<h1>" + userInput + "</h1>");
        out.println("<form method='POST'>");
        out.println("<input type='text' name='user_input'/>");
        out.println("<input type='submit' value='Submit'/>");
        out.println("</form>");
    }
}