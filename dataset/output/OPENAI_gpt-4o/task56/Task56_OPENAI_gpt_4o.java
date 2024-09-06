import java.security.SecureRandom;
import java.util.Base64;

public class Task56_OPENAI_gpt_4o {
    public static void main(String[] args) {
        // Python part is done
        try {
            Thread.sleep(5000); // Waiting for 5 seconds
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Java part
        SecureRandom random = new SecureRandom();
        byte[] tokenBytes = new byte[16];
        random.nextBytes(tokenBytes);
        String token = Base64.getEncoder().encodeToString(tokenBytes);
        System.out.println("Java Generated Token: " + token);
        
        // Calling C++ part
        try {
            ProcessBuilder pb = new ProcessBuilder("g++", "-o", "cppPart", "cppPart.cpp");
            Process p = pb.start();
            p.waitFor();
            pb = new ProcessBuilder("./cppPart");
            p = pb.start();
            p.waitFor();

            // Calling C part
            pb = new ProcessBuilder("gcc", "-o", "cPart", "cPart.c");
            p = pb.start();
            p.waitFor();
            pb = new ProcessBuilder("./cPart");
            p = pb.start();
            p.waitFor();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}