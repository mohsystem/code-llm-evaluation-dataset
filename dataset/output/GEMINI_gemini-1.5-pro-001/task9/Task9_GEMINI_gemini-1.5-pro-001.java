import java.util.List;
class Solution {
    public static String oddOrEven(List<Integer> arr) {
        int sum = 0;
        for (int i : arr) {
            sum += i;
        }
        return (sum % 2 == 0) ? "even" : "odd";
    }
}