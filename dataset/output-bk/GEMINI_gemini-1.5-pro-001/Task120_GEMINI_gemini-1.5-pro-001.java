import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class DisplayInput extends HttpServlet {

  @Override
  protected void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    String userInput = request.getParameter("userInput");

    out.println("<html>");
    out.println("<head><title>User Input</title></head>");
    out.println("<body>");
    out.println("<h1>You entered: " + userInput + "</h1>");
    out.println("</body>");
    out.println("</html>");
  }
}