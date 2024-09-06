import java.io.*;
import java.util.Scanner;

public class Task89_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String password = "correctpassword";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("password.txt"))) {
            writer.write(password);
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your password: ");
        String userInput = input.nextLine();
        
        if (checkPassword(userInput)) {
            System.out.println("Password is correct");
        } else {
            System.out.println("Password is incorrect");
        }
        input.close();
    }

    public static boolean checkPassword(String inputPassword) {
        String storedPassword = "";
        try (BufferedReader br = new BufferedReader(new FileReader("password.txt"))) {
            storedPassword = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        if (storedPassword.length() != inputPassword.length()) {
            return false;
        }
        
        for (int i = 0; i < storedPassword.length(); i++) {
            if (storedPassword.charAt(i) != inputPassword.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}