// Java (using Spring Boot)
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class InputController {
    @GetMapping("/")
    public String home() {
        return "<form method='post'><input name='user_input'><input type='submit' value='Submit'></form>";
    }

    @PostMapping("/")
    @ResponseBody
    public String submit(@RequestParam("user_input") String userInput) {
        return userInput;
    }
}