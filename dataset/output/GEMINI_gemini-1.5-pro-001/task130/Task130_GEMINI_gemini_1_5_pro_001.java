import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.CrossOrigin;

@SpringBootApplication
@RestController
public class Task130_GEMINI_gemini_1_5_pro_001 {

    public static void main(String[] args) {
        SpringApplication.run(Task130_GEMINI_gemini_1_5_pro_001.class, args);
    }

    @CrossOrigin(origins = "*")
    @GetMapping("/api/data")
    public Data getData() {
        return new Data("John Doe", 30);
    }

    class Data {
        private String name;
        private int age;

        public Data(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public String getName() {
            return name;
        }

        public int getAge() {
            return age;
        }
    }
}