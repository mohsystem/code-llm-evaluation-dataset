// Java code using Spring Boot

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import javax.validation.Valid;


@SpringBootApplication
public class Application {
    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }
}

@Controller
@RequestMapping("/settings")
public class SettingsController {

    @GetMapping
    public String showSettingsForm(Model model) {
        model.addAttribute("userSettings", new UserSettings());
        return "settings";
    }

    @PostMapping("/update")
    public String updateUserSettings(@ModelAttribute @Valid UserSettings userSettings, Model model) {
        model.addAttribute("userSettings", userSettings);
        return "result";
    }
}

import javax.validation.constraints.NotNull;

public class UserSettings {
    @NotNull
    private String setting1;

    @NotNull
    private String setting2;

    public String getSetting1() {
        return setting1;
    }

    public void setSetting1(String setting1) {
        this.setting1 = setting1;
    }

    public String getSetting2() {
        return setting2;
    }

    public void setSetting2(String setting2) {
        this.setting2 = setting2;
    }
}