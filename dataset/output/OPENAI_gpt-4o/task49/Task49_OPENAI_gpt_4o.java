import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.*;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.beans.factory.annotation.Autowired;

import javax.annotation.PostConstruct;
@SpringBootApplication
public class Task49_OPENAI_gpt_4o {

    public static void main(String[] args) {
        SpringApplication.run(Task49_OPENAI_gpt_4o.class, args);
    }
}

@RestController
@RequestMapping("/api")
class UserController {
    @Autowired
    private JdbcTemplate jdbcTemplate;

    @PostConstruct
    public void init() {
        jdbcTemplate.execute("CREATE TABLE IF NOT EXISTS users (id SERIAL, name VARCHAR(255), email VARCHAR(255))");
    }

    @PostMapping("/add_user")
    public String addUser(@RequestBody User user) {
        jdbcTemplate.update("INSERT INTO users (name, email) VALUES (?, ?)", user.getName(), user.getEmail());
        return "User added successfully!";
    }
}

class User {
    private String name;
    private String email;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}