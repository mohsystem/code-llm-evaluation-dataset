import java.util.*;
public class Task169_OPENAI_gpt_4o {
    public static List<Integer> countSmaller(int[] nums) {
        Integer[] result = new Integer[nums.length];
        List<Integer> sortedList = new ArrayList<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            int index = Collections.binarySearch(sortedList, nums[i]);
            if (index < 0) index = -index - 1;
            result[i] = index;
            sortedList.add(index, nums[i]);
        }
        return Arrays.asList(result);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        int[] nums = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
        List<Integer> result = countSmaller(nums);
        for (int count : result) {
            System.out.print(count + " ");
        }
    }
}