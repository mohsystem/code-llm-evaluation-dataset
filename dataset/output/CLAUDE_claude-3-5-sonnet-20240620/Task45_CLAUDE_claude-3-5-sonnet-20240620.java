
import java.util.Scanner;

public class ErrorHandlingDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        try {
            System.out.print("Enter a number: ");
            int num = Integer.parseInt(scanner.nextLine());
            
            System.out.print("Enter another number: ");
            int divisor = Integer.parseInt(scanner.nextLine());
            
            int result = divide(num, divisor);
            System.out.println("Result of division: " + result);
            
            int[] array = new int[5];
            System.out.print("Enter an index to access the array: ");
            int index = Integer.parseInt(scanner.nextLine());
            
            int value = array[index];
            System.out.println("Value at index " + index + ": " + value);
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid input. Please enter a valid integer.");
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array index out of bounds.");
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
    
    public static int divide(int a, int b) {
        return a / b;
    }
}
