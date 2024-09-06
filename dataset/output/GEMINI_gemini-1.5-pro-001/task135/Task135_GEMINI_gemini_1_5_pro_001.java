import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;
import org.springframework.security.web.csrf.CookieCsrfTokenRepository;

@SpringBootApplication
public class Task135_GEMINI_gemini_1_5_pro_001 extends WebSecurityConfigurerAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .csrf()
                .csrfTokenRepository(CookieCsrfTokenRepository.withDefaults()) // Use cookie-based CSRF token
            .and()
            // ... other security configurations
            ;
    }

    public static void main(String[] args) {
        SpringApplication.run(Task135_GEMINI_gemini_1_5_pro_001.class, args);
    }
}