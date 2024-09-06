// Java (using Spring Boot)
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class Task120_MISTRAL_codestral_latest {

    @GetMapping("/")
    public String getInput() {
        return "input";
    }

    @PostMapping("/")
    public String showInput(@RequestParam("user_input") String userInput, Model model) {
        model.addAttribute("user_input", userInput);
        return "output";
    }
}