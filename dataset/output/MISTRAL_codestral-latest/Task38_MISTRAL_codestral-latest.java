// Java code using Spring Boot framework
// Controller
@Controller
public class InputController {

    @GetMapping("/")
    public String home() {
        return "index";
    }

    @PostMapping("/submit")
    public String submit(@RequestParam("user_input") String userInput, Model model) {
        model.addAttribute("user_input", userInput);
        return "result";
    }
}