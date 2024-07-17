
import java.io.IOException;
import java.security.SecureRandom;
import java.util.Base64;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

@WebServlet("/")
public class CSRFProtectionServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String csrfToken = generateCSRFToken();
        HttpSession session = request.getSession();
        session.setAttribute("csrf_token", csrfToken);
        
        response.setContentType("text/html");
        response.getWriter().println("<form method=\'post\'>");
        response.getWriter().println("<input type=\'hidden\' name=\'csrf_token\' value=\'" + csrfToken + "\'>");
        response.getWriter().println("<input type=\'submit\' value=\'Submit\'>");
        response.getWriter().println("</form>");
    }
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String sessionToken = (String) session.getAttribute("csrf_token");
        String requestToken = request.getParameter("csrf_token");
        
        if (sessionToken == null || !sessionToken.equals(requestToken)) {
            response.sendError(HttpServletResponse.SC_FORBIDDEN, "CSRF token mismatch");
            return;
        }
        
        response.getWriter().println("Form submitted successfully");
    }
    
    private String generateCSRFToken() {
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[24];
        random.nextBytes(bytes);
        return Base64.getEncoder().encodeToString(bytes);
    }
    
    public static void main(String[] args) {
        // This main method is just a placeholder. 
        // In a real scenario, you\'d deploy this servlet to a web container like Tomcat.
        System.out.println("CSRF Protection Servlet");
    }
}
