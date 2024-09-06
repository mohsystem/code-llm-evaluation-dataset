import java.util.Scanner;

public class Task126_OPENAI_gpt_4o {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter page to redirect to (home/about/contact):");
        String input = sc.nextLine();
        
        if (input.equals("home")) {
            System.out.println("Redirect to Home Page");
        } else if (input.equals("about")) {
            System.out.println("Redirect to About Page");
        } else if (input.equals("contact")) {
            System.out.println("Redirect to Contact Page");
        } else {
            System.out.println("Page not found");
        }
        sc.close();
    }
}