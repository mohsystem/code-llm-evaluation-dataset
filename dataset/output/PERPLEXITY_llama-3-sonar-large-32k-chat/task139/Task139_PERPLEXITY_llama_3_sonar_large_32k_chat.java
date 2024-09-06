import java.util.Scanner;
public class Task139_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = scanner.nextDouble();
        double area = Math.PI * (radius * radius);
        System.out.println("The area of the circle is: " + area);
    }
}