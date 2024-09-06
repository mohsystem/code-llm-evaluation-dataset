// This is a simplified example and doesn't include necessary imports or error handling

@WebServlet("/login")
public class Task43_MISTRAL_codestral_latest extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        session.setAttribute("username", "user");
        response.getWriter().write("Logged in");
    }
}

@WebServlet("/logout")
public class LogoutServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        if (session != null) {
            session.removeAttribute("username");
            response.getWriter().write("Logged out");
        }
    }
}