// Java code using Servlet and HttpSession
import javax.servlet.http.*;
import java.io.*;

public class Task43_PERPLEXITY_llama_3_sonar_large_32k_chat extends HttpServlet {
    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        if (username.equals("admin") && password.equals("password")) {
            HttpSession session = req.getSession();
            session.setAttribute("username", username);
            res.sendRedirect("home");
        } else {
            res.sendRedirect("login");
        }
    }

    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
        String path = req.getServletPath();
        if (path.equals("/login")) {
            res.getWriter().println("<form action=\"\" method=\"post\">");
            res.getWriter().println("Username: <input type=\"text\" name=\"username\"><br>");
            res.getWriter().println("Password: <input type=\"password\" name=\"password\"><br>");
            res.getWriter().println("<input type=\"submit\" value=\"Login\">");
            res.getWriter().println("</form>");
        } else if (path.equals("/home")) {
            HttpSession session = req.getSession();
            if (session.getAttribute("username") != null) {
                res.getWriter().println("Welcome, " + session.getAttribute("username"));
            } else {
                res.sendRedirect("login");
            }
        } else if (path.equals("/logout")) {
            HttpSession session = req.getSession();
            session.invalidate();
            res.sendRedirect("login");
        }
    }
}