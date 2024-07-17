
import java.util.Arrays;

public class OutlierFinder {
    public static int findOutlier(int[] integers) {
        int[] odds = Arrays.stream(integers).filter(i -> i % 2 != 0).toArray();
        int[] evens = Arrays.stream(integers).filter(i -> i % 2 == 0).toArray();
        
        return odds.length == 1 ? odds[0] : evens[0];
    }

    public static void main(String[] args) {
        System.out.println(findOutlier(new int[]{2, 4, 0, 100, 4, 11, 2602, 36}));
        System.out.println(findOutlier(new int[]{160, 3, 1719, 19, 11, 13, -21}));
    }
}
