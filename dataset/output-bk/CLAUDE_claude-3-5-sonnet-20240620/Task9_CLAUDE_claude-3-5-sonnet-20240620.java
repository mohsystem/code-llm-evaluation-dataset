
import java.util.Scanner;

public class OddOrEven {
    public static String oddOrEven(int[] arr) {
        if (arr.length == 0) {
            return "even";
        }
        
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        
        return (sum % 2 == 0) ? "even" : "odd";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        
        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        System.out.println(oddOrEven(arr));
        scanner.close();
    }
}
