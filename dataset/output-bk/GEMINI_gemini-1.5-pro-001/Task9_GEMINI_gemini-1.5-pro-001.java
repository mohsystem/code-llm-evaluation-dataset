import java.util.List;

class Solution {
    public String oddOrEven(List<Integer> array) {
        int sum = 0;
        for (int i = 0; i < array.size(); i++) {
            sum += array.get(i);
        }
        if (sum % 2 == 0) {
            return "even";
        } else {
            return "odd";
        }
    }
}