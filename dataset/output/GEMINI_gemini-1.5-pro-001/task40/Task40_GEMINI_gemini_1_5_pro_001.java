import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.security.web.csrf.CsrfToken;
import javax.servlet.http.HttpServletRequest;

@SpringBootApplication
@RestController
public class Task40_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        SpringApplication.run(Task40_GEMINI_gemini_1_5_pro_001.class, args);
    }

    @GetMapping("/settings")
    public String getSettingsForm(HttpServletRequest request) {
        CsrfToken csrfToken = (CsrfToken) request.getAttribute("_csrf");
        return "<html><body>" +
                "<form method='post'>" +
                "<input type='hidden' name='_csrf' value='" + csrfToken.getToken() + "' />" +
                "<label for='username'>Username:</label>" +
                "<input type='text' id='username' name='username' />" +
                "<button type='submit'>Update Settings</button>" +
                "</form>" +
                "</body></html>";
    }

    @PostMapping("/settings")
    public String updateSettings(@RequestParam String username) {
        // Process user settings update here
        return "Settings updated successfully!";
    }
}