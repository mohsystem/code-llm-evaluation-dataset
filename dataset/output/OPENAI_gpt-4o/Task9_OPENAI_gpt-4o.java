import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(0, -1, -5); // Example input list
        System.out.println(oddOrEven(list));
    }
    
    public static String oddOrEven(List<Integer> list) {
        int sum = list.stream().mapToInt(Integer::intValue).sum();
        return sum % 2 == 0 ? "even" : "odd";
    }
}