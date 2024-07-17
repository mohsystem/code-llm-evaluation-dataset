import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.security.web.csrf.CookieCsrfTokenRepository;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@RestController
public class Application {

    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }

    @GetMapping("/")
    public String index() {
        return "<html><body>
" +
                "<form method=\"POST\" action=\"/\">
" +
                "  <input type=\"hidden\" name=\"_csrf\" value=\"{{csrfToken}}\" />
" +
                "  <button type=\"submit\">Submit</button>
" +
                "</form>
" +
                "</body></html>";
    }

    @PostMapping("/")
    public String submitForm() {
        return "Form submitted successfully!";
    }

    // Enable CSRF protection
    CookieCsrfTokenRepository repository = CookieCsrfTokenRepository.withHttpOnlyFalse();
}