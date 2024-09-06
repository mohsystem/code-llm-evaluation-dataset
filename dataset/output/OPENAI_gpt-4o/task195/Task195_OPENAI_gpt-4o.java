import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class MedianFinder {
    private List<Integer> nums;

    public MedianFinder() {
        nums = new ArrayList<>();
    }

    public void addNum(int num) {
        int pos = Collections.binarySearch(nums, num);
        if (pos < 0) pos = -pos - 1;
        nums.add(pos, num);
    }

    public double findMedian() {
        int n = nums.size();
        if (n % 2 == 1) {
            return nums.get(n / 2);
        } else {
            return (nums.get(n / 2 - 1) + nums.get(n / 2)) / 2.0;
        }
    }

    public static void main(String[] args) {
        MedianFinder medianFinder = new MedianFinder();
        medianFinder.addNum(1);
        medianFinder.addNum(2);
        System.out.println(medianFinder.findMedian()); // 1.5
        medianFinder.addNum(3);
        System.out.println(medianFinder.findMedian()); // 2.0
    }
}