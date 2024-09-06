
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

@SpringBootApplication
@Controller
public class Task40_CLAUDE_claude_3_5_sonnet_20240620 {

    public static void main(String[] args) {
        SpringApplication.run(Task40_CLAUDE_claude_3_5_sonnet_20240620.class, args);
    }

    @GetMapping("/")
    public String settingsForm(Model model) {
        model.addAttribute("settings", new Settings());
        return "settings";
    }

    @PostMapping("/")
    public String settingsSubmit(@ModelAttribute Settings settings) {
        // Process the settings update (not implemented here)
        return "result";
    }
}

class Settings {
    private String username;
    private String email;

    // Getters and setters
    public String getUsername() { return username; }
    public void setUsername(String username) { this.username = username; }
    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }
}

// Note: You'll need to create 'settings.html' and 'result.html' in src/main/resources/templates/
// settings.html should include a form with CSRF token:
// <form action="#" th:action="@{/}" th:object="${settings}" method="post">
//     <input type="hidden" th:name="${_csrf.parameterName}" th:value="${_csrf.token}" />
//     <p>Username: <input type="text" th:field="*{username}" /></p>
//     <p>Email: <input type="text" th:field="*{email}" /></p>
//     <p><input type="submit" value="Submit" /></p>
// </form>
