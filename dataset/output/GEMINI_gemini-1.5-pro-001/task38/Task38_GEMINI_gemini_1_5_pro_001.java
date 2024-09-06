import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@SpringBootApplication
@Controller
public class Task38_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        SpringApplication.run(Task38_GEMINI_gemini_1_5_pro_001.class, args);
    }

    @GetMapping("/")
    public String index() {
        return "index";
    }

    @PostMapping("/submit")
    public String submitInput(@RequestParam String userInput, Model model) {
        model.addAttribute("userInput", userInput);
        return "index";
    }
}