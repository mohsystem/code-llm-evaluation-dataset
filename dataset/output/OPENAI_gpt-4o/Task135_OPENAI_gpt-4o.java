import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.*;
import java.io.IOException;
import java.security.SecureRandom;
import java.util.Base64;

@WebServlet("/form")
public class CSRFServlet extends HttpServlet {
    private static final String SECRET_KEY = "SuperSecretKey";
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String sessionToken = (String) request.getSession().getAttribute("csrf_token");
        String requestToken = request.getParameter("csrf_token");
        if (sessionToken == null || !sessionToken.equals(requestToken)) {
            response.sendError(HttpServletResponse.SC_FORBIDDEN);
            return;
        }
        response.getWriter().write("Form submitted successfully!");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String csrfToken = generateCsrfToken();
        request.getSession().setAttribute("csrf_token", csrfToken);
        response.getWriter().write("<form method='post'><input type='hidden' name='csrf_token' value='" + csrfToken + "'><input type='submit' value='Submit'></form>");
    }

    private String generateCsrfToken() {
        try {
            SecureRandom secureRandom = new SecureRandom();
            byte[] randomBytes = new byte[32];
            secureRandom.nextBytes(randomBytes);

            Mac mac = Mac.getInstance("HmacSHA256");
            SecretKeySpec secretKeySpec = new SecretKeySpec(SECRET_KEY.getBytes(), "HmacSHA256");
            mac.init(secretKeySpec);
            byte[] tokenBytes = mac.doFinal(randomBytes);
            return Base64.getEncoder().encodeToString(tokenBytes);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}

@WebFilter("/*")
public class CsrfFilter implements Filter {
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) request;
        if ("POST".equalsIgnoreCase(req.getMethod())) {
            String sessionToken = (String) req.getSession().getAttribute("csrf_token");
            String requestToken = req.getParameter("csrf_token");
            if (sessionToken == null || !sessionToken.equals(requestToken)) {
                ((HttpServletResponse) response).sendError(HttpServletResponse.SC_FORBIDDEN);
                return;
            }
        }
        chain.doFilter(request, response);
    }

    public void init(FilterConfig filterConfig) throws ServletException {}

    public void destroy() {}
}