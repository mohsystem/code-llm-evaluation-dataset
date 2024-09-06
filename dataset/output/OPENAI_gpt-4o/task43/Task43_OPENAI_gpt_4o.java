import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/")
public class Task43_OPENAI_gpt_4o extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String username = (String) session.getAttribute("username");
        
        if (username != null) {
            out.println("Logged in as " + username);
        } else {
            out.println("You are not logged in");
        }
        out.println("<a href='login'>Login</a> <a href='logout'>Logout</a>");
        out.close();
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String action = request.getServletPath();
        
        if ("/login".equals(action)) {
            session.setAttribute("username", request.getParameter("username"));
            response.sendRedirect(".");
        } else if ("/logout".equals(action)) {
            session.invalidate();
            response.sendRedirect(".");
        } else {
            doGet(request, response);
        }
    }
}