import java.util.Properties;
import java.util.Random;
import javax.mail.*;
import javax.mail.internet.*;

public class Task54_GEMINI_gemini_1_5_pro_001 {

    public static String generateOTP(int length) {
        String digits = "0123456789";
        StringBuilder otp = new StringBuilder();
        Random random = new Random();
        for (int i = 0; i < length; i++) {
            otp.append(digits.charAt(random.nextInt(digits.length())));
        }
        return otp.toString();
    }

    public static void sendOTPEmail(String otp, String recipientEmail) {
        final String senderEmail = "your_email@example.com"; // Replace with your email
        final String senderPassword = "your_password";     // Replace with your email password

        Properties props = new Properties();
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "587");

        Session session = Session.getInstance(props, new javax.mail.Authenticator() {
            protected PasswordAuthentication getPasswordAuthentication() {
                return new PasswordAuthentication(senderEmail, senderPassword);
            }
        });

        try {
            Message message = new MimeMessage(session);
            message.setFrom(new InternetAddress(senderEmail));
            message.setRecipient(Message.RecipientType.TO, new InternetAddress(recipientEmail));
            message.setSubject("Your Two-Factor Authentication Code");
            message.setText("Your OTP is: " + otp);
            Transport.send(message);
        } catch (MessagingException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        // Simulate user input (replace with your actual input method)
        String username = "user"; 
        String password = "password";

        // Simulate user authentication (replace with your actual authentication logic)
        if (username.equals("user") && password.equals("password")) {
            String otp = generateOTP(6);
            sendOTPEmail(otp, "recipient@example.com"); // Replace with user's email
            
            // Simulate OTP input (replace with your actual input method)
            String enteredOTP = "123456"; // Replace with user-entered OTP
            
            if (enteredOTP.equals(otp)) {
                System.out.println("Two-factor authentication successful. Logged in!");
            } else {
                System.out.println("Incorrect OTP. Access denied.");
            }
        } else {
            System.out.println("Invalid username or password.");
        }
    }
}