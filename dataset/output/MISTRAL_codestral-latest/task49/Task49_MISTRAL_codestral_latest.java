// Java (using Spring Boot)
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.*;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import java.util.Collections;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@SpringBootApplication
public class Task49_MISTRAL_codestral_latest {

    public static void main(String[] args) {
        SpringApplication.run(Task49_MISTRAL_codestral_latest.class, args);
    }
}

@RestController
@RequestMapping("/user")
class UserController {

    private final Map<Long, User> users = new ConcurrentHashMap<>();

    @PostMapping
    public User addUser(@RequestBody User user) {
        users.put(user.getId(), user);
        return user;
    }
}

@Entity
class User {

    @Id
    @GeneratedValue
    private Long id;
    private String name;
    private String email;

    // getters and setters
}